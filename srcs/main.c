/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:18:56 by dmeirele          #+#    #+#             */
/*   Updated: 2024/04/18 17:55:50 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 && argv)
		return (printf("No arguments\n"));
	return_argv(argv);
	ft_init_signals();
	g_signal = 0;
	return_envs(ft_create_envs(envp));
	ft_minishell();
	return (0);
}
