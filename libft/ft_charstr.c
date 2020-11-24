/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 19:03:48 by larosale          #+#    #+#             */
/*   Updated: 2020/06/18 12:08:51 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_charstr(int number, unsigned char c)
{
	char	*result;
	int		i;

	i = 0;
	if (number < 0 || !(result = malloc(number + 1)))
		return (NULL);
	while (i < number)
	{
		*(result + i) = c;
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
