/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 00:20:11 by larosale          #+#    #+#             */
/*   Updated: 2020/05/10 20:09:56 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks, whether the string "haystack" at the current position "step"
** (limited by "len") is equal to the string "needle". If yes, returns
** the starting position of "needle" in "haystack", or NULL otherwise.
*/

static char	*check_substring(const char *haystack, const char *needle,
	size_t step, size_t len)
{
	char	*string;

	string = (char *)haystack;
	while (*needle && *haystack && step++ < len)
	{
		if (*needle++ == *haystack++)
			continue ;
		else
			return (NULL);
	}
	if (*needle == '\0')
		return (string);
	return (NULL);
}

/*
** Finds a "needle" string in the "haystack" string within "len" characters.
*/

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	step;
	char	*found;

	if (*needle == '\0')
		return ((char *)haystack);
	step = 0;
	while (step < len && *haystack)
	{
		if (*haystack == *needle)
		{
			if ((found = check_substring(haystack, needle, step, len)))
				return (found);
		}
		haystack++;
		step++;
	}
	return (NULL);
}
