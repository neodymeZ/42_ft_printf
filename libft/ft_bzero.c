/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:47:52 by larosale          #+#    #+#             */
/*   Updated: 2020/05/06 19:08:59 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes "n" zeroed bytes to the string "s". Does nothing if n == 0.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *temp;

	if (n != 0)
	{
		temp = s;
		while (n--)
			*temp++ = '\0';
	}
}
