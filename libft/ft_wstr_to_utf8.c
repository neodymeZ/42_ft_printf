/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:55:50 by larosale          #+#    #+#             */
/*   Updated: 2020/06/19 19:20:27 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "libft.h"

/*
** Counts the number of bytes needed to store the string after encoding "str",
** allocates memory and returns the resulting empty string.
** Returns NULL if allocation fails, or if a wchar in "str" cannot be encoded.
** Memory allocation: bytes needed for encoding + 1.
*/

static char	*generate_string(wchar_t *str)
{
	int		bytes_count;
	int		bytes_count_s;
	char	*result;

	bytes_count = 0;
	while (*str)
	{
		bytes_count_s = bytes_count;
		*str >= 0 && *str <= 0x7F ? bytes_count += 1 : 0;
		*str >= 0x80 && *str <= 0x7FF ? bytes_count += 2 : 0;
		*str >= 0x800 && *str <= 0xFFFF ? bytes_count += 3 : 0;
		*str >= 0x10000 && *str <= 0x10FFFF ? bytes_count += 4 : 0;
		if (bytes_count == bytes_count_s)
			return (NULL);
		str++;
	}
	if (!(result = malloc(bytes_count + 1)))
		return (NULL);
	return (result);
}

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
}

/*
** Converts wide string "str" with Unicode code points to a multi-byte
** string encoded in UTF-8 and returns it.
** Returns NULL if "str" is NULL, allocation failed or if "str" contains
** at least one wchar which is not a Unicode code point.
*/

char		*ft_wstr_to_utf8(wchar_t *str)
{
	int		bytes_count;
	char	*result;
	char	*temp;

	if (!str || !(result = generate_string(str)))
		return (NULL);
	temp = result;
	while (*str)
	{
		bytes_count = 0;
		*str >= 0 && *str <= 0x7F ? bytes_count = 1 : 0;
		*str >= 0x80 && *str <= 0x7FF ? bytes_count = 2 : 0;
		*str >= 0x800 && *str <= 0xFFFF ? bytes_count = 3 : 0;
		*str >= 0x10000 && *str <= 0x10FFFF ? bytes_count = 4 : 0;
		convert_char(*str, temp, bytes_count);
		temp += bytes_count;
		str++;
	}
	*temp = '\0';
	return (result);
}
