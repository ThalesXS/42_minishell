/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:18:10 by dmeirele          #+#    #+#             */
/*   Updated: 2024/04/22 12:18:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_processio	*ft_return_processio(t_processio *processio)
{
	static t_processio	*static_processio = NULL;

	if (processio)
		static_processio = processio;
	return (static_processio);
}
