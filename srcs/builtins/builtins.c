/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:57:18 by dmeirele          #+#    #+#             */
/*   Updated: 2024/03/24 16:12:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_exec_builtins(t_parsed *tokens)
{
	t_envs	*envs;

	envs = return_envs(0);
	ft_save_exit_status(0, envs);
	if (!ft_strcmp(tokens->text, "echo") || !ft_strcmp(tokens->text, "\\echo"))
		ft_exec_echo(tokens->next);
	else if (!ft_strcmp(tokens->text, "cd") || !ft_strcmp(tokens->text, "\\cd"))
		ft_exec_cd(tokens->next, envs);
	else if (!ft_strcmp(tokens->text, "pwd")
		|| !ft_strcmp(tokens->text, "\\pwd"))
		ft_exec_pwd(envs);
	else if (!ft_strcmp(tokens->text, "export") || !ft_strcmp(tokens->text,
			"\\export"))
		envs = ft_exec_export(envs, tokens->next);
	else if (!ft_strcmp(tokens->text, "unset") || !ft_strcmp(tokens->text,
			"\\unset"))
		envs = ft_exec_unset(envs, tokens->next);
	else if (!ft_strcmp(tokens->text, "env")
		|| !ft_strcmp(tokens->text, "\\env"))
		ft_exec_env(envs);
	else if (!ft_strcmp(tokens->text, "exit")
		|| !ft_strcmp(tokens->text, "\\exit"))
		ft_exit(tokens);
	else
		ft_find_path(tokens, envs);
}
