/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:08:06 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:15:57 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_backwards(void *dest, const void *src, size_t n)
{
	unsigned char	*tar;
	const char		*ptr;
	size_t			i;

	tar = dest;
	ptr = src;
	i = 0;
	if (n > 0)
		i = n - 1;
	while (i > 0)
	{
		tar[i] = ptr[i];
		i--;
	}
	tar[i] = ptr[i];
	return (dest);
}

static void	*ft_memmove_forwards(void *dest, const void *src, size_t n)
{
	unsigned char	*tar;
	const char		*ptr;
	size_t			i;

	tar = dest;
	ptr = src;
	i = 0;
	while (i < n)
	{
		tar[i] = ptr[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((dest == 0 && src == 0) || n == 0)
		return (dest);
	if (src < dest)
		ft_memmove_backwards(dest, src, n);
	else
		ft_memmove_forwards(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	char	*frase;
	
	str = malloc(11);
	str[10] = '\0';
	frase = "1234567890";
	ft_memcpy(str, frase, 10);
//	ft_memmove(str, &frase[5], 5);
	printf("%s\n", str);
//	ft_memmove(str, &str[3], 5);
	ft_memmove(&str[5], &str[3], 5);
	printf("%s", str);
	free(str);
	return (0);
}*/
