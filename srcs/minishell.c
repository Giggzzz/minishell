/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:15:58 by gudias            #+#    #+#             */
/*   Updated: 2022/05/17 11:17:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

//struct termios saved;

/*void restore(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}*/

t_vars	vars;
/* ************************************************************************** */
int	main(int argc, char **argv, char **envp)
{
	char	*new_line;
	char	**segments;
	int		i;

	//------------------------------------
	(void)argv;
	if (argc > 1)
		exit_msg(ERR_ARGS);
	if (!isatty(0) || !isatty(1) || !isatty(2))
		exit_msg(ERR_TTY);
	
	initialisation (&vars, envp);
	
	//------------------------------------
	struct termios attributes;
	(void)attributes;
	//tcgetattr(STDIN_FILENO, &saved);
	//atexit(restore);
	//tcgetattr(STDIN_FILENO, &attributes);
	//attributes.c_lflag &= ~ ECHO;
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);	
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	//------------------------------------

	launch_message();

	new_line = NULL;
	while (1)
	{
		new_line = show_prompt(&vars);

		if (new_line && *new_line)
		{
			add_history(new_line);	
			if (is_grammar_correct(new_line, &vars))
			{	
				new_line = chevron_space_maker(new_line);
				new_line = pipeline_space_maker(new_line);
				segments = split_shell_line(new_line, '|');
				
				i = -1;
				while (segments[++i])
					vars.segments_count++;
						
				i = 0;
				while (segments[i + 1])
					parse_line(&vars, segments[i++], 0);
				parse_line(&vars, segments[i], 1);
				
				vars.segments_count = 0;	
				ft_free_array(segments);	
			}						
		}

		ft_free_null((void**)&new_line);
	}	
	//------------------------------------
	// free les variables d'environnement
	// free les variables locales
	//------------------------------------
	return (0);
}

/* ************************************************************************** */
