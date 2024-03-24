/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:46:33 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:18:34 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnstr_comp(const char *s1, const char *s2, unsigned long n)
{
	size_t			i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] && i == n)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;

	i = 0;
	if (!*little || big == little || (!*big && !*little))
		return ((char *) big);
	if (ft_strlen(big) < ft_strlen(little) || ft_strlen(little) > len)
		return (0);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
			if (!ft_strnstr_comp(&big[i], &little[0], (len - i)))
				return ((char *)&big[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*frase;
	char	*str;
	unsigned long x;

	x = 3;

	frase = "foo bay bar baz";
	str = "bay";
	//printf("%s\n", ft_strnstr(frase, str, 12));
	frase = "aaxx";
	str = "xx";
	printf("%s\n", ft_strnstr(frase, str, x));
	return (0);
}*/
