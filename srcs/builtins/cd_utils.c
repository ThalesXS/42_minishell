/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:07:51 by txisto-d          #+#    #+#             */
/*   Updated: 2024/04/17 22:10:11 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_errno(void)
{
	if (errno == 13)
		ft_err_msg(" Permission denied", 1);
	else if (errno == 2)
		ft_err_msg(" No such file or directory", 1);
}
