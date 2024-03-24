/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:20:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/04 14:33:52 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_isascii(65));
	printf("%i\n", ft_isascii(94));
	printf("%i\n", ft_isascii(99));
	printf("%i\n", ft_isascii('P'));
	printf("%i\n", ft_isascii(-1));
	printf("%i", ft_isascii(256));
	return (0);
}*/
