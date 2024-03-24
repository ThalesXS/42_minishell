/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:20:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/03 17:05:01 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_isalpha(65));
	printf("%i\n", ft_isalpha(94));
	printf("%i\n", ft_isalpha(99));
	printf("%i", ft_isalpha('P'));
	return (0);
}*/
