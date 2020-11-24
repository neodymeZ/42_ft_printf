/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 00:51:34 by larosale          #+#    #+#             */
/*   Updated: 2020/05/08 13:59:26 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if "dst" is further in memory than "src" and chooses copy direction,
** then copies "len" bytes of "src" to "dst" in this direction.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_char;
	const char	*src_char;

	src_char = src;
	dst_char = dst;
	if (len && dst != src)
	{
		if ((size_t)dst > (size_t)src)
			while (len--)
				*(dst_char + len) = *(src_char + len);
		else if ((size_t)dst < (size_t)src)
			while (len--)
				*dst_char++ = *src_char++;
	}
	return (dst);
}
