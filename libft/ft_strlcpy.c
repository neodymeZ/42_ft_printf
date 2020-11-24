/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:30:18 by larosale          #+#    #+#             */
/*   Updated: 2020/05/08 23:47:21 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies "src" to "dst" until one of the strings end with \0 (up to
** "dstsize" - 1 characters from "src"). If index "copysize"
** goes to zero, there is not enough space in "dst", the function terminates
** "dst" with \0 and traverses the rest of src. Returns the length of "src"
** (the string it tried to copy to easily check if truncation occurs).
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		copysize;
	const char	*copysrc;

	copysize = dstsize;
	copysrc = src;
	if (copysize)
	{
		while (--copysize != 0)
		{
			*dst++ = *src++;
			if (*(dst - 1) == '\0')
				break ;
		}
	}
	if (!copysize)
	{
		if (dstsize)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - copysrc - 1);
}
