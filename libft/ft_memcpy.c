/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:11:09 by larosale          #+#    #+#             */
/*   Updated: 2020/05/09 01:14:27 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies "n" bytes from memory area "src" to memory area "dst". If they
** overlap, the behavior is undefined.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_char;
	const char	*src_char;

	src_char = src;
	dst_char = dst;
	if (n && dst != src)
		while (n--)
			*dst_char++ = *src_char++;
	return (dst);
}
