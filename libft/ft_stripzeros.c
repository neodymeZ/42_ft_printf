/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stripzeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 00:01:58 by larosale          #+#    #+#             */
/*   Updated: 2020/07/04 18:37:15 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Strips trailing zeros from the input string, which contains a string
** representation of a double number, in exponential or fixed-point notation.
*/

void	ft_stripzeros(char *input)
{
	char	exp[10];
	char	*temp;
	size_t	len;

	exp[0] = '\0';
	len = ft_strlen(input);
	if (!input || !(temp = ft_strchr(input, '.')))
		return ;
	if ((temp = ft_strchr(input, 'e')))
		ft_strlcpy(exp, temp, 10);
	else
		temp = input + len;
	temp--;
	while (temp > input && *temp == '0')
		temp--;
	if (*temp == '.')
		*temp = '\0';
	else
		*(temp + 1) = '\0';
	if (exp[0])
		ft_strlcat(input, exp, len + 1);
	return ;
}
