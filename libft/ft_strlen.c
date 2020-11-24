/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:53:10 by larosale          #+#    #+#             */
/*   Updated: 2020/05/04 22:54:03 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the length of string "s", not counting the terminating NUL.
*/

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}
