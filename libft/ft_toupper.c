/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:15:14 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/04 09:28:43 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 'a')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_toupper('a'));
	return (0);
}*/
