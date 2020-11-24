/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:44:57 by larosale          #+#    #+#             */
/*   Updated: 2020/05/08 11:21:32 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares byte strings "s1" and "s2", both are assumed to be "n" bytes long.
** Returns 0 if strings are identical, or difference otherwise.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*firststr;
	const unsigned char	*secondstr;

	firststr = s1;
	secondstr = s2;
	if (n)
	{
		while (n--)
			if (*firststr++ != *secondstr++)
				return (*--firststr - *--secondstr);
	}
	return (0);
}
