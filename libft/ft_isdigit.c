/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:20:32 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/03 17:05:29 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_isdigit(65));
	printf("%i\n", ft_isdigit('5'));
	printf("%i\n", ft_isdigit(48));
	printf("%i", ft_isdigit('P'));
	return (0);
}*/
