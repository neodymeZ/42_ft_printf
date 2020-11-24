/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 01:29:44 by larosale          #+#    #+#             */
/*   Updated: 2020/05/06 10:43:16 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Reverses the itoa resulting string.
*/

static void	reverse_str(char *s)
{
	size_t	start;
	size_t	end;
	char	temp;

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

static int	n_length(int n)
{
	int length;

	length = 1;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

/*
** Allocates memory, converts the input number "n" to unsigned (for INT_MIN),
** builds reversed string and reverses it to obtain the resulting string.
*/

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	abs_n;
	int				step;

	if (!(result = malloc(n_length(n) + 1)))
		return (NULL);
	if (n < 0)
		abs_n = -n;
	else
		abs_n = n;
	step = 0;
	while (abs_n > 0)
	{
		*(result + step) = (abs_n % 10) + '0';
		abs_n /= 10;
		step++;
	}
	if (n < 0)
		*(result + step++) = '-';
	if (n == 0)
		*(result + step++) = '0';
	*(result + step) = '\0';
	reverse_str(result);
	return (result);
}
