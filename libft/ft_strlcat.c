/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:46:49 by larosale          #+#    #+#             */
/*   Updated: 2020/05/13 17:37:59 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Traverses through "dst"; then if "dstsize" is less than (strlen(dst) + 1)
** returns the length of a string it tried to create. If dstsize is greater
** than the full "dst" length, the function copies "src" until reaching one
** position before buffer end and places "end of line" symbol. If "dstsize" is
** equal to the full "dst" length, then only "src" traverse happens. The
** function returns the length of a string it tried to create.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		copysize;
	size_t		dstlen;
	const char	*copydst;
	const char	*copysrc;

	copysize = dstsize;
	copydst = dst;
	copysrc = src;
	while (copysize-- && *dst)
		dst++;
	dstlen = dst - copydst;
	copysize = dstsize - dstlen;
	if (copysize-- == 0)
		return (dstlen + ft_strlen(src));
	while (*src)
	{
		if (copysize)
		{
			*dst++ = *src;
			copysize--;
		}
		src++;
	}
	*dst = '\0';
	return (dstlen + (src - copysrc));
}
