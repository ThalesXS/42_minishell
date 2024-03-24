/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:25 by pabernar          #+#    #+#             */
/*   Updated: 2023/11/13 10:12:11 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoalen(int n)
{
	int	count;

	count = 0;
	if (n >= 0)
		count++;
	else
		count += 2;
	if (n == 0)
		return (count + 1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_itoalen(n);
	str = malloc(len);
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[len - 1] = '\0';
	while (n != 0)
	{
		if (n < 0)
			str[len - 2] = (n % 10 * -1) + 48;
		else
			str[len - 2] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}*/
