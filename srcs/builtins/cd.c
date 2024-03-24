/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:57:13 by dmeirele          #+#    #+#             */
/*   Updated: 2024/02/11 11:47:08 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	ft_update_curr_dir(t_envs *envs, char *curr_dir, char *old_pwd);
static void	ft_get_home_dir(t_envs *envs);

void	ft_exec_cd(t_parsed *tokens, t_envs *envs)
{
	char	curr_dir[PATH_MAX];
	char	old_pwd[PATH_MAX];
	char	*args;

	if (tokens)
		args = tokens->text;
	else
		args = NULL;
	if (getcwd(old_pwd, sizeof(old_pwd)))
	{
		if (args == NULL || !ft_strcmp(args, "~"))
		{
			ft_get_home_dir(envs);
			if (getcwd(curr_dir, sizeof(curr_dir)))
				ft_update_curr_dir(envs, curr_dir, old_pwd);
		}
		else if (!chdir(args))
		{
			if (getcwd(curr_dir, sizeof(curr_dir)))
				ft_update_curr_dir(envs, curr_dir, old_pwd);
		}
		else
			printf("cd: %s: No such file or directory\n", args);
	}
}

static void	ft_update_curr_dir(t_envs *envs, char *curr_dir, char *old_pwd)
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

static void	ft_get_home_dir(t_envs *envs)
{
	char	*home_dir;

	home_dir = NULL;
	while (envs)
	{
		if (!ft_strcmp(envs->key, "HOME"))
			home_dir = ft_strdup(envs->value);
		envs = envs->next;
	}
	if (!chdir(home_dir))
	{
		if (home_dir)
			free(home_dir);
		return ;
	}
}
