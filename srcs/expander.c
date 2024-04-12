/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:12:17 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/12 21:10:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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
		while (ft_check_quotes_and_exp(aux->text))
		{
			envs = return_envs(0);
			new = NULL;
			tmp = NULL;
			ft_expanding(aux, new, tmp, envs);
			if (*aux->text == '\0')
				ft_void_text(&tokens, &aux, &to_free);
		}
		aux = aux->next;
		free(to_free);
	}
	return (tokens);
}

void	ft_void_text(t_parsed **aux, t_parsed **to_free, t_parsed **tokens)
{
	if (*aux && *tokens && *to_free)
	{
		if ((*aux)->prev)
			(*aux)->prev->next = (*aux)->next;
		else
			*tokens = (*aux)->next;
		if ((*aux)->next)
			(*aux)->next->prev = (*aux)->prev;
		free((*aux)->text);
		*to_free = *aux;
	}
}

static void	ft_expanding(t_parsed *tokens, char *new, char *tmp, t_envs *envs)
{
	int		klen;
	int		before_len;
	char	*point;

	before_len = ft_before_exp(tokens->text);
	klen = ft_key_len(tokens->text);
	tmp = ft_substr(tokens->text, 0, before_len);
	point = tokens->text + before_len + 1;
	if (!ft_strncmp(point, "?", 1) && ft_expand_question_mark(tokens, new, tmp))
		return ;
	while (envs && ft_strncmp(point, envs->key, ft_strlen(envs->key)) != 0)
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

int	ft_before_exp(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}
