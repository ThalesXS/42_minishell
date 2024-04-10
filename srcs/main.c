/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:48:43 by pabernar          #+#    #+#             */
/*   Updated: 2024/04/10 16:15:10 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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
