/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:32:09 by larosale          #+#    #+#             */
/*   Updated: 2020/06/26 17:54:43 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Calculates the result of exponentiation of the floating number "x" to the
** integer power "pow".
** Returns the floating point result, 1 for power of 0 and 0 for base of 0.
** Uses recursive algorithm of exponentiation by squaring.
*/

double	ft_math_pow(double x, int pow)
{
	double	temp;

	if (!pow)
		return (1);
	if (!x)
		return (0);
	temp = ft_math_pow(x, pow / 2);
	if (!(pow % 2))
		return (temp * temp);
	else
	{
		if (pow > 0)
			return (x * temp * temp);
		else
			return (temp * temp) / x;
	}
}
