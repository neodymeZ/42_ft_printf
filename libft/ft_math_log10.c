/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_log10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:57 by larosale          #+#    #+#             */
/*   Updated: 2020/06/26 17:52:04 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LN10 2.3025850929940456840179914546844
#define LG2 0.301029995663981198017467022510

static double	return_nan(void)
{
	return (0.0 / 0.0);
}

/*
** Calculates the log10 of "x" using the area hyperbolic tangent function
** (2 x artanh(z - 1 / z + 1)) approximation.
** The cycle continues until the sum of terms "sum" stops changing in double
** precision.
*/

static double	calculate_log10(double x)
{
	double	sum;
	double	ratio;
	double	denominator;
	double	numerator;
	double	prev_sum;

	prev_sum = 0.0;
	denominator = 1.0;
	ratio = (x - 1) / (x + 1);
	numerator = ratio;
	sum = numerator / denominator;
	while (sum != prev_sum)
	{
		prev_sum = sum;
		denominator += 2.0;
		numerator = numerator * ratio * ratio;
		sum += numerator / denominator;
	}
	return (2.0 * sum / LN10);
}

/*
** Calculates log10 of "x".
** Checks for negative "x" and large exponents.
*/

double			ft_math_log10(double x)
{
	int		exponent;
	double	mantissa;

	if (x <= 0.0)
		return (return_nan());
	mantissa = ft_math_frexp(x, &exponent);
	if ((exponent >= 0 ? exponent : -exponent) > 1)
		return (calculate_log10(mantissa) + exponent * LG2);
	else
		return (calculate_log10(x));
}
