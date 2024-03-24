/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:18:21 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/20 11:30:55 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	*ft_remove_quotes(char *str);
static void	ft_treating(t_parsed *tokens);
static void	ft_check_unite(t_parsed *tokens, const char *line);
static void	ft_unite(t_parsed *token);

void	ft_treat_token(t_parsed *tokens, char *line)
{
	ft_check_unite(tokens, line);
	ft_expand_variables(tokens);
	ft_treating(tokens);
}

static void	ft_treating(t_parsed *tokens)
{
	t_parsed	*aux;

	aux = tokens;
	while (aux)
	{
		if (aux->text[0] == '\'' || aux->text[0] == '\"')
		{
			aux->text = ft_remove_quotes(aux->text);
		}
		aux = aux->next;
	}
	aux = tokens;
	while (aux)
	{
		while (aux->unite_with_next)
			ft_unite(aux);
		aux = aux->next;
	}
}

static void	ft_unite(t_parsed *token)
{
	t_parsed	*aux;
	t_parsed	*to_free;
	char		*old1;
	char		*old2;
	char		*new;

	aux = token;
	to_free = aux->next;
	old1 = aux->text;
	old2 = aux->next->text;
	new = ft_strjoin(aux->text, aux->next->text);
	aux->text = new;
	aux->unite_with_next = aux->next->unite_with_next;
	aux->next = aux->next->next;
	free(old1);
	free(old2);
	free(to_free);
	if (aux->next)
		aux->next->prev = aux;
}

static char	*ft_remove_quotes(char *str)
{
	char	*new;
	int		len;

	len = ft_strlen(str) - 2;
	new = ft_substr(str, 1, len);
	free(str);
	return (new);
}

static void	ft_check_unite(t_parsed *tokens, const char *line)
{
	t_parsed	*aux;
	char		*tmp;
	size_t		arg_len;

	aux = tokens;
	if (!aux)
		return ;
	arg_len = ft_strlen(aux->text);
	tmp = ft_strnstr(line, aux->text, ft_strlen(line)) + arg_len;
	while (aux)
	{
		if (*tmp != '\0' && *tmp != ' ' && *tmp != '\t')
			aux->unite_with_next = 1;
		else
			aux->unite_with_next = 0;
		while (*tmp == ' ' || *tmp == '\t')
			tmp++;
		aux = aux->next;
		if (aux)
		{
			arg_len = ft_strlen(aux->text);
			tmp = ft_strnstr(tmp, aux->text, ft_strlen(line)) + arg_len;
		}
	}
}
