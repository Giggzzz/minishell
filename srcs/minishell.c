/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:15:58 by gudias            #+#    #+#             */
/*   Updated: 2022/04/25 19:21:37 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <termios.h>

//struct termios saved;

/*void restore(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}*/

static void	init_vars(t_vars *vars, char **envp)
{
	vars->stdin_fd = dup(0);
	vars->stdout_fd = dup(1);
	vars->stderr_fd = dup(2);
	vars->env = NULL;
	init_env(vars, envp);
	init_sa_struc_main(&vars->sig);
	init_sigaction_main(&vars->sig);
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	char	*new_line;

	if (argc > 1)
		exit_msg(ERR_ARGS);
	if (!isatty(0) || !isatty(1) || !isatty(2))
		exit_msg(ERR_TTY);

	init_vars(&vars, envp);

	struct termios attributes;
	//tcgetattr(STDIN_FILENO, &saved);
	//atexit(restore);
	//tcgetattr(STDIN_FILENO, &attributes);
	//attributes.c_lflag &= ~ ECHO;
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	ft_putendl("HELLO MINISHELL");
	//------------------------------------
	while(1)
	{
		new_line = readline("minishell> ");
		if (new_line)
		{
			add_history(new_line);
			parse_line(&vars, new_line);
		}
		new_line = NULL;
		free(new_line);
	}	
	//------------------------------------
	return (0);
}

