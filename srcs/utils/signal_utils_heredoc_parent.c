/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils_heredoc_parent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/13 00:13:11 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
static void init_struct_sa_heredoc_parent(t_sig *s);
static void init_sigaction_heredoc_parent(t_sig *s);
/* ************************************************************************** */
void init_signal_heredoc_parent(t_sig *s)
{
	init_struct_sa_heredoc_parent(s);
	init_sigaction_heredoc_parent(s);	
}

/* ************************************************************************** */
static void init_struct_sa_heredoc_parent(t_sig *s)
{
	// SIGINT -----------------------------------------	
	s->sa_sigint_main.sa_handler = &handler_signal_heredoc_parent;	// SA_HANDLER	
	sigemptyset(&s->sa_sigint_main.sa_mask);				// SA_MASK
	sigaddset(&s->sa_sigint_main.sa_mask, SIGINT);			// -
	sigaddset(&s->sa_sigint_main.sa_mask, SIGQUIT);			// -	
	s->sa_sigint_main.sa_flags = SA_RESTART;				// SA_FLAG
	
	// SIGQUIT -----------------------------------------	
	s->sa_sigquit_main.sa_handler = SIG_IGN;
	// ------------------------------------------------
}

/* ************************************************************************** */
static void init_sigaction_heredoc_parent(t_sig *s)
{
	sigaction(SIGINT, &s->sa_sigint_main, NULL);	// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &s->sa_sigquit_main, NULL);	// [ctrl-\]: SIGQUIT	
}

/* ************************************************************************** */
void	handler_signal_heredoc_parent(int sig_code)
{
	if (sig_code == SIGINT)
	{
		ft_printf(MSG_SIGINT_HEREDOC_PARENT);
		// update_var(&vars->loc, "?", 1);
	}
	
	if (sig_code == SIGQUIT)
		ft_printf(MSG_SIGQUIT_HEREDOC_PARENT);
}

/* ************************************************************************** */