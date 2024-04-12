/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:36 by dmeirele          #+#    #+#             */
/*   Updated: 2024/02/12 12:20:36 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_exec_env(t_envs *envs)
{
	while (envs)
	{
		if (envs->value)
			printf("%s=%s\n", envs->key, envs->value);
		envs = envs->next;
	}
}

void	ft_exec_declare_env(t_envs *envs)
{
	while (envs)
	{
		if (!envs->value && envs->key)
			printf("declare -x %s\n", envs->key);
		else if (envs->value && envs->key)
			printf("declare -x %s=\"%s\"\n", envs->key, envs->value);
		envs = envs->next;
	}
}

t_envs	*ft_return_new_env(t_envs *new, char **new_envs)
{
	while (*new_envs)
	{
		new = ft_add_env(new, ft_new_env(*new_envs));
		new_envs++;
	}
	return (new);
}

int	ft_expand_question_mark(t_parsed *tokens, char *new, char *tmp)
{
	int		klen;
	char	*signal;

	if (g_signal > 255)
		signal = ft_itoa(WEXITSTATUS(g_signal));
	else
		signal = ft_itoa(g_signal);
	new = ft_strjoin(tmp, signal);
	klen = ft_before_exp(tokens->text) + 2;
	free(tmp);
	tmp = ft_substr(tokens->text, klen, ft_strlen(tokens->text) - klen);
	free(tokens->text);
	tokens->text = ft_strjoin(new, tmp);
	free(new);
	free(tmp);
	free(signal);
	return (1);
}
