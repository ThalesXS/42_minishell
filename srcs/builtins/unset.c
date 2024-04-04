/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:20 by dmeirele          #+#    #+#             */
/*   Updated: 2024/04/03 16:21:07 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void		ft_finish(t_envs *envs);
static t_envs	*ft_unset_variables(t_envs *envs,
					t_envs *start, t_parsed *tokens);

t_envs	*ft_exec_unset(t_envs *envs, t_parsed *tokens)
{
	t_envs	*start;

	start = envs;
	if (tokens)
		start = ft_unset_variables(envs, start, tokens);
	return_envs(start);
	return (start);
}

static t_envs	*ft_unset_variables(t_envs *envs,
					t_envs *start, t_parsed *tokens)
{
	char	*key;
	t_envs	*last;
	t_envs	*temp;

	if (!tokens)
		return start;

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
	if (envs)
	{
		if (last == envs)
			start = envs->next;
		else
			last->next = envs->next;
		if (!ft_strcmp(key, envs->key))
		{
			temp = envs;
			envs = envs->next;
			ft_finish(temp);
		}
	}
	return ft_exec_unset(start, tokens->next);
}

static void	ft_finish(t_envs *envs)
{
	free(envs->key);
	free(envs->value);
	free(envs);
}
