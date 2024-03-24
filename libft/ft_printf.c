/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:28:19 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/21 16:00:29 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_typefinder(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	count;

	ft_printf("\nMy Printf:\n");
	count = ft_printf("%c, %%testes %s", '1', "12345");
	ft_printf("\ncount of last sentence: %i\n", count);
	ft_printf(" count: %i\n", ft_printf("NULL %s NULL", 0));
	ft_printf("\t count: %i\n", ft_printf("%i", 2147483647));
	ft_printf("\t\t count: %d\n", ft_printf("%i", -101));
	ft_printf("\t count: %i\n", ft_printf("%i", -2147483648));
	ft_printf("\t count: %i\n", ft_printf("%u", 4294967295));
	ft_printf("\t\t count: %i\n", ft_printf("%x", 255));
	ft_printf("\t count: %i\n", ft_printf("%X", 2147483647));
	ft_printf("\t count: %i\n", ft_printf("%p", &"ola"));
	ft_printf("\t\t count: %i\n", ft_printf("%p", 0));
	ft_printf("\t count: %i\n", ft_printf(" %p %p ", 0, 0));
	
	printf("\n\nOriginal Printf:\n");
	count = printf("%c, %%testes %s", '1', "12345");
	printf("\ncount of last sentence: %i\n", count);
	printf(" count: %i\n", printf("NULL %s NULL", (char *) 0));
	printf("\t count: %i\n", printf("%i", 2147483647));
	printf("\t\t count: %d\n", printf("%i", -101));
	printf("\t count: %i\n", printf("%li", -2147483648));
	printf("\t count: %i\n", printf("%ld", 4294967295));
	printf("\t\t count: %i\n", printf("%x", 255));
	printf("\t count: %i\n", printf("%X", 2147483647));
	printf("\t count: %i\n", printf("%p", &"ola"));
	printf("\t\t count: %i\n", printf("%p", (void *) 0));
	printf("\t count: %i\n", printf(" %p %p ", (void *) 0, (void *) 0));

	return (0);
}*/
