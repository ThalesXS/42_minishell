/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:00:28 by pabernar          #+#    #+#             */
/*   Updated: 2024/03/24 16:02:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_envs	*ft_create_envs(void)
{
	extern char	**environ;
	t_envs		*envs;

	envs = 0;
	while (*environ)
	{
		envs = ft_add_env(envs, ft_new_env(*environ));
		environ++;
	}
	envs = ft_add_env(envs, ft_new_env("?=0"));
	return (envs);
}

t_envs	*ft_new_env(char *str)
{
	t_envs	*envs;
	int		len;

	envs = malloc(sizeof(t_envs));
	len = 0;
	while (str[len] != '=')
		len++;
	len++;
	envs->key = malloc(len);
	ft_strlcpy(envs->key, str, len);
	str += (len);
	len = ft_strlen(str);
	len++;
	envs->value = malloc(len);
	ft_strlcpy(envs->value, str, len);
	envs->next = 0;
	return (envs);
}

t_envs	*ft_add_env(t_envs *envs, t_envs *new)
{
	t_envs	*start;

	start = 0;
	if (envs && new)
	{
		start = envs;
		while (envs->next && ft_strcmp(envs->key, new->key))
			envs = envs->next;
		if (!ft_strcmp(envs->key, new->key))
		{
			free(envs->value);
			envs->value = new->value;
			free(new->key);
			free(new);
			return (start);
		}
		envs->next = new;
		return (start);
	}
	else if (new)
		return (new);
	return (0);
}

char	**ft_array_envs(t_envs *envs)
{
	t_envs	*start;
	int		len;
	char	*temp;
	char	**arr;

	len = 1;
	start = envs;
	while (envs && len++)
		envs = envs->next;
	arr = malloc(sizeof(char *) * len);
	len = 0;
	while (start)
	{
		temp = ft_strjoin(start->key, "=");
		arr[len] = ft_strjoin(temp, start->value);
		free(temp);
		len++;
		start = start->next;
	}
	arr[len] = 0;
	return (arr);
}
