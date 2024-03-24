/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:19:48 by hescoval          #+#    #+#             */
/*   Updated: 2024/02/26 20:50:07 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	pad(char *src, char *dest, int i, int j)
{
	char	skip;

	while (src[i])
	{
		if (src[i] && find_char(src[i], "|><") && !quotes_open(src, i))
		{
			dest[j++] = ' ';
			skip = src[i];
			while (src[i] == skip)
				dest[j++] = src[i++];
			dest[j++] = ' ';
			continue ;
		}
		dest[j++] = src[i];
		i++;
	}
}

char	*pad_central(char *line)
{
	int		extra;
	char	*ret;

	extra = padding_needed(line, 0, 0);
	if (extra == 0)
		return (ft_strdup(line));
	ret = (char *)ft_calloc(1, ft_strlen(line) + extra + 1);
	pad(line, ret, 0, 0);
	return (ret);
}

int	padding_needed(char *line, int i, int pad)
{
	char	skip;

	while (line[i])
	{
		if (line[i] && find_char(line[i], "|><") && !quotes_open(line, i))
		{
			skip = line[i];
			while (line[i] && line[i] == skip)
				i++;
			pad += 2;
			continue ;
		}
		i++;
	}
	return (pad);
}

void	ft_farfaraway(t_parsed *tokens, int klen, char **new, char **tmp)
{
	klen = ft_key_len(tokens->text);
	klen = ft_before_exp(tokens->text) + ft_key_len(tokens->text) + 1;
	*new = ft_strjoin(*tmp, (tokens->text + klen));
	free(*tmp);
	free(tokens->text);
	tokens->text = *new;
}

int	pipe_check(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '|' && !quotes_open(line, i))
		{
			if (i == 0)
				return (0);
			if (line[i + 1] == '\0')
				return (0);
			if (i != 0 && (line[i - 1] == '|' || line[i + 1] == '|'))
				return (0);
		}
	}
	return (1);
}
