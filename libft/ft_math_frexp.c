/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_frexp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:24:24 by larosale          #+#    #+#             */
/*   Updated: 2020/06/29 18:53:14 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Separates mantissa and exponent parts of a double number "value".
** Returns mantissa and writes exponent to the location, pointed by "exp".
** The function returns NaN if "exp" is NULL.
*/

double	ft_math_frexp(double value, int *exp)
{
	double			mantissa;
	unsigned short	*exp_ptr;
	unsigned short	exponent;

	if (!exp)
		return (0.0 / 0.0);
	exp_ptr = (unsigned short *)&value + 3;
	exponent = *exp_ptr;
	exponent = (exponent & 0x7FF0) >> 4;
	*exp = (int)exponent - 1023;
	mantissa = value;
	exp_ptr = (unsigned short *)&mantissa + 3;
	*exp_ptr = (*exp_ptr & 0x800F) | 0x3FF0;
	return (mantissa);
}
