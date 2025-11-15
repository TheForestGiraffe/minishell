/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_run_builtin_in_parent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:52:57 by pecavalc          #+#    #+#             */
/*   Updated: 2025/11/15 19:18:22 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "types.h"
#include "local_execute.h"
#include "builtin.h"

int	run_builtin_in_parent(t_exec_context *exec_context)
{
	int stdin;
	int stdout;

	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	if (stdin == -1 || stdout == -1)
	{
		perror("@run_builtin_in_parent.dup");
		return (-1);
	}
	if (assign_input_output(exec_context->cmd_lst) == -1
		|| search_builtin_functions(exec_context) == -1)
	{
		dup2(stdin, STDIN_FILENO);
		dup2(stdout, STDOUT_FILENO);
		close(stdin);
		close(stdout);
		return (-1);
	}
	return (1);
}
