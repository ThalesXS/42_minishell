/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:51:56 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/09 21:47:09 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		reading;

	i = 0;
	words = 0;
	reading = 0;
	while (s[i])
	{
		if (!reading && s[i] != c)
		{
			reading = 1;
			words += 1;
		}
		if (reading && s[i] == c)
			reading = 0;
		i++;
	}
	return (words);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char	**ft_clean(char	**arr, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	**ft_alloc_write(char const *s, char c, char **arr, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	word = 0;
	while (word < words)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		arr[word] = malloc(ft_word_len(&s[i], c) + 1);
		if (!arr[word])
			return (ft_clean(arr, word));
		while (s[i] && s[i] != c)
		{
			arr[word][j] = s[i];
			j++;
			i++;
		}
		arr[word][j] = '\0';
		word++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	words = ft_count_words(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (0);
	arr[words] = 0;
	if (words > 0)
		arr = ft_alloc_write(s, c, arr, words);
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	**arr;

	str = "hello!";
	arr = ft_split(str, ' ');
	printf("%s", arr[0]);
	str = "The cake is a lie!";
	arr = ft_split(str, ' ');
	printf("%s", arr[0]);
	printf("%s", arr[1]);
	printf("%s", arr[2]);
	printf("%s", arr[3]);
	printf("%s", arr[4]);
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr[3]);
	free(arr[4]);
	free(arr);
	return (0);
}*/
