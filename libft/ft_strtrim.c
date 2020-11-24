/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:51:49 by larosale          #+#    #+#             */
/*   Updated: 2020/05/16 20:29:06 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Returns 1 if "symbol" is in "set" or 0 otherwise.
*/

static int			in_set(char symbol, char const *set)
{
	while (*set)
	{
		if (*set == symbol)
			return (1);
		set++;
	}
	return (0);
}

/*
** Returns index of a first symbol in "s1" which is not in set,
** or "s1" length if all symbols in "s1" are in "set".
*/

static size_t		find_start(char const *s1, char const *set)
{
	size_t index;

	index = 0;
	while (*(s1 + index) && in_set(*(s1 + index), set))
		index++;
	return (index);
}

/*
** Returns index of a last symbol in "s1" which is not in "set",
** or "s1" length if all symbols in "s1" are in "set".
*/

static size_t		find_end(char const *s1, char const *set)
{
	size_t index;

	index = ft_strlen(s1) - 1;
	while (in_set(*(s1 + index), set))
	{
		if (index == 0)
			return (ft_strlen(s1));
		index--;
	}
	return (index);
}

/*
** Trims the string "s1" from the characters in "set".
** Finds positions of characters not to be trimmed from the beginning and
** the end of "s1", then calculates the trimmed string length, copies "s1"
** symbols within these borders to "trimstr" and returns "trimstr".
*/

char				*ft_strtrim(char const *s1, char const *set)
{
	char		*trimstr;
	size_t		trimstart;
	size_t		trimend;
	size_t		trimlen;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trimstart = find_start(s1, set);
	trimend = find_end(s1, set);
	trimlen = trimend - trimstart + 1;
	if (!(trimstr = malloc(trimlen + 1)))
		return (NULL);
	if (trimlen > 1)
	{
		while (trimstart <= trimend)
		{
			*trimstr = *(s1 + trimstart);
			trimstart++;
			trimstr++;
		}
		trimlen++;
	}
	*trimstr = '\0';
	return (trimstr - (trimlen - 1));
}
