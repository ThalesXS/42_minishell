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
		if (!ft_strcmp(envs->key, "?"))
			printf("%s=%s\n", envs->key, envs->value);
		envs = envs->next;
	}
}
