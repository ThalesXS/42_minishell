/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:48:43 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/21 12:00:37 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	g_signal;

int	main(int argc, char **argv)
{
	if (argc != 1 && argv)
		return (printf("No arguments\n"));
	return_argv(argv);
	ft_init_signals();
	ft_minishell();
	return (0);
}
