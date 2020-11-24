/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signbit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:55:47 by larosale          #+#    #+#             */
/*   Updated: 2020/07/01 23:07:52 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the sign bit of a double number "value" (1 for negative and 0 for
** positive numbers).
*/

int	ft_signbit(double value)
{
	unsigned short	*sign_ptr;
	int				result;

	sign_ptr = (unsigned short *)&value + 3;
	result = (int)((*sign_ptr & 0x8000) >> 15);
	return (result);
}
