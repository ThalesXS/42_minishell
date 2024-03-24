/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:13:25 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/10 15:42:43 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst[0])
	{
		temp = lst[0];
		while (lst[0]->next)
			lst[0] = lst[0]->next;
		lst[0]->next = new;
		lst[0] = temp;
	}
	else
		lst[0] = new;
}
