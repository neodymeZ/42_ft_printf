/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isposinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:58:12 by larosale          #+#    #+#             */
/*   Updated: 2020/06/30 13:22:40 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the "input" value (double) is positive inf.
** Returns 1 if it is, and 0 otherwise.
*/

int	ft_isposinf(double input)
{
	double	mantissa;
	int		exponent;

	mantissa = ft_math_frexp(input, &exponent);
	if (mantissa == 1.0 && exponent == 1024)
		return (1);
	else
		return (0);
}
