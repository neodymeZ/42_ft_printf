/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_ipow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:59:26 by larosale          #+#    #+#             */
/*   Updated: 2020/06/26 02:53:47 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#define SQRT_LLONG_MAX 0xB504F333

/*
** Performs exponentiation of the integer number "x" to the power "pow".
** Uses recursive algorithm of exponentiation by squaring.
** Before calculation, the function checks for integer overflow.
** If overflow is detected, the function returns 0.
*/

long long	ft_math_ipow(int x, unsigned int pow)
{
	long long	temp;

	if (!pow || x == 1)
		return (1);
	if (!x)
		return (0);
	temp = ft_math_ipow(x, pow / 2);
	printf("Temp is: %lld\n", temp);
	printf("Pow is: %u\n", pow);
	if (temp && !(pow % 2) && (temp > 0 ? temp : -temp) < SQRT_LLONG_MAX)
		return (temp * temp);
	else if (temp && (pow % 2) && (x > 0 ? x : -x) < LLONG_MAX / (temp * temp))
		return (x * temp * temp);
	else
		return (0);
}
