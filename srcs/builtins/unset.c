/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:20 by dmeirele          #+#    #+#             */
/*   Updated: 2024/02/12 12:20:20 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static t_envs	*ft_finish(t_envs *envs, t_envs *start, char *key);

t_envs	*ft_exec_unset(t_envs *envs, t_parsed *tokens)
{
	t_envs	*start;
	t_envs	*last;
	char	*key;

	start = envs;
	last = envs;
	if (tokens)
		key = tokens->text;
	else
		key = NULL;
	if (key && !ft_strcmp(key, envs->key))
		start = envs->next;
	else
	{
		while (envs && key && ft_strcmp(key, envs->key))
		{
			last = envs;
			envs = envs->next;
		}
		if (envs)
			last->next = envs->next;
	}
	return (ft_finish(envs, start, key));
}

static t_envs	*ft_finish(t_envs *envs, t_envs *start, char *key)
{
	if (!envs || !key)
		return (start);
	free(envs->key);
	free(envs->value);
	free(envs);
	return_envs(start);
	return (start);
}
