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

void	ft_exec_pwd()
{
	char	*curr_dir;

	curr_dir = getcwd(0,0);
	printf("%s\n", curr_dir);
	free(curr_dir);
}
