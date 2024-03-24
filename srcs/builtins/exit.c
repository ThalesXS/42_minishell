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

void	ft_exit(t_parsed *tokens)
{
	if (tokens)
		ft_free_tokens(tokens);
	ft_free_envs(return_envs(0));
	exit(0);
}
