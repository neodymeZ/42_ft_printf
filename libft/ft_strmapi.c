/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:55:25 by larosale          #+#    #+#             */
/*   Updated: 2020/05/06 01:14:04 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Applies the function "f" to each character of the string "s" to create
** a new string, resulting from successive applications of "f".
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	step;

	if (!s || !f || !(map = malloc(ft_strlen(s) + 1)))
		return (NULL);
	step = 0;
	while (*(s + step))
	{
		*(map + step) = f(step, *(s + step));
		step++;
	}
	*(map + step) = '\0';
	return (map);
}
