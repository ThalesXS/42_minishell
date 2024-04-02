/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:00:28 by pabernar          #+#    #+#             */
/*   Updated: 2024/03/24 16:14:44 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_executer(char *command, char **new_array,
		char **array_env, t_parsed *tokens)
{
	struct stat path_stat;

	ft_restore_signals();
	stat(command, &path_stat);
	if (execve(command, new_array, array_env) == -1)
	{
		if (strncmp(command, "./", 2) && strncmp(command, "/", 1))
		{
			ft_putendl_fd(" command not found", 2);
			g_signal = 127;
		}
		else if (S_ISDIR(path_stat.st_mode))
		{
			ft_putendl_fd(" Is a directory", 2);
			g_signal = 126;
		}
		else
		{
			ft_putendl_fd(" command not found", 2);
			g_signal = 127;
		}
		free_splits(new_array);
		free_splits(array_env);
//		free(command);
		ft_exit(tokens, NULL, NULL, 0);
	}
}
void	ft_save_exit_status(int status, t_envs *envs)
{
	char	*exit_status;
	char	*key;

	exit_status = ft_itoa(status);
	key = ft_strjoin("?=", exit_status);
	envs = ft_add_env(envs, ft_new_env(key));
	free(exit_status);
}
