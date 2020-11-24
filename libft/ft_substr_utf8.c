/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 02:47:46 by larosale          #+#    #+#             */
/*   Updated: 2020/06/21 01:48:28 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Corrects "*start" and "*len" in a way to align them with UTF-8 encoding.
** "*start" is incremented and "*len" is decremented accordingly.
** Returns 1 on success and 0 on failure.
*/

static int	correct_len_start(const char *s, unsigned int *start, size_t *len)
{
	size_t			step;
	size_t			step_start;
	unsigned int	num_bytes;

	step = 0;
	s += *start;
	while (*(s + step) && step < *len && !ft_isutf8(s + step))
		step++;
	if (ft_isutf8(s + step))
	{
		step_start = step;
		*start += step;
	}
	else
		return (0);
	while (*(s + step) && step < *len && (num_bytes = ft_isutf8(s + step)))
		step += num_bytes;
	if (step > *len)
		step -= num_bytes;
	*len = step - step_start;
	return (1);
}

/*
** Allocates memory and returns a substring of UTF-8 encoded string "s".
** The substring begins at "start" and is of maximum length "len" bytes.
** The number of characters in the resulting string and start position
** are corrected to align with UTF-8 encoded multibyte chars.
** Memory allocation: maximum "len" bytes + 1 (adjusted if needed).
** Function is SAFE.
*/

char		*ft_substr_utf8(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	if (start < ft_strlen(s) && len > 0 && correct_len_start(s, &start, &len))
	{
		if (!(substr = malloc(len + 1)))
			return (NULL);
		s += start;
		s_len = 0;
		while (*s && s_len < len)
		{
			*(substr + s_len) = *(s + s_len);
			s_len++;
		}
		*(substr + s_len) = '\0';
	}
	else
	{
		if (!(substr = malloc(1)))
			return (NULL);
		*substr = '\0';
	}
	return (substr);
}
