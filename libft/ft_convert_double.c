/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:04:56 by larosale          #+#    #+#             */
/*   Updated: 2020/07/05 00:08:16 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_DIGITS 256

/*
** Converts the "input" (non-negative double) to a string of digits,
** containing whole and fraction parts, and returns the string.
** The exponent is written to "*exponent".
** A simple arithmetical algorithm is used - it can lead to inaccurate
** rounding sometimes. For correct rounding, Dragon4 algorithm, which
** uses integer math, shall be implemented.
*/

char		*ft_convert_double(double input, int *exponent)
{
	double		value;
	double		digit;
	int			num_digits;
	char		buffer[MAX_DIGITS];

	if (input == 0.0)
	{
		*exponent = 0;
		return (ft_strdup("0"));
	}
	num_digits = 0;
	value = input;
	*exponent = (int)ft_math_floor(ft_math_log10(value));
	value /= ft_math_pow(10, *exponent);
	while (value > 0.0 && num_digits < MAX_DIGITS)
	{
		digit = ft_math_floor(value);
		buffer[num_digits] = (char)digit + '0';
		num_digits++;
		value -= digit;
		value *= 10.0;
	}
	buffer[num_digits] = '\0';
	return (ft_strdup(buffer));
}
