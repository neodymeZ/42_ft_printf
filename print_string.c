/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 01:37:34 by larosale          #+#    #+#             */
/*   Updated: 2020/06/22 01:35:41 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libftprintf.h"

/*
** Handles conversion of string "arg" to the resulting string, taking the specs
** into account and returns the resulting string ("output").
** Allocates and reallocates if necessary memory needed for the "output".
*/

static char	*handle_conversion(t_specs *specs, const char *arg)
{
	char	*output;
	char	*temp;
	int		excess;

	if (specs->precision_set && !specs->length)
		output = ft_substr(arg, 0, specs->precision);
	else if (specs->precision_set && specs->length == L)
		output = ft_substr_utf8(arg, 0, specs->precision);
	else
		output = ft_strdup(arg);
	if (!output)
		return (NULL);
	if ((excess = specs->width - ft_strlen(output)) > 0 && specs->flags_minus)
	{
		temp = output;
		output = ft_strpad(temp, ' ', excess, 1);
	}
	else if (excess > 0 && !specs->flags_minus && (temp = output))
	{
		if (specs->type == PER && specs->flags_zero)
			output = ft_strpad(temp, '0', -1 * excess, 1);
		else
			output = ft_strpad(temp, ' ', -1 * excess, 1);
	}
	return (output);
}

/*
** Handles the special case of '\0' char. Takes an empty string "arg"
** as a parameter, prints the result, frees "arg".
*/

static int	handle_nul_char(t_specs *specs, char *arg)
{
	int		count_printed;
	int		i;

	count_printed = specs->width > 1 ? specs->width : 1;
	if (specs->flags_minus)
		ft_putchar_fd('\0', 1);
	if (count_printed > 1)
	{
		i = 1;
		while (i++ < count_printed)
			ft_putchar_fd(' ', 1);
	}
	if (!specs->flags_minus)
		ft_putchar_fd('\0', 1);
	free(arg);
	return (count_printed);
}

/*
** Prints the conversion result and returns the count of printed characters.
** Allocates and frees memory needed to store the resulting string.
** Frees the "arg" string.
*/

static int	generate_result(t_specs *specs, char *arg)
{
	char	*result;
	int		count_printed;

	if (!arg)
		return (-1);
	if (specs->type == C && *arg == '\0')
		return (handle_nul_char(specs, arg));
	if (!(result = handle_conversion(specs, arg)))
	{
		free(arg);
		return (-1);
	}
	count_printed = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	free(arg);
	return (count_printed);
}

/*
** Prints the resulting string of the following conversions: c, s.
** Takes pointer to variadic arguments' list "args" as an argument and,
** using the converted value of "args" creates a string "arg", which is
** then passed for processing to the "generate_result" function, which
** frees the "arg" after processing.
** Returns the count of characters printed.
*/

int			print_string(t_specs *specs, va_list args)
{
	char	*arg;

	arg = NULL;
	specs->width == -1 ? specs->width = va_arg(args, int) : 0;
	specs->width < 0 ? specs->flags_minus = 1 : 0;
	specs->width < 0 ? specs->width *= -1 : 0;
	specs->precision == -1 ? specs->precision = va_arg(args, int) : 0;
	specs->precision < 0 || specs->type == PER ? specs->precision_set = 0 : 0;
	if (specs->type == C && !specs->length &&
		!(arg = ft_charstr(1, (unsigned char)va_arg(args, int))))
		return (-1);
	else if (!arg && specs->type == C && specs->length == L &&
		!(arg = ft_wchar_to_utf8((wchar_t)va_arg(args, wint_t))))
		return (-1);
	if (specs->type == S && !specs->length && (arg = va_arg(args, char *)) &&
		!(arg = ft_strdup(arg)))
		return (-1);
	else if (!arg && specs->type == S && specs->length == L &&
		!(arg = ft_wstr_to_utf8(va_arg(args, wchar_t *))))
		return (-1);
	if (specs->type == PER && !(arg = ft_strdup("%")))
		return (-1);
	if (!arg && !(arg = ft_strdup("(null)")))
		return (-1);
	return (generate_result(specs, arg));
}
