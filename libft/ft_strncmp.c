/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:03:17 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:23:22 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i] || !ptr1[i] || !ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*frase1;
	char	*frase2;
	char	c;
	char	h;

	frase1 = "teste";
	frase2 = "teste";
	printf("%i\n", ft_strncmp(frase1, frase2, 3));
	printf("%i\n\n", strncmp(frase1, frase2, 3));
	frase1 = "TESTe";
	frase2 = "TESTE";
	printf("%i\n", ft_strncmp(frase1, frase2, 5));
	printf("%i\n\n", strncmp(frase1, frase2, 5));
	frase1 = "TESTE";
	frase2 = "TESTe";
	printf("%i\n", ft_strncmp(frase1, frase2, 4));
	printf("%i\n\n", strncmp(frase1, frase2, 4));
	frase1 = "TESTEeeee";
        frase2 = "TESTe";
        printf("%i\n", ft_strncmp(frase1, frase2, 6));
        printf("%i\n\n", strncmp(frase1, frase2, 6));
	frase1 = "TES";
        frase2 = "TES";
        printf("%i\n", ft_strncmp(frase1, frase2, 4));
        printf("%i\n\n", strncmp(frase1, frase2, 4));
	frase1 = "TESTe";
        frase2 = "TESTeeeeee";
        printf("%i\n", ft_strncmp(frase1, frase2, 10));
        printf("%i\n\n", strncmp(frase1, frase2, 10));
	frase1 = "TESTE";
        frase2 = "TESTe";
        printf("%i\n", ft_strncmp(frase1, frase2, 0));
        printf("%i\n\n", strncmp(frase1, frase2, 0));
	frase1 = "TESTE";
        frase2 = "TESTe";
        printf("%i\n", ft_strncmp(frase1, frase2, -1));
        printf("%i\n\n", strncmp(frase1, frase2, -1));
	frase1 = "";
        frase2 = "TESTe";
        printf("%i\n", ft_strncmp(frase1, frase2, 4));
        printf("%i\n\n", strncmp(frase1, frase2, 4));
	c = -50;
	h = -55;
        printf("%i\n", ft_strncmp(&c, &h, 4));
        printf("%i\n\n", strncmp(&c, &h, 4));
	frase1 = "123";
        frase2 = "123";
        printf("%i\n", ft_strncmp(frase1, frase2, 10));
        printf("%i\n\n", strncmp(frase1, frase2, 10));
	frase1 = "TESTE";
        frase2 = "";
        printf("%i\n", ft_strncmp(frase1, frase2, 4));
        printf("%i\n", strncmp(frase1, frase2, 4));
	return (0);
}*/
