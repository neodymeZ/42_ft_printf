/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:39:35 by larosale          #+#    #+#             */
/*   Updated: 2020/06/30 19:11:41 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Inserts char "sym" to the string "input" on the "position" and returns
** the resulting string.
** Returns NULL on allocation error, or if "input" is NULL, returns "input"
** if "position" if larger than the "input" size.
** Memory allocation: "input" length + 2 bytes.
*/

char	*ft_strins(char *input, char sym, size_t position)
{
	size_t	size;
	char	*result;
	size_t	i;

	if (!input)
		return (NULL);
	size = ft_strlen(input);
	i = 0;
	if (position > size)
		return (input);
	if (!(result = malloc(size + 2)))
		return (NULL);
	while (i < position)
	{
		*(result + i) = *(input + i);
		i++;
	}
	*(result + i) = sym;
	while (i < size)
	{
		*(result + i + 1) = *(input + i);
		i++;
	}
	*(result + i + 1) = '\0';
	return (result);
}
