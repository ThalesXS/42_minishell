/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:57:39 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:17:56 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_strlen("test"));
	printf("%i\n", ft_strlen(" "));
	printf("%i\n", ft_strlen("the cake is a lie!"));
	printf("%i\n", ft_strlen("1234567890"));
	printf("%i\n", ft_strlen("Ken"));
	return (0);
}*/
