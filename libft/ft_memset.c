/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 13:19:15 by larosale          #+#    #+#             */
/*   Updated: 2020/05/07 20:41:50 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes "len" bytes of value "c" (converted to unsigned char) to string "b".
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ucb;

	i = 0;
	ucb = b;
	if (len != 0)
	{
		while (i < len)
		{
			*(ucb + i) = (unsigned char)c;
			i++;
		}
	}
	return (ucb);
}
