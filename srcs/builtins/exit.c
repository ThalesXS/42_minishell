/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:14:08 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/01 10:20:06 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/*
	TODO:
		free stuff
*/

void    ft_exit(t_parsed *tokens, t_parsed *force_signal, t_parsed **commands, int total_com)
{
	int    sig_value;

	if (force_signal)
		sig_value = ft_atoi(force_signal->text);
	else
		sig_value = g_signal;
	if (tokens)
		ft_free_tokens(tokens);
	ft_free_envs(return_envs(0));
	if (commands && total_com)
		ft_free_commands(commands, total_com);
	exit(sig_value);
}