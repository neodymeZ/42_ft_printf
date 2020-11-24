/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:36:41 by larosale          #+#    #+#             */
/*   Updated: 2020/07/01 12:24:25 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#define DIGITS "0123456789abcdef"

/*
** Reverses the itoa resulting string.
*/

static void		reverse_str(char *s)
{
	size_t		start;
	size_t		end;
	char		temp;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		temp = *(s + start);
		*(s + start) = *(s + end);
		*(s + end) = temp;
		start++;
		end--;
	}
}

/*
** Calculates the length of itoa input number for memory allocation.
*/

static size_t	n_length(uintmax_t n, int sign, unsigned int base, int flag)
{
	size_t		length;

	length = 0;
	if (sign == SIGN_MINUS || n == 0)
		length++;
	while (n > 0)
	{
		n /= base;
		length++;
	}
	if (flag && (base == 16 || base == 2))
		length += 2;
	if (flag && base == 8)
		length += 1;
	return (length);
}

/*
** Converts the input unsigned integer "n" (if signed, the caller should set
** "sign" to SIGN_MINUS(-1)) to the string, representing "n" in the "base"
** base (2 to 16).
** The string is build in reversed order, then reversed.
** If "flag" is set to PREFIX_ON(1), the function prepends output with 0b,
** 0 and 0x for bases 2, 8 and 16 respectively. Otherwise the flag should be
** set to PREFIX_OFF(0).
** Allocates ("n" length + 1) bytes.
*/

char			*ft_itoa_base(uintmax_t n, int sign, unsigned int base,
	int flag)
{
	char		*result;
	int			step;

	if (!(result = malloc(n_length(n, sign, base, flag) + 1)) ||
		base > 16 || base < 2)
		return (NULL);
	step = 0;
	n == 0 ? *(result + step++) = '0' : 0;
	while (n > 0)
	{
		*(result + step) = DIGITS[n % base];
		n /= base;
		step++;
	}
	sign == SIGN_MINUS ? *(result + step++) = '-' : 0;
	flag && base == 16 ? *(result + step++) = 'x' : 0;
	flag && base == 2 ? *(result + step++) = 'b' : 0;
	flag && (base == 8 || base == 2 || base == 16) ?
		*(result + step++) = '0' : 0;
	*(result + step) = '\0';
	reverse_str(result);
	return (result);
}
