/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:15:14 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/17 19:24:54 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_child(int *pipe_fd);
static void	ft_parent(int *pipe_fd);

pid_t	ft_pipe(int *num_com, int total_com)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid;

	pid = 0;
	if (*num_com < total_com - 1)
	{
		status = pipe(pipe_fd);
		if (status == -1)
			ft_printf("Error creating pipe\n");
		pid = fork();
		if (pid == 0)
		{
			ft_child(pipe_fd);
			(*num_com)++;
			pid = ft_pipe(num_com, total_com);
		}
		else
			ft_parent(pipe_fd);
	}
	return (pid);
}

static void	ft_parent(int *pipe_fd)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
}

static void	ft_child(int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
}

pid_t	ft_manage_heredoc(int pipe_fd[2], char *heredoc,
			int *std_fd, t_parsed **tokens)
{
	pid_t	pid;

	pid = fork();
	ft_ignore_signals();
	if (pid == 0)
	{
		ft_save_commands(tokens);
		ft_doc_signals();
		dup2(std_fd[0], 0);
		dup2(std_fd[1], 1);
		ft_in_doc(pipe_fd, heredoc);
		ft_free_commands(tokens, 1);
		ft_exit(NULL, NULL, NULL, 0);
	}
	else
		waitpid(pid, &g_signal, 0);
	if (g_signal != 65280)
		dup2(pipe_fd[0], 0);
	else
		pid = -2;
	ft_init_signals();
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (pid);
}

int	valid_tokens(t_parsed *tokens)
{
	int	type;

	while (tokens)
	{
		type = tokens->type;
		if (type == PIPE)
		{
			if (!tokens->next || !tokens->prev || tokens->next->type == PIPE)
			{
				ft_putendl_fd("Invalid Pipe", 2);
				g_signal = 2;
				return (0);
			}
		}
		else if (type != STRING)
		{
			if (!tokens->next || tokens->next->type != STRING)
			{
				ft_putendl_fd(" syntax error near unexpected token `newline'", 2);
				g_signal = 2;
				return (0);
			}
		}
		tokens = tokens->next;
	}
	return (1);
}
