/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:22:04 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/12 12:14:45 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_start(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	void	*cont;

	if (!lst || !f || !del)
		return (0);
	cont = f(lst->content);
	newlst = ft_lstnew(cont);
	if (!newlst)
	{
		del(cont);
		return (0);
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*newlst;
	void	*cont;

	start = ft_start(lst, f, del);
	if (!start)
		return (0);
	newlst = start;
	lst = lst->next;
	while (lst)
	{
		cont = f(lst->content);
		newlst->next = ft_lstnew(cont);
		if (!newlst->next)
		{
			del(cont);
			ft_lstclear(&start, del);
			return (0);
		}
		newlst = newlst->next;
		lst = lst->next;
	}
	return (start);
}
