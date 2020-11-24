/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larosale <larosale@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:16:01 by larosale          #+#    #+#             */
/*   Updated: 2020/05/13 19:51:52 by larosale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*curlst;

	if (lst && (newlst = ft_lstnew(f(lst->content))))
	{
		curlst = newlst;
		lst = lst->next;
		while (lst)
		{
			if (!(curlst->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			curlst = curlst->next;
			lst = lst->next;
		}
		curlst->next = NULL;
		return (newlst);
	}
	return (NULL);
}
