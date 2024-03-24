/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:43:46 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/07 17:22:57 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mult;
	void	*mem;

	mult = nmemb * size;
	mem = malloc(mult);
	if (!mem)
		return (0);
	ft_bzero(mem, mult);
	return (mem);
}
/*
int	main(void)
{
	void	**mem;

	mem = ft_calloc(5, 5);
	free(mem);
	return (0);
}*/
