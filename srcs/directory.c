/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:29:26 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/26 21:44:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*ft_get_dir(void)
{
	char	*dir;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	dir = ft_strjoin \
	("\001\033[1;32m\002minishell@42\001\033[0m\002:\001\033[1;34m\002", tmp);
	free(tmp);
	tmp = ft_strjoin(dir, "\001\033[0m\002$ ");
	free(dir);
	return (tmp);
}

char	**ft_get_path(t_envs *envs)
{
	char	*value;
	char	**path_value;

	path_value = NULL;
	value = NULL;
	while (envs)
	{
		if (!ft_strncmp(envs->key, "PATH", 4))
			value = ft_substr(envs->value, 0, ft_strlen(envs->value));
		envs = envs->next;
	}
	if (value)
		path_value = ft_split(value, ':');
	free(value);
	return (path_value);
}
