/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:43:58 by larosale          #+#    #+#             */
/*   Updated: 2020/05/06 11:45:37 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Writes symbol "c" to the output with file descriptor "fd".
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
