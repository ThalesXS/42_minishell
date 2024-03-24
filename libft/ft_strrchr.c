/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:58:31 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 13:06:55 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	*last;
	unsigned char	car;

	ptr = (unsigned char *) s;
	last = 0;
	car = (unsigned char) c;
	while (*ptr)
	{
		if (*ptr == car)
			last = ptr;
		ptr++;
	}
	if (last)
		return ((char *) last);
	if (*ptr == car)
		return ((char *)ptr);
	return (0);
}
/*
#include <stdio.h>
// ft_strrchr(s, 't' + 256) == s)
int	main(void)
{
	char	*str;
	char	*frase;
	char	c;

	str = "The cake is a lie";
	c = 'a';
	frase = ft_strrchr(str, c);
	printf("%s\n", frase);
	return (0);
}*/
