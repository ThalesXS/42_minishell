/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:09:08 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:15:07 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tar;
	const char		*ptr;
	size_t			i;

	tar = dest;
	ptr = src;
	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	while (i < n)
	{
		tar[i] = ptr[i];
		i++;
	}
	return (dest);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*frase;
	
	str = malloc(11);
	str[10] = '\0';
	frase = "1234567890";
	ft_memcpy(str, frase, 10);
	printf("%s", str);
	free(str);
	return (0);
}*/
