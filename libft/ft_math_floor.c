/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:12 by larosale          #+#    #+#             */
/*   Updated: 2020/06/25 20:02:19 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/*
** Calculates and returns the closest round number to the "value"
** which is less than "value".
** The function is SAFE - it checks, if the "value" is out of long long
** bounds, or is NaN.
** The "value" is limited to the long long, as a simple integer conversion
** algorithm is used.
*/

double	ft_math_floor(double value)
{
	long long	n;
	double		conv_value;

	if (value >= LLONG_MAX || value <= LLONG_MIN || value != value)
		return (value);
	n = (long long)value;
	conv_value = (double)n;
	if (conv_value == value || value >= 0)
		return (conv_value);
	else
		return (conv_value - 1);
}
