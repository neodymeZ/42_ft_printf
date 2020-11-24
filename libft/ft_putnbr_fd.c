/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:17:14 by larosale          #+#    #+#             */
/*   Updated: 2020/05/06 13:15:11 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Writes integer number "n" to the output with file descriptor "fd".
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n < 0)
	{
		abs_n = -n;
		ft_putchar_fd('-', fd);
		if (abs_n > 9)
			ft_putnbr_fd(abs_n / 10, fd);
		ft_putchar_fd(((abs_n % 10) + '0'), fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}
