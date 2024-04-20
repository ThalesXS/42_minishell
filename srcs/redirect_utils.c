/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:00:14 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/20 20:32:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delete_redirects(t_parsed **aux, t_parsed **tokens, int num_com)
{
	tokens[num_com] = *aux;
	if (*aux)
		(*aux)->prev = NULL;
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
			ft_putendl_fd("Erro writing to pipe", 2);
		status = write(pipe_fd[1], "\n", 1);
		if (status == -1)
			ft_putendl_fd("Erro writing to pipe", 2);
		free(line);
	}
}
