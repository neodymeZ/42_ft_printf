/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:32:47 by larosale          #+#    #+#             */
/*   Updated: 2020/06/17 00:27:21 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Test for little or big endian:
** #include <stdio.h>
** #include <stdint.h>
**
** int main(void)
** {
**		uint16_t x = 1;
**		printf("%s\n", *((uint8_t *) &x) == 0 ? "big-endian" : "little-endian");
**		return 0;
** }
*/

/*
** Prints the value of bit field, pointed to by pointer "ptr", of size "size".
** Assumes little-endian, prints in big-endian.
*/

void				ft_memprint(size_t const size, void const *const ptr)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;

	b = (unsigned char *)ptr;
	i = size - 1;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar_fd(byte ? '1' : '0', 1);
			j--;
		}
		i--;
	}
	ft_putchar_fd('\n', 1);
}
