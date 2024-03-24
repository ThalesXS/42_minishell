/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:35:50 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/07 17:12:26 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(const char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_strtrim_strlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i] && ft_inset(s1[i], set))
		i++;
	while (s1[i])
	{
		count++;
		i++;
	}
	i--;
	while (ft_inset(s1[i], set))
	{
		if (count > 0)
			count--;
		else
			return (count);
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;	

	len = ft_strtrim_strlen(s1, set);
	if (len)
		str = malloc(len + 1);
	else
		str = malloc(1);
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (s1[i] && ft_inset(s1[i], set))
		i++;
	while (s1[i] && len > 0)
	{
		str[j] = s1[i];
		len--;
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*set;

	str = "-----The-cake-is-a-lie-----";
	set = "-";
	str = ft_strtrim(str, set);
	printf("%s", str);
	return (0);
}*/
