/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:18:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/09 08:50:09 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (start > size)
		str = malloc(1);
	else if (len < (size - start))
		str = malloc(len + 1);
	else
		str = malloc(size + 1 - start);
	if (!str)
		return (0);
	if (size > start)
	{
		while (i < len && s[start])
		{
			str[i] = s[start];
			start++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*frase;
	
	frase = "The Cake is a Lie!";	
	printf("%s\n", ft_substr(frase, 4, 10));
	printf("%zu", ft_strlen(ft_substr(frase, 4, 10)));
	return (0);
}*/
