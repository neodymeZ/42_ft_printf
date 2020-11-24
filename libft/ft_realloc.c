/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:53:46 by larosale          #+#    #+#             */
/*   Updated: 2020/06/02 12:56:45 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates "new_size" bytes of memory and copies there the byte string
** located at pointer "ptr" (within "old_size"), then frees the latter.
** Returns the new pointer. If ptr is NULL, the function is equivalent to
** malloc(new_size). If "new_size" is less than "old_size", "ptr" is returned.
*/

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	if (!ptr || !old_size)
		return (malloc(new_size));
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	if (!(new_ptr = malloc(new_size)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
