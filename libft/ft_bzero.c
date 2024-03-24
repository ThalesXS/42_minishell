/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:15:10 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:23:50 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	int	i;

	i = 0;
	str = malloc(11);
	str[10] = '5';
	ft_bzero(str, 10);
	while (str[i] == 0)
	{
		printf("Null\n");
		i++;
	}	
	printf("%c", str[i]);
	free(str);
	return (0);
}*/
