/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:09:26 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 12:03:25 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;	
	unsigned char	num;
	size_t			i;

	ptr = (unsigned char *) s;
	num = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == num)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	
//	str = "/|\x12\xff\x09\x42\2002\42|\\";
//	printf("%s\n", (char *)ft_memchr(str, '\200', 10));
	str = "/|\x12\xff\x09\x42\042\42|\\";
	printf("%s\n", (char *)ft_memchr(str, '\200', 10));
	return (0);

}*/
