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
	char 	*helper_pwd;
	char 	*helper2;
	char	*args;
	t_envs	*head;

	head = envs;
	if (tokens && tokens->next)
	{
		ft_putendl_fd(" too many arguments", 2);
		g_signal = 1;
		return ;
	}
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
		{
			if (errno == 13)
				ft_putendl_fd(" Permission denied", 2);
			else if(errno == 2)	
				ft_putendl_fd(" No such file or directory", 2);
			g_signal = 1;
		}
	}
	else
	{
		while (head)
		{
			if (!ft_strcmp(head->key, "OLDPWD"))
				helper_pwd = ft_strdup(head->value);
			if (!ft_strcmp(head->key, "PWD"))
				helper2 = ft_strdup(head->value);
			head = head->next;
		}
		chdir(helper_pwd);
		ft_update_curr_dir(envs, helper_pwd, helper2);
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
