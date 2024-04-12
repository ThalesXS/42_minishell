/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:07:13 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/12 21:09:56 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_io_reset(int *std_fd)
{
	dup2(std_fd[0], 0);
	dup2(std_fd[1], 1);
	close(std_fd[0]);
	close(std_fd[1]);
}

int	ft_get_fd(t_parsed *aux, t_parsed **tokens, int num_com, int std_0)
{
	int	fd;

	fd = 1;
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
	return (fd);
}

int	ft_invalid_pipe(t_parsed *tokens)
{
	if (!tokens->next || !tokens->prev || tokens->next->type == PIPE)
	{
		ft_putendl_fd("Invalid Pipe", 2);
		g_signal = 2;
		return (0);
	}
	return (1);
}

int	ft_check_quotes_and_exp(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\'')
		return (0);
	while (str[i])
	{
		if (str[i] == '$'
			&& (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\"'))
			return (0);
		else if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
