/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:19:11 by dmeirele          #+#    #+#             */
/*   Updated: 2024/04/18 19:05:59 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parsed	*ft_tokenizer(char *line);

int	ft_more_than_blank(char *line)
{
	int	i;
	int	not_blank;

	i = 0;
	not_blank = 0;
	while (line[i])
	{
		if (line[i] != ' ' || (line[i] >= 7 && line[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

void	ft_minishell(void)
{
	char		*line;
	char		*prompt;
	t_parsed	*tokens;

	while (1)
	{
		prompt = ft_get_dir();
		line = readline(prompt);
		free(prompt);
		if (!line)
			ft_handle_eof();
		if (ft_more_than_blank(line))
		{
			add_history(line);
			tokens = ft_tokenizer(line);
			if (!tokens)
				continue ;
			if (valid_tokens(tokens))
				ft_parser(tokens);
		}
		free(line);
	}
}

static t_parsed	*ft_tokenizer(char *line)
{
	t_parsed	*tokens;
	char		*add_pad;

	if (!ft_check_open_quotes(line))
		return (NULL);
	if (!redirect_basic_check(line))
	{
		ft_putendl_fd(" syntax error near invalid redirect", 2);
		g_signal = 2;
		return (NULL);
	}
	if (!pipe_check(line))
	{
		ft_putendl_fd(" syntax error near unexpected token `|'", 2);
		g_signal = 2;
		return (NULL);
	}
	add_pad = pad_central(line);
	tokens = ft_split_token(add_pad);
	ft_treat_token(&tokens, add_pad);
	free(add_pad);
	return (tokens);
}

int	ft_check_open_quotes(char *line)
{
	char	quote;
	int		state;

	state = 0;
	while (*line)
	{
		if (!state && (*line == '\'' || *line == '\"'))
		{
			state = 1;
			quote = *line;
		}
		else if (state && *line == quote)
			state = 0;
		line++;
	}
	if (state && write(2, "Error: Open quotes\n", 19))
		return (0);
	return (1);
}

int	redirect_basic_check(char *line)
{
	int	i;
	int	count;

	i = -1;
	while (line[++i])
	{
		count = 0;
		if (find_char(line[i], "><") && !quotes_open(line, i))
		{
			while (line[i] && find_char(line[i], "><"))
			{
				if (find_char(line[i + 1], "><") && line[i + 1] != line[i])
					return (0);
				count++;
				i++;
			}
		}
		if (count > 2)
			return (0);
	}
	return (1);
}
