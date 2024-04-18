/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:07:51 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/18 16:37:30 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_errno(void)
{
	if (errno == 13)
		ft_err_msg(" Permission denied", 1);
	else if (errno == 2)
		ft_err_msg(" No such file or directory", 1);
}

void	ft_while_else(char	**helper_pwd, char	**helper2, t_envs **head)
{
	if (!ft_strcmp((*head)->key, "OLDPWD"))
		*helper_pwd = ft_strdup((*head)->value);
	if (!ft_strcmp((*head)->key, "PWD"))
		*helper2 = ft_strdup((*head)->value);
	(*head) = (*head)->next;
}

void	ft_get_oldpwd_dir(t_envs *envs)
{
	char	*old_dir;

	old_dir = NULL;
	while (envs)
	{
		if (!ft_strcmp(envs->key, "OLDPWD"))
			old_dir = ft_strdup(envs->value);
		envs = envs->next;
	}
	if (!chdir(old_dir))
	{
		if (old_dir)
			free(old_dir);
		return ;
	}
	ft_putendl_fd(" OLDPWD not set", 2);
}

void	ft_update_curr_dir(t_envs *envs, char *curr_dir, char *old_pwd)
{
	while (envs)
	{
		if (!ft_strcmp(envs->key, "PWD"))
		{
			if (envs->value)
				free(envs->value);
			envs->value = ft_strdup(curr_dir);
		}
		if (!ft_strcmp(envs->key, "OLDPWD"))
		{
			if (envs->value)
				free(envs->value);
			envs->value = ft_strdup(old_pwd);
		}
		envs = envs->next;
	}
}