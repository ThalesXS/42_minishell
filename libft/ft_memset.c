/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:05:47 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:16:34 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	str = malloc(11);
	ft_memset(str, '3', 10);
	str[10] = '\0';
	printf("%s\n", str);
	free(str);
	return (0);
}*/
