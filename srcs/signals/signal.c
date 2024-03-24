/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:42:17 by pabernar          #+#    #+#             */
/*   Updated: 2024/02/27 15:01:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_init_signals(void)
{
	g_signal = 0;
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_ignore_signals(void)
{
	signal(SIGINT, ft_handle_sigint_ign);
	signal(SIGQUIT, ft_handle_sigquit);
}

void	ft_restore_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	ft_doc_signals(void)
{
	signal(SIGINT, ft_handle_doc);
	signal(SIGQUIT, SIG_IGN);
}

t_parsed	**ft_save_commands(t_parsed **commands)
{
	static t_parsed	**save = NULL;

	if (commands)
		save = commands;
	return (save);
}
