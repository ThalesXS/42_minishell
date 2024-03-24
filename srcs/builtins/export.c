/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:20 by dmeirele          #+#    #+#             */
/*   Updated: 2024/02/12 12:20:20 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	ft_check_first_char(char *args);
static int	ft_check_signal_equal(char *args);
static char	*ft_remove_quotes(char *array_args);

t_envs	*ft_exec_export(t_envs *envs, t_parsed *tokens)
{
	char	*new_array;
	char	*args;

	new_array = NULL;
	if (tokens)
		args = tokens->text;
	else
		args = NULL;
	if (ft_check_first_char(args) && ft_check_signal_equal(args))
	{
		if (*args == '\"' || *args == '\'')
		{
			new_array = ft_remove_quotes(args);
			envs = ft_add_env(envs, ft_new_env(new_array));
		}
		else
			envs = ft_add_env(envs, ft_new_env(args));
		free(new_array);
	}
	else
		printf("export: not a valid identifier\n");
	return (envs);
}

static int	ft_check_first_char(char *args)
{
	if (!args)
		return (0);
	while (*args == '\"' || *args == '\'')
		args++;
	if (ft_isalpha(*args))
		return (1);
	return (0);
}

static int	ft_check_signal_equal(char *args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		if (args[i] == '=' && ft_isalnum(args[i - 1])
			&& args[1 - 1] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_remove_quotes(char *array_args)
{
	char	*new_array;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (array_args[i])
	{
		if (array_args[i] != '\"' && array_args[i] != '\'')
			size++;
		i++;
	}
	new_array = malloc(sizeof(char) * size + 1);
	if (!new_array)
		return (NULL);
	i = 0;
	while (*array_args)
	{
		if (*array_args != '\"' && *array_args != '\'')
			new_array[i++] = *array_args;
		array_args++;
	}
	new_array[i] = '\0';
	return (new_array);
}
