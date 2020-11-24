/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 01:23:03 by larosale          #+#    #+#             */
/*   Updated: 2020/07/05 01:57:26 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Handles rounding up.
*/

static void	round_up(char *input, int shift, int *exponent)
{
	char	*temp;

	temp = input - shift;
	*input-- = '\0';
	while (input >= temp)
	{
		*input += 1;
		if (input != temp && *input == ':' && (*input-- = '0'))
			continue ;
		else if (input == temp && *input == ':' && (*input = '1'))
		{
			*exponent += 1;
			break ;
		}
		else
			break ;
	}
	return ;
}

/*
** Handles rounding on '5' digit.
** For correct rounding, five-zeroes and four-nines up to 15th digit
** are rounded as 5.
*/

static void	round_five(char *input, int shift, int *exponent)
{
	char	*temp;
	int		step;

	temp = input - shift;
	step = shift + 1;
	while (*(temp + step) && step < 15)
	{
		if (*(temp + step) != '0')
			return (round_up(input, shift, exponent));
		step++;
	}
	if ((*(temp + step) == '\0' || step == 15) && (*(input - 1) - '0') % 2)
		return (round_up(input, shift, exponent));
	else if ((*(temp + step) == '\0' || step == 15) &&
		!((*(input - 1) - '0') % 2))
		*input = '\0';
	return ;
}

/*
** Handles special rounding case (4 with 9's to the precision limit).
*/

static void	round_special(char *input, int shift, int *exponent)
{
	int step;

	step = 1;
	if (*input == '4')
	{
		while (*(input + step) == '9' && (step + shift) < 15)
			step++;
		if (step + shift == 15)
		{
			round_up(input + 1, shift + 1, exponent);
			return (round_five(input, shift, exponent));
		}
	}
	if (shift > 14 && *(input - 1) == '9')
		return (round_up(input, shift, exponent));
	*input = '\0';
	return ;
}

/*
** Rounds the "input" string of decimal digits, representing a normalized
** floating point mantissa to the given "precision" (number of digits after
** dot).
** The "input" string could be generated by "ft_convert_double" function.
** Rounding is performed in-place.
*/

void		ft_round_double(char *input, unsigned int precision, int *exponent)
{
	char	*temp;

	if (precision > 15)
		precision = 15;
	if (!input || ft_strlen(input) <= precision + 1)
		return ;
	temp = input;
	temp += precision + 1;
	if (*temp < '5')
	{
		if (*temp == '4' || (precision > 13 && *(temp - 1) == '9'))
			return (round_special(temp, precision + 1, exponent));
		*temp = '\0';
		return ;
	}
	else if (*temp > '5')
		return (round_up(temp, precision + 1, exponent));
	else
		return (round_five(temp, precision + 1, exponent));
	return ;
}
