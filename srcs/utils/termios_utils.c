/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:59:25 by ski               #+#    #+#             */
/*   Updated: 2022/05/18 14:03:53 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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

	printf("ECHOKE		[%lu]\n", ta.c_lflag & ECHOKE);  
	printf("ECHOE		[%lu]\n", ta.c_lflag & ECHOE);  
	printf("ECHOK		[%lu]\n", ta.c_lflag & ECHOK);  
	printf("ECHO		[%lu]\n", ta.c_lflag & ECHO);	
	printf("ECHONL		[%lu]\n", ta.c_lflag & ECHONL);
	printf("ECHOPRT		[%lu]\n", ta.c_lflag & ECHOPRT);  
	printf("ECHOCTL		[%lu]\n", ta.c_lflag & ECHOCTL);  
	printf("ISIG 		[%lu]\n", ta.c_lflag & ISIG);  	
	printf("ICANON 		[%lu]\n", ta.c_lflag & ICANON);  
	printf("ALTWERASE	[%lu]\n", ta.c_lflag & ALTWERASE);  
	printf("IEXTEN 		[%lu]\n", ta.c_lflag & IEXTEN);  
	printf("EXTPROC 	[%lu]\n", ta.c_lflag & EXTPROC);  	
	printf("TOSTOP 		[%lu]\n", ta.c_lflag & TOSTOP);  
	printf("FLUSHO 		[%lu]\n", ta.c_lflag & FLUSHO);  
	printf("NOKERNINFO 	[%lu]\n", ta.c_lflag & NOKERNINFO);	 
	printf("PENDIN     	[%lu]\n", ta.c_lflag & PENDIN); 	
	printf("NOFLSH     	[%lu]\n", ta.c_lflag & NOFLSH); 

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


// #define ECHOKE          0x00000001      /* visual erase for line kill */
// #define ECHOE           0x00000002      /* visually erase chars */
// #define ECHOK           0x00000004      /* echo NL after line kill */
// #define ECHO            0x00000008      /* enable echoing */
// #define ECHONL          0x00000010      /* echo NL even if ECHO is off */
// #define ECHOPRT         0x00000020      /* visual erase mode for hardcopy */
// #define ECHOCTL         0x00000040      /* echo control chars as ^(Char) */
// #define ISIG            0x00000080      /* enable signals INTR, QUIT, [D]SUSP */
// #define ICANON          0x00000100      /* canonicalize input lines */
// #define ALTWERASE       0x00000200      /* use alternate WERASE algorithm */
// #define IEXTEN          0x00000400      /* enable DISCARD and LNEXT */
// #define EXTPROC         0x00000800      /* external processing */
// #define TOSTOP          0x00400000      /* stop background jobs from output */
// #define FLUSHO          0x00800000      /* output being flushed (state) */
// #define NOKERNINFO      0x02000000      /* no kernel output from VSTATUS */
// #define PENDIN          0x20000000      /* XXX retype pending input (state) */
// #define NOFLSH          0x80000000      /* don't flush after interrupt */

// fd
// Indicates an open file descriptor associated with a terminal.

// when
// Indicates a symbol, defined in the termios.h header file, specifying when to change the terminal attributes:

// TCSANOW
// The change should take place immediately.

// TCSADRAIN
// The change should take place after all output written to fd has been read by the master pseudoterminal.
// Use this value when changing terminal attributes that affect output.

// TCSAFLUSH
// The change should take place after all output written to fd has been sent;
// in addition, all input that has been received but not read should be discarded (flushed) before the change is made.