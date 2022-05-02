/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:05:59 by gudias            #+#    #+#             */
/*   Updated: 2022/05/02 12:51:53 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
static void copy_parent_env(t_env **child_env, char **parent_env)
{
	char	*name;
	char	*data;
	int		len;

	while (*parent_env)
	{
		len = ft_strchr(*parent_env, '=') - *parent_env;
		name = ft_substr(*parent_env, 0, len);
		data = ft_substr(*parent_env, len + 1, ft_strlen(*parent_env));
		add_var(child_env, name, data);
		ft_free_null((void**)&name);
		ft_free_null((void**)&data);
		parent_env++;
	}
}

/* ************************************************************************** */
void	init_env(t_vars *vars, char **envp)
{
	t_env	*temp;

	copy_parent_env(&vars->env, envp);
	
	// Update: SHLVL
	temp = get_var(vars->env, "SHLVL");
	temp->data = ft_itoa(ft_atoi(temp->data) + 1);

	// AJOUTER le path de [./minishell] dans la variable d'environnement $PATH
	
	update_var(&vars->env, "OLDPWD", "/"); //a reflechir
	//assurer que PATH, HOME, PWD, OLDPWD, SHLVL SONT PRESENTS
	//sinon -> les ajouter
	
}

/* ************************************************************************** */
void	env_builtin(t_vars *vars)
{
	print_var(vars->env);
}

/* ************************************************************************** */
void	loc_builtin(t_vars *vars)
{
	print_var(vars->loc);
}

/* ************************************************************************** */