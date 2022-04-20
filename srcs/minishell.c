/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:15:58 by gudias            #+#    #+#             */
/*   Updated: 2022/04/20 20:27:54 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <termios.h>

//struct termios saved;

/*void restore(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}*/

static void	init_vars(t_vars *vars)
{
	vars->stdin_fd = dup(0);
	vars->stdout_fd = dup(1);
	vars->stderr_fd = dup(2);
}

int	is_builtin(char *cmd)
{
	const char	*builtins[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

	int i = 0;
	while (builtins[i])
	{
		if (!ft_strncmp(cmd, builtins[i], ft_strlen(builtins[i])))
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 4))
			echo_builtin(cmd+5, ft_strncmp(cmd+5, "-n", 2));
	else if (!ft_strncmp(cmd, "cd", 2))
			(void)cmd;//cd_builtin();		// ski: jai besoin  du path et de l-environnement
	else if (!ft_strncmp(cmd, "pwd", 3))
			pwd_builtin();
	else if (!ft_strncmp(cmd, "export", 6))
			(void)cmd;//export_builtin();
	else if (!ft_strncmp(cmd, "unset", 5))
			(void)cmd;//unset_builtin();
	else if (!ft_strncmp(cmd, "env", 3))
			(void)cmd;//env_builtin();
	else if (!ft_strncmp(cmd, "exit", 4))
			exit_builtin();
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;
	t_vars	vars;
	char	*new_line;

	if (argc > 1)
		exit_msg(ERR_ARGS);
	if (!isatty(0) || !isatty(1) || !isatty(2))
		exit_msg(ERR_TTY);	
	init_vars(&vars);
	init_sa_struc_main(&d);
	init_sigaction_main(&d);

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
			if (is_builtin(new_line))
					exec_builtin(new_line);
			else
				run_cmd(&vars, new_line, envp, 1);
		}
		new_line = NULL;
		free(new_line);
	}	
	//------------------------------------
	return (0);
}
