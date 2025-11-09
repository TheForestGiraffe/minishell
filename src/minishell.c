/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:54:30 by plima             #+#    #+#             */
/*   Updated: 2025/11/09 16:30:45 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "signals.h"
#include "parser.h"
#include "execute.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	read_parse_and_execute(char **envp);

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	register_signals();
	while (1)
	{
		if (read_parse_and_execute(envp))
			break ;
	}
	rl_clear_history();
	return (0);
}

static int	read_parse_and_execute(char **envp)
{
	char			*line;
	t_exec_context	*exec_context;

	exec_context = malloc (sizeof (t_exec_context));
	if (!exec_context)
	{
		perror ("@read_parse_and_execute.malloc: ");
		return (-1);
	}
	exec_context->envp = envp;
	exec_context->exit_state = NULL;
	exec_context->cmd_lst = NULL;
	line = readline("minishell$ ");
	if (!line)
	{
		ft_putstr_fd("exit\n", 1);
		return (1);
	}
	if (*line)
	{
		add_history(line);
		exec_context->cmd_lst = parse(line, envp);
		if (exec_context->cmd_lst)
			execute(exec_context);
	}
	free(line);
	return (0);
}
// make types .h file