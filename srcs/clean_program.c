/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:23:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/25 18:26:13 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* ************************************************************************** */
void	clean_program(t_vars *vars)
{
	rl_clear_history();
	free_var_list(&vars->env);
	free_var_list(&vars->loc);
	ft_free_null((void **)&vars->new_line);
}
/* ************************************************************************** */
