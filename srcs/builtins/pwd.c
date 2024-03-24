/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:15:18 by dmeirele          #+#    #+#             */
/*   Updated: 2024/02/10 23:15:18 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_exec_pwd(t_envs *envs)
{
	while (envs)
	{
		if (!ft_strcmp(envs->key, "PWD"))
			printf("%s\n", envs->value);
		envs = envs->next;
	}
}
