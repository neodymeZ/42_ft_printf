/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:01:46 by larosale          #+#    #+#             */
/*   Updated: 2020/06/21 02:22:25 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates memory and returns a substring of string "s". The substring
** begins at "start" and is of maximum length "len".
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	if (start < ft_strlen(s) && len > 0)
	{
		len > ft_strlen(s) - start ? len = ft_strlen(s) - start : 0;
		if (!(substr = malloc(len + 1)))
			return (NULL);
		s += start;
		s_len = -1;
		while (*s && ++s_len < len)
			*(substr + s_len) = *(s + s_len);
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
