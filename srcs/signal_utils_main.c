/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/19 16:21:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_vars g_vars;

/* ************************************************************************** */
// # define MSG_SIGINT_MAIN	RED"\nminishell> "DEFAULT
# define MSG_SIGINT_MAIN	"\n"
# define MSG_SIGQUIT_MAIN	""
/* ************************************************************************** */
static void init_struc_sa_main(t_sig *s);
static void init_sigaction_main(t_sig *s);

/* ************************************************************************** */
void init_signal_main(t_sig *s)
{
	init_struc_sa_main(s);	
	init_sigaction_main(s);	
}

/* ************************************************************************** */
static void init_struc_sa_main(t_sig *s)
{		
	// SIGINT -----------------------------------------	
	s->sa_sigint.sa_handler = &handler_signal_main;	// SA_HANDLER	
	// sigemptyset(&s->sa_sigint.sa_mask);				// SA_MASK
	// sigaddset(&s->sa_sigint.sa_mask, SIGINT);			// -
	// sigaddset(&s->sa_sigint.sa_mask, SIGQUIT);			// -	
	s->sa_sigint.sa_flags = SA_RESTART;				// SA_FLAG
	
	// SIGQUIT -----------------------------------------	
	s->sa_sigquit.sa_handler = SIG_IGN;
	// s->sa_sigquit.sa_handler = &handler_signal_main;	// SA_HANDLER	
	sigemptyset(&s->sa_sigquit.sa_mask);				// SA_MASK
	sigaddset(&s->sa_sigquit.sa_mask, SIGINT);			// -
	sigaddset(&s->sa_sigquit.sa_mask, SIGQUIT);			// -	
	s->sa_sigquit.sa_flags = SA_RESTART;				// SA_FLAG
	// ------------------------------------------------
}

/* ************************************************************************** */
static void init_sigaction_main(t_sig *s)
{
	// signal(SIGINT, handler_signal_main);	// [ctrl-C]: SIGINT
	// signal(SIGQUIT, SIG_IGN);				// [ctrl-\]: SIGQUIT
		
	sigaction(SIGINT, &s->sa_sigint, NULL);	// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &s->sa_sigquit, NULL);	// [ctrl-\]: SIGQUIT	
}

/* ************************************************************************** */
void	handler_signal_main(int sig_code)
{
	if (sig_code == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("",0);
		rl_on_new_line();
		rl_redisplay();
		
		update_var(&g_vars.loc, "?", "1");
	}
	
	if (sig_code == SIGQUIT)
	{
		write(1, MSG_SIGQUIT_MAIN, ft_strlen(MSG_SIGQUIT_MAIN));
	}
}

/* ************************************************************************** */
