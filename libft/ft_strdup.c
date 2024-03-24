/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:21:48 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 14:34:16 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		count;
	char	*nstr;

	count = 0;
	while (src[count])
		count++;
	nstr = malloc(count + 1);
	if (!nstr)
		return (0);
	count = 0;
	while (src[count])
	{
		nstr[count] = src[count];
		count++;
	}
	nstr[count] = '\0';
	return (nstr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*frase;
	char	*newstr;

	frase = "hello world!";
	newstr = ft_strdup(frase);
	printf("%s", newstr);
	free(newstr);
	return (0);	
}*/
