/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:12:17 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/21 19:31:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_quotes_and_exp(char *str);
static void	ft_expanding(t_parsed *tokens, char *new, char *tmp, t_envs *envs);

t_parsed	*ft_expand_variables(t_parsed *tokens)
{
	char		*new;
	char		*tmp;
	t_envs		*envs;
	t_parsed	*aux;
	t_parsed	*to_free;

	aux = tokens;
	while (aux && aux->text)
	{
		to_free = NULL;
		while (aux && ft_check_quotes_and_exp(aux->text))
		{
			envs = return_envs(0);
			new = NULL;
			tmp = NULL;
			if (ft_prev_is_redirect(aux))
				break ;
			ft_expanding(aux, new, tmp, envs);
			ft_null_text(&aux, &tokens, &to_free);
		}
		if (!to_free)
			aux = aux->next;
		free(to_free);
	}
	return (tokens);
}

static void	ft_expanding(t_parsed *tokens, char *new, char *tmp, t_envs *envs)
{
	int		klen;
	char	*point;

	ft_init_temp(tokens, &klen, &point, &tmp);
	if (!ft_strncmp(point, "?", 1))
	{
		ft_expand_question_mark(tokens, new, tmp);
		return ;
	}
	while (envs && ft_strncmp(point, envs->key, ft_envlen(point)) != 0)
		envs = envs->next;
	if (envs && envs->value)
	{
		new = ft_strjoin(tmp, envs->value);
		klen = ft_before_exp(tokens->text) + ft_strlen(envs->key) + 1;
		free(tmp);
		tmp = ft_substr(tokens->text, klen, ft_strlen(tokens->text) - klen);
		free(tokens->text);
		tokens->text = ft_strjoin(new, tmp);
		free(new);
		free(tmp);
	}
	else
		ft_farfaraway(tokens, klen, &new, &tmp);
}

size_t	ft_envlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

int	ft_key_len(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == '$')
		i++;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?'))
	{
		i++;
		j++;
	}
	return (j);
}

static int	ft_check_quotes_and_exp(char *str)
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
