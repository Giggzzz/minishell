/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:13 by ski               #+#    #+#             */
/*   Updated: 2022/04/25 16:50:42 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* ************************************************************************** */
void replace_env_pwd(t_env **ptr_env, char *new_path)
{
	update_var(ptr_env, "PWD", new_path);
}

/* ************************************************************************** */
void replace_env_oldpwd(t_env **ptr_env, char *new_path)
{
	update_var(ptr_env, "OLDPWD", new_path);
}

/* ************************************************************************** */