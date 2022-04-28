/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:34:50 by gudias            #+#    #+#             */
/*   Updated: 2022/04/28 18:06:12 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_line(t_vars *vars, char *line)
{
	char	**cmd_args;
	int		i;
	
	//check single quotes

	//check double quotes
	
	//check redirs

	//replace $value

	cmd_args = ft_split(line, ' ');
	if (!cmd_args[0])
		return ;

	add_history(line);
	i = 0;
	if (is_assignation(cmd_args[i]))
	{
		while (cmd_args[++i])
		{
			if (!is_assignation(cmd_args[i]))
				break ;
		}
		if (!cmd_args[i])
			add_local_var(vars, cmd_args);
	}
	if (cmd_args[i] && is_builtin(cmd_args[i]))
		exec_builtin(vars, cmd_args + i);
	else if (cmd_args[i])
		run_cmd(vars, line, 1);  //modif line ---> cmd_args (changer parsing dans exec_cmd)

	//update '$?' ici ?? (besoin de valeur de retour d'exec)
	//pourquoi?
	//$? est une variable du shell, elle se met a jour apres l'execution de qqch
	//peu importe quoi
	//un programme lancer ne doit pas gerer les var de notre shell mais retourne just 
	//son exit status: exit(0); exit(1); return(-1); etc...
	//il faut recuperer cette valeur peu importe ce qu'on a fait et mettre a jour apres
	// (ca me semble plus coherent)
	// 	!!! -->modifier fonction pour qu'elle retourne le code erreur
	
	ft_free_array(cmd_args);
}
