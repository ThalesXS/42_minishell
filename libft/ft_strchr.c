/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:38:51 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 13:05:10 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	car;
	unsigned int	i;	

	i = 0;
	car = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == car)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == car)
		return ((char *) &s[i]);
	return (0);
}
/*
#include <stdio.h>
// ft_strchr(s, 't' + 256) == s)
int	main(void)
{
	char	*str;
	char	*frase;
	char	c;

	str = "teste";
	c = 'e';
	frase = ft_strchr(str, c);
	printf("%s\n", frase);
	return (0);
}*/
