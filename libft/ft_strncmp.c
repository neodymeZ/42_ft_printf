/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:13:40 by larosale          #+#    #+#             */
/*   Updated: 2020/05/11 14:35:11 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compare two strings "s1" and "s2" within "n" characters.
** Returns 0 if strings are the same, or difference if not.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	step;

	step = 0;
	while (*(s1 + step) && *(s2 + step) && step < n)
	{
		if (*(s1 + step) == *(s2 + step))
		{
			step++;
			continue ;
		}
		else
		{
			return ((int)(*(unsigned char *)(s1 + step) -
				*(unsigned char *)(s2 + step)));
		}
	}
	if (n && (*(s1 + step) == '\0' || *(s2 + step) == '\0'))
	{
		return ((int)(*(unsigned char *)(s1 + step) -
			*(unsigned char *)(s2 + step)));
	}
	return (0);
}
