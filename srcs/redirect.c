/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:08:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/27 17:55:58 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	ft_write_append(t_parsed **aux, t_parsed **tokens,
				int num_com, int flag);
static int	ft_input(t_parsed **aux, t_parsed **tokens, int num_com);
static int	ft_doc(t_parsed **aux, t_parsed **tokens, int num_com, int std_0);

int	ft_redirect(t_parsed **tokens, int num_com, int std_0)
{
	t_parsed	*aux;
	int			fd;

	aux = tokens[num_com];
	fd = 1;
	while (aux)
	{
		if (aux->type == RD_OVERWRITE)
			fd = ft_write_append(&aux, tokens,
					num_com, O_WRONLY | O_CREAT | O_TRUNC);
		else if (aux->type == RD_APPEND)
			fd = ft_write_append(&aux, tokens,
					num_com, O_WRONLY | O_CREAT | O_APPEND);
		else if (aux->type == RD_INPUT)
			fd = ft_input(&aux, tokens, num_com);
		else if (aux->type == RD_HEREDOC)
			fd = ft_doc(&aux, tokens, num_com, std_0);
		if (aux)
			aux = aux->next;
		if (fd == -1)
			ft_putstr_fd("Invalid file permission for redirection.\n", 1);
		if (fd <= -1)
			return (-1);
	}
	return (fd);
}

static int	ft_write_append(t_parsed **aux, t_parsed **tokens,
				int num_com, int flag)
{
	int			fd;
	t_parsed	*tmp;
	t_parsed	*free_me;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	fd = open(free_me->next->text, flag, 0644);
	if (fd != -1)
	{
		dup2(fd, 1);
		close(fd);
	}
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
	return (fd);
}

static int	ft_input(t_parsed **aux, t_parsed **tokens, int num_com)
{
	int			fd;
	t_parsed	*tmp;
	t_parsed	*free_me;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	fd = open(free_me->next->text, O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, 0);
		close(fd);
	}
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
	return (fd);
}

static int	ft_doc(t_parsed **aux, t_parsed **tokens, int num_com, int std_0)
{
	int			pipe_fd[2];
	int			status;
	t_parsed	*tmp;
	t_parsed	*free_me;
	pid_t		pid;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	status = pipe(pipe_fd);
	if (status == -1)
		ft_printf("Error creating pipe\n");
	pid = ft_manage_heredoc(pipe_fd, free_me->next->text, std_0, tokens);
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
	return (pid);
}

void	ft_in_doc(int pipe_fd[2], char *heredoc)
{
	char	*line;
	int		status;

	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, heredoc))
			break ;
		status = write(pipe_fd[1], line, ft_strlen(line));
		if (status == -1)
			ft_printf("Error writing to pipe\n");
		status = write(pipe_fd[1], "\n", 1);
		if (status == -1)
			ft_printf("Error writing to pipe\n");
		free(line);
	}
}
