/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:23:16 by gudias            #+#    #+#             */
/*   Updated: 2022/05/19 14:26:50 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//struct termios saved;

/*void restore(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}*/

	//------------------------------------
	//struct termios attributes;
	//(void)attributes;
	//tcgetattr(STDIN_FILENO, &saved);
	//atexit(restore);
	//tcgetattr(STDIN_FILENO, &attributes);
	//attributes.c_lflag &= ~ ECHO;
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);	
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	//------------------------------------


/* ************************************************************************** */
// typedef unsigned long   tcflag_t;
// typedef unsigned char   cc_t;
void print_termios_attributes(struct termios ta)
{
	printf("\n");
	printf("VEOF     [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VEOF], ta.c_cc[VEOF], ta.c_cc[VEOF]); 
	printf("VEOL     [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VEOL], ta.c_cc[VEOL], ta.c_cc[VEOL]);
	// printf("VEOL2    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VEOL2], ta.c_cc[VEOL2], ta.c_cc[VEOL2]);
	printf("VERASE   [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VERASE], ta.c_cc[VERASE], ta.c_cc[VERASE]);
	// printf("VWERASE  [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VWERASE], ta.c_cc[VWERASE], ta.c_cc[VWERASE]);
	printf("VKILL    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VKILL], ta.c_cc[VKILL], ta.c_cc[VKILL]);
	// printf("VREPRINT [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VREPRINT], ta.c_cc[VREPRINT], ta.c_cc[VREPRINT]);
	printf("VINTR    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VINTR], ta.c_cc[VINTR], ta.c_cc[VINTR]);
	printf("VQUIT    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VQUIT], ta.c_cc[VQUIT], ta.c_cc[VQUIT]);
	printf("VSUSP    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VSUSP], ta.c_cc[VSUSP], ta.c_cc[VSUSP]);
	// printf("VDSUSP   [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VDSUSP], ta.c_cc[VDSUSP], ta.c_cc[VDSUSP]);
	// printf("VSTART   [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VSTART], ta.c_cc[VSTART], ta.c_cc[VSTART]);
	// printf("VSTOP    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VSTOP], ta.c_cc[VSTOP], ta.c_cc[VSTOP]);
	// printf("VLNEXT   [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VLNEXT], ta.c_cc[VLNEXT], ta.c_cc[VLNEXT]);
	// printf("VDISCARD [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VDISCARD], ta.c_cc[VDISCARD], ta.c_cc[VDISCARD]);
	// printf("VMIN     [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VMIN], ta.c_cc[VMIN], ta.c_cc[VMIN]);
	// printf("VTIME    [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VTIME], ta.c_cc[VTIME], ta.c_cc[VTIME]);
	// printf("VSTATUS  [%d]\t[%Xh]\t[octal %o]\n", ta.c_cc[VSTATUS], ta.c_cc[VSTATUS], ta.c_cc[VSTATUS]);
	// printf("NCCS [ %x ] \n", ta.c_cc[NCCS]);
	printf("\n");
}

/* ************************************************************************** */




// #define VEOF            0       /* ICANON */
// #define VEOL            1       /* ICANON */
// #define VEOL2           2       /* ICANON together with IEXTEN */
// #define VERASE          3       /* ICANON */
// #define VWERASE         4       /* ICANON together with IEXTEN */
// #define VKILL           5       /* ICANON */
// #define VREPRINT        6       /* ICANON together with IEXTEN */
// #define VINTR           8       /* ISIG */
// #define VQUIT           9       /* ISIG */
// #define VSUSP           10      /* ISIG */
// #define VDSUSP          11      /* ISIG together with IEXTEN */
// #define VSTART          12      /* IXON, IXOFF */
// #define VSTOP           13      /* IXON, IXOFF */
// #define VLNEXT          14      /* IEXTEN */
// #define VDISCARD        15      /* IEXTEN */
// #define VMIN            16      /* !ICANON */
// #define VTIME           17      /* !ICANON */
// #define VSTATUS         18      /* ICANON together with IEXTEN */
// #define NCCS            20