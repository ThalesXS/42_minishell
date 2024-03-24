/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:37:04 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/27 17:54:50 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static t_parsed	**ft_commands(t_parsed *tokens, int *num_com);
static int		ft_count_pipe(t_parsed *tokens);
static void		ft_overpipe(t_parsed **tokens, int *num_com);
static void		ft_disconect(t_parsed *aux);

void	ft_parser(t_parsed *tokens)
{
	t_parsed	**commands;
	int			num_com;
	int			total_com;
	int			std_fd[2];
	pid_t		parent;

	parent = getpid();
	std_fd[0] = dup(0);
	std_fd[1] = dup(1);
	commands = ft_commands(tokens, &total_com);
	num_com = 0;
	ft_pipe(&num_com, total_com, parent);
	if (ft_redirect(commands, num_com, std_fd[0]) != -1 && commands[num_com])
		ft_exec_builtins(commands[num_com]);
	dup2(std_fd[0], 0);
	dup2(std_fd[1], 1);
	close(std_fd[0]);
	close(std_fd[1]);
	ft_free_commands(commands, total_com);
	if (getpid() != parent)
		ft_exit(NULL);
	else
		waitpid(-1, NULL, 0);
}

static t_parsed	**ft_commands(t_parsed *tokens, int *num_com)
{
	t_parsed	*aux;
	t_parsed	**commands;
	int			i;

	aux = tokens;
	*num_com = ft_count_pipe(tokens);
	commands = ft_calloc(*num_com + 1, sizeof(t_parsed *));
	i = 0;
	commands[i++] = aux;
	while (aux)
	{
		if (aux->type == RD_OVERWRITE && aux->next && aux->next->type == PIPE)
			ft_overpipe(&aux, num_com);
		else if (aux->type == PIPE)
		{
			commands[i] = aux->next;
			ft_disconect(aux);
			aux = commands[i++];
		}
		else
			aux = aux->next;
	}
	return (commands);
}

static void	ft_disconect(t_parsed *aux)
{
	aux->prev->next = NULL;
	aux->next->prev = NULL;
	aux->next = NULL;
	ft_free_tokens(aux);
}

static void	ft_overpipe(t_parsed **tokens, int *num_com)
{
	t_parsed	*pipe_token;

	pipe_token = (*tokens)->next;
	(*tokens)->next = pipe_token->next;
	(*tokens)->next->prev = *tokens;
	free(pipe_token->text);
	free(pipe_token);
	(*num_com)--;
}

static int	ft_count_pipe(t_parsed *tokens)
{
	int	i;

	i = 1;
	while (tokens)
	{
		if (tokens->type == PIPE)
			i++;
		tokens = tokens->next;
	}
	return (i);
}
