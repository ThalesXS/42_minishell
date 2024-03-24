/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:55:00 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/06 11:55:30 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size)
	{
		while (*src && count < (size - 1))
		{
			*dst = *src;
			dst++;
			src++;
			count++;
		}
		*dst = '\0';
	}
	while (*src)
	{
		count++;
		src++;
	}
	return (count);
}
