/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar_chevron.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:10:05 by ski               #+#    #+#             */
/*   Updated: 2022/05/24 15:38:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
static bool	is_token_chevron_correct(char **array, t_vars *vars);
static bool	is_next_token_correct(char **array, t_vars *vars);

/* ************************************************************************** */
// return NULL if grammar about chevron is not correct
// !!! WARNING !!!: exit the main program if NULL is returned
// -------------------------------------------------
bool	is_grammar_chevron_correct(char *line, t_vars *vars)
{
	char	**array;

	if (!line)
		return (false);
	array = NULL;
	array = split_shell_line(line, ' ');
	translate_dollars_all(array, vars);
	if (!is_token_chevron_correct(array, vars)
		|| !is_next_token_correct(array, vars))
		return (false);
	free_array_null(&array);
	return (true);
}

/* ************************************************************************** */
// chevron token like [ < , << , > , >> ] are correct
// [ <<< , <<<< , ... , >>> , >>>>, ...] are NOT correct
// -------------------------------------------------
static bool	is_token_chevron_correct(char **array, t_vars *vars)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (does_wordstart_match(array[i], "<")
			|| does_wordstart_match(array[i], ">"))
		{
			if (!does_word_match(array[i], "<")
				&& !does_word_match(array[i], "<<")
				&& !does_word_match(array[i], ">")
				&& !does_word_match(array[i], ">>"))
			{
				update_var(&vars->loc, "?", "258");
				ft_printf("minishell: syntax error near token ");
				ft_printf("\'%s\'\n", array[i]);
				return (false);
			}
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */
// chevron token [ < , << , > , >> ] HAVE TO BE FOLLOWED
// by a next_token WITHOUT
//				- [ < ] single or multiple
//				- [ > ] single or multiple
//				- [ | ] single or multiple
// -------------------------------------------------
static bool	is_next_token_correct(char **array, t_vars *vars)
{
	int		i;
	char	*next_token;

	i = 0;
	while (array[i])
	{
		if (does_word_match(array[i], "<") || does_word_match(array[i], "<<")
			|| does_word_match(array[i], ">")
			|| does_word_match(array[i], ">>"))
		{
			next_token = array[i + 1];
			if (!next_token || does_wordstart_match(next_token, "<")
				|| does_wordstart_match(next_token, ">")
				|| does_wordstart_match(next_token, "|"))
			{
				update_var(&vars->loc, "?", "258");
				ft_printf("minishell: syntax error near token ");
				ft_printf("\'%s\'\n", array[i]);
				return (false);
			}
		}		
		i++;
	}
	return (true);
}

/* ************************************************************************** */