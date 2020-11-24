/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isutf8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 23:41:21 by larosale          #+#    #+#             */
/*   Updated: 2020/06/21 00:22:31 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks, whether the characters in a string, pointed to by "str", are a
** valid UTF-8 encoded multibyte character (up to 4 bytes).
** Returns 0 if the byte sequence is not UTF-8, or the number of bytes in
** multibyte character.
** Function is NOT SAFE (does not check for NULL "str").
*/

int	ft_isutf8(const char *str)
{
	unsigned char *temp;

	temp = (unsigned char *)str;
	if (*temp == '\0')
		return (0);
	if (*temp >> 7 == 0)
		return (1);
	if (*temp >> 5 == 0x6 && *(temp + 1) >> 6 == 0x2)
		return (2);
	if (*temp >> 4 == 0xE && *(temp + 1) >> 6 == 0x2 && *(temp + 2) >> 6 == 0x2)
		return (3);
	if (*temp >> 3 == 0x1E && *(temp + 1) >> 6 == 0x2 &&
		*(temp + 2) >> 6 == 0x2 && *(temp + 3) >> 6 == 0x2)
		return (4);
	return (0);
}
