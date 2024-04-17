/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:20 by dmeirele          #+#    #+#             */
/*   Updated: 2024/04/17 21:22:16 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void		ft_finish(t_envs *envs);
static t_envs	*ft_unset_variables(t_envs *envs, t_envs *start,
					t_parsed *tokens);

t_envs	*ft_exec_unset(t_envs *envs, t_parsed *tokens)
{
	t_envs	*start;

	start = envs;
	if (tokens)
		start = ft_unset_variables(envs, start, tokens);
	return_envs(start);
	return (start);
}

void	ft_unsetting(t_envs *envs, t_envs *last, t_envs **start, char *key)
{
	t_envs	*temp;

	if (envs)
	{
		if (last == envs)
			*start = envs->next;
		else
			last->next = envs->next;
		if (!ft_strcmp(key, envs->key))
		{
			temp = envs;
			envs = envs->next;
			ft_finish(temp);
		}
	}
}

static t_envs	*ft_unset_variables(t_envs *envs, t_envs *start,
		t_parsed *tokens)
{
	char	*key;
	t_envs	*last;

	if (!tokens)
		return (start);
	last = envs;
	key = tokens->text;
	envs = start;
	if (envs && !ft_strcmp(envs->key, key))
		start = envs->next;
	while (envs && ft_strcmp(key, envs->key))
	{
		last = envs;
		envs = envs->next;
	}
	ft_unsetting(envs, last, &start, key);
	return (ft_exec_unset(start, tokens->next));
}

static void	ft_finish(t_envs *envs)
{
	free(envs->key);
	free(envs->value);
	free(envs);
}
