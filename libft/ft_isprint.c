/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:20:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/03 17:05:41 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_isprint(65));
	printf("%i\n", ft_isprint(94));
	printf("%i\n", ft_isprint(99));
	printf("%i\n", ft_isprint('P'));
	printf("%i\n", ft_isprint(' '));
	printf("%i\n", ft_isprint(-1));
	printf("%i", ft_isprint(256));
	return (0);
}*/
