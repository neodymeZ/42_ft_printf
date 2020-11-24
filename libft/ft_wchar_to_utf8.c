/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_utf8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 01:03:27 by larosale          #+#    #+#             */
/*   Updated: 2020/06/19 02:06:19 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "libft.h"

/*
** Performs UTF-8 encoding of wchar "c" to the string "result".
*/

static void	convert_char(wchar_t c, char *result, int bytes_count)
{
	if (bytes_count == 1)
		*result++ = c;
	if (bytes_count == 2)
	{
		*result++ = (0xC0 + (c >> 6));
		*result++ = (0x80 + (c & 0x3F));
	}
	if (bytes_count == 3)
	{
		*result++ = (0xE0 + (c >> 12));
		*result++ = (0x80 + ((c >> 6) & 0x3F));
		*result++ = (0x80 + (c & 0x3F));
	}
	if (bytes_count == 4)
	{
		*result++ = (0xF0 + (c >> 18));
		*result++ = (0x80 + ((c >> 12) & 0x3F));
		*result++ = (0x80 + ((c >> 6) & 0x3F));
		*result++ = (0x80 + (c & 0x3F));
	}
	*result = '\0';
}

/*
** Converts wide char "c" with a Unicode code point to a multi-byte character
** (string) encoded in UTF-8 and returns it.
** Returns NULL if wchar does not contain a Unicode code point.
** Allocates 2 to 5 bytes of memory.
*/

char		*ft_wchar_to_utf8(wchar_t c)
{
	int		bytes_count;
	char	*result;

	bytes_count = 0;
	c >= 0 && c <= 0x7F ? bytes_count = 1 : 0;
	c >= 0x80 && c <= 0x7FF ? bytes_count = 2 : 0;
	c >= 0x800 && c <= 0xFFFF ? bytes_count = 3 : 0;
	c >= 0x10000 && c <= 0x10FFFF ? bytes_count = 4 : 0;
	if (!bytes_count || !(result = malloc(bytes_count + 1)))
		return (NULL);
	convert_char(c, result, bytes_count);
	return (result);
}
