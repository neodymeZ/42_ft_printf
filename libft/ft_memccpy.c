/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:30:25 by larosale          #+#    #+#             */
/*   Updated: 2020/05/08 13:56:58 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies byte string "src" to "dst" until char "c" is found in src. If found,
** pointer to the next char is returned. Otherwise, "n" chars are copied and
** NULL is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst_char;
	unsigned char const		*src_char;
	unsigned char			stop_char;

	dst_char = dst;
	src_char = src;
	stop_char = c;
	if (n)
	{
		while (n--)
			if ((*dst_char++ = *src_char++) == stop_char)
				return (dst_char);
	}
	return (NULL);
}
