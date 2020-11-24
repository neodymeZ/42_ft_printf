/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:32:42 by larosale          #+#    #+#             */
/*   Updated: 2020/07/01 12:22:05 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Pads the "input" string with the given amount ("num") of "pad" symbols.
** If "num" < 0 the padding is made to the left of the "input" string, if
** "num" > 0 - to the right. The function returns NULL on error and "input"
** if num == 0.
** Allocates (ft_strlen(input) + num + 1) bytes of memory.
** Frees "input" if padding was made and "free_flag" is set to FREE(1).
** Otherwise the flag should be set to NOFREE(0).
*/

char	*ft_strpad(char *input, char pad, int num, int free_flag)
{
	char	*padding;
	char	*output;

	if (num < 0)
	{
		num = -num;
		padding = ft_charstr(num, pad);
		output = ft_strjoin(padding, input);
		free(padding);
		if (free_flag == FREE)
			free(input);
		return (output);
	}
	else if (num > 0)
	{
		padding = ft_charstr(num, pad);
		output = ft_strjoin(input, padding);
		free(padding);
		if (free_flag == FREE)
			free(input);
		return (output);
	}
	return (input);
}
