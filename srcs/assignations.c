/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:29:32 by gudias            #+#    #+#             */
/*   Updated: 2022/05/24 16:39:36 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_assignation(char *cmd)
{
	char	*equal;
	char	*name;

	equal = ft_strchr(cmd, '=');
	if (equal && (equal - cmd > 0))
	{
		name = ft_substr(cmd, 0, equal - cmd);
		if (name_is_valid(name))
		{
			ft_free_null(&name);
			return (1);
		}
		ft_free_null(&name);
	}
	return (0);
}

static int	add_local_var(t_vars *vars, char **cmd_args)
{
	char	*name;
	char	*equal;
	char	*data;
	int		i;

	i = 0;
	while (cmd_args[i])
	{
		equal = ft_strchr(cmd_args[i], '=');
		if (equal && equal - cmd_args[i] > 0)
		{
			name = ft_substr(cmd_args[i], 0, equal - cmd_args[i]);
			data = ft_substr(equal, 1, ft_strlen(equal + 1));
			update_var(&vars->loc, name, data);
			if (does_var_exist(vars->env, name))
				update_var(&vars->env, name, data);
			ft_free_null(&name);
			ft_free_null(&data);
		}
		i++;
	}
	return (0);
}

int	check_assignations(t_vars *vars, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args[i] && is_assignation(cmd->args[i]))
	{
		while (cmd->args[++i])
		{
			if (!is_assignation(cmd->args[i]))
				break ;
		}
		if (!(cmd->args[i]) && vars->segments_count == 1)
		{
			translate_dollars_all(cmd->args, vars);
			add_local_var(vars, cmd->args);
		}	
	}
	return (i);
}

	// i = 0;
	// if (cmd_args[i] && is_assignation(cmd_args[i]))
	// {
	// 	while (cmd_args[++i])
	// 	{
	// 		if (!is_assignation(cmd_args[i]))
	// 			break ;
	// 	}

	// 	translate_dollars_all(cmd_args, vars);
	// 	if (!cmd_args[i] && vars->segments_count == 1)
	// 		return_code = add_local_var(vars, cmd_args);
	// }

int	name_is_valid(char *name)
{
	if (!*name || !ft_isalpha(*name))
		return (0);
	while (*name)
	{
		if (!ft_isalnum(*name))
			return (0);
		name++;
	}
	return (1);
}
