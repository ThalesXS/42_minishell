/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:37:44 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:23:10 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_valreturn(char *dst, const char *src, size_t size)
{
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	else
		return (ft_strlen(dst) + ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	output;		
	size_t			i;

	i = 0;
	output = ft_valreturn(dst, src, size);
	while (dst[i] && size > 0)
	{
		size--;
		i++;
	}
	while (size > 1 && *src)
	{
		dst[i] = *src;
		i++;
		src++;
		size--;
	}
	if (size >= 1)
		dst[i] = '\0';
	return (output);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*frase;
	unsigned int	size;
	int	resultado;

	frase = "1234567890";
	char fnova[100] = "pow";
	size = 7;
	printf("%s\n", frase);
	printf("%s\n", fnova);
	resultado = ft_strlcat(fnova, frase, size);
	printf("%s\n", fnova);
	printf("%i\n", resultado);
	return (0);
}*/
