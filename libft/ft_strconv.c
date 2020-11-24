/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:54:00 by larosale          #+#    #+#             */
/*   Updated: 2020/06/15 19:27:15 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Performs an in-place conversion of the string "str" using function "f".
*/

char		*ft_strconv(char *str, int (*f)(int))
{
	char	*temp;

	if (!str || !f)
		return (NULL);
	temp = str;
	while (*str)
	{
		*str = f(*str);
		str++;
	}
	return (temp);
}
