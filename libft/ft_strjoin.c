/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 23:03:45 by larosale          #+#    #+#             */
/*   Updated: 2020/05/05 16:52:13 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates memory and returns a new string, which is the result of
** concatenation of the strings "s1" and "s2".
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	strlen;

	if (s1 == NULL || s2 == NULL
		|| !(strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	while ((*strjoin = *s1))
	{
		strjoin++;
		s1++;
	}
	while ((*strjoin = *s2))
	{
		strjoin++;
		s2++;
	}
	return (strjoin - strlen);
}
