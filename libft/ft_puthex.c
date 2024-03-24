/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <pabernar@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:28:55 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/18 11:36:39 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	ft_puthex_write(unsigned int n, char *base)
{
	if (n >= 16)
	{
		ft_puthex_write(n / 16, base);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n % 16]);
}

int	ft_puthex(unsigned int n, int upper)
{
	int	count;

	count = ft_hexlen(n);
	if (upper)
		ft_puthex_write(n, "0123456789ABCDEF");
	else
		ft_puthex_write(n, "0123456789abcdef");
	return (count);
}
