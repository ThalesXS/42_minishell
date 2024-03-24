/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typefinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <pabernar@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:36 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/18 11:36:14 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_typefinder(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, unsigned long)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
