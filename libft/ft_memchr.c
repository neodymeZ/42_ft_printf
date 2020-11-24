/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:37:40 by larosale          #+#    #+#             */
/*   Updated: 2020/05/08 14:00:44 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a pointer to the first occurence of "c" in "s", or NULL (if no such
** byte exists within "n" bytes).
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*result;

	result = s;
	while (n--)
	{
		if (*result == (unsigned char)c)
			return ((void *)result);
		result++;
	}
	return (NULL);
}
