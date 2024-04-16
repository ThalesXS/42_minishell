/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:57:13 by dmeirele          #+#    #+#             */
/*   Updated: 2024/04/16 19:19:22 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	ft_update_curr_dir(t_envs *envs, char *curr_dir, char *old_pwd);
static void	ft_get_home_dir(t_envs *envs);
static int	ft_change_directory(char *args, t_envs *envs);
static void	ft_change_directory_exception(t_envs *head, t_envs *envs);

void	ft_exec_cd(t_parsed *tokens, t_envs *envs)
{
	char	*args;
	t_envs	*head;

	head = envs;
	if (tokens && tokens->next)
	{
		ft_err_msg(" too many arguments", 1);
		return ;
	}
	if (tokens)
		args = tokens->text;
	else
		args = NULL;
	if (!ft_change_directory(args, envs))
		ft_change_directory_exception(head, envs);
}

static void	ft_change_directory_exception(t_envs *head, t_envs *envs)
{
	char	*helper[2];

	while (head)
	{
		if (!ft_strcmp(head->key, "OLDPWD"))
			helper[0] = ft_strdup(head->value);
		if (!ft_strcmp(head->key, "PWD"))
			helper[1] = ft_strdup(head->value);
		head = head->next;
	}
	ft_update_curr_dir(envs, helper[0], helper[1]);
}

static int	ft_change_directory(char *args, t_envs *envs)
{
	char	old_pwd[PATH_MAX];
	char	curr_dir[PATH_MAX];

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
				ft_err_msg(" Permission denied", 1);
			else if (errno == 2)
				ft_err_msg(" No such file or directory", 1);
		}
		return (1);
	}
	return (0);
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
