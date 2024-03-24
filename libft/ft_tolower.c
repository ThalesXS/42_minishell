/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:15:14 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/04 09:38:31 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c) && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_tolower('A'));
	return (0);
}*/
