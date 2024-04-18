/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:04:23 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/17 22:05:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_syntax_error(void)
{
	ft_putendl_fd(" syntax error near unexpected token `newline'",
		2);
	g_signal = 2;
	return (0);
}