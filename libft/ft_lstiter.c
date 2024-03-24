/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:04:31 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/16 09:12:56 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	plus(void *value)
{
	int	*x;

	x = (int *) value;
	*x += 21;
}

#include <stdio.h>
int	main(void)
{
	int	*value;
	int	i;
	t_list	*lst;
	t_list	*temp;

	i = 0;
	value = malloc(sizeof(int));
	*value = 21;
	lst = ft_lstnew(value);
	while (i < 5)
	{
		value = malloc(sizeof(int));
		*value = 21;
		temp = ft_lstnew(value);
		ft_lstadd_back(&lst, temp);
		i++;
	}
	temp = lst;
	i = 0;
	while (temp)
	{
		printf("node %i\n", i);
		printf("%i\n", (*(int *)(lst->content)));
		i++;
		temp = temp->next;
	}
	ft_lstiter(lst, plus);
	temp = lst;
	i = 0;
	printf("\n\nAfter Iteration:\n\n");
	while (temp)
	{
		printf("node %i\n", i);
		printf("%i\n", (*(int *)(lst->content)));
		i++;
		temp = temp->next;
	}
	return (0);
}*/
