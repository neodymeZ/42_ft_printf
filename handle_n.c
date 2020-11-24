/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:06:53 by larosale          #+#    #+#             */
/*   Updated: 2020/07/04 11:51:15 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libftprintf.h"

/*
** Takes pointer to variadic arguments' list "args" as an argument and
** uses the value of "args", converted to the respective pointer to int, to
** assign the number of already printed characters ("already printed")
** to the object, pointed to by the pointer.
** Returns 0 as the number of characters printed.
*/

int		handle_n(t_specs *specs, va_list args, int already_printed)
{
	va_list	args_temp;

	specs->width == -1 ? specs->width = va_arg(args, int) : 0;
	specs->width < 0 ? specs->flags_minus = 1 : 0;
	specs->width < 0 ? specs->width *= -1 : 0;
	specs->precision == -1 ? specs->precision = va_arg(args, int) : 0;
	specs->precision < 0 ? specs->precision_set = 0 : 0;
	va_copy(args_temp, args);
	if (!va_arg(args_temp, void *))
		return (0);
	va_end(args_temp);
	if (specs->length)
	{
		specs->length == HH ?
			*va_arg(args, signed char *) = already_printed : 0;
		specs->length == H ? *va_arg(args, short *) = already_printed : 0;
		specs->length == L ? *va_arg(args, long *) = already_printed : 0;
		specs->length == LL ? *va_arg(args, long long *) = already_printed : 0;
		specs->length == Z ? *va_arg(args, ssize_t *) = already_printed : 0;
		specs->length == J ? *va_arg(args, intmax_t *) = already_printed : 0;
		specs->length == T ? *va_arg(args, ptrdiff_t *) = already_printed : 0;
	}
	else
		*va_arg(args, int *) = already_printed;
	return (0);
}
