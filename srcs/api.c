/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:00:28 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/01 15:29:37 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_envs	*return_envs(t_envs *envs)
{
	static t_envs	*static_envs;

	if (envs)
		static_envs = envs;
	return (static_envs);
}

char	**return_argv(char **argv)
{
	static char	**static_argv;

	if (argv)
		static_argv = argv;
	return (static_argv);
}
