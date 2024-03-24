/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <pabernar@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:09:00 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/18 11:32:58 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_putchar(str[i++]);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (i);
}
