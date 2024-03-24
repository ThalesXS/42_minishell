/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:24:42 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/26 22:23:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static t_parsed	*ft_tokenizer(char *line);

void	ft_minishell(void)
{
	char		*line;
	char		*prompt;
	t_parsed	*tokens;
	t_envs		*envs;

	envs = NULL;
	while (1)
	{
		prompt = ft_get_dir();
		line = readline(prompt);
		free(prompt);
		if (!envs)
			envs = return_envs(ft_create_envs());
		if (!line)
			ft_handle_eof();
		if (!line[0])
			continue ;
		add_history(line);
		tokens = ft_tokenizer(line);
		if (!tokens)
			continue ;
		if (valid_tokens(tokens))
			ft_parser(tokens);
		free(line);
	}
}

static t_parsed	*ft_tokenizer(char *line)
{
	t_parsed	*tokens;
	char		*help_hugo_god;

	if (!ft_check_open_quotes(line))
		return (NULL);
	if (!redirect_basic_check(line))
	{
		ft_printf("invalid redirect\n");
		return (NULL);
	}
	if (!pipe_check(line))
	{
		ft_printf("Unexpected near '|'\n");
		return (NULL);
	}
	help_hugo_god = pad_central(line);
	tokens = ft_split_token(help_hugo_god);
	ft_treat_token(tokens, help_hugo_god);
	free(help_hugo_god);
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
