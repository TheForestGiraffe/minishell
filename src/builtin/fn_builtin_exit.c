/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:13:04 by pecavalc          #+#    #+#             */
/*   Updated: 2025/11/13 20:41:15 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "local_builtin.h"
#include "types.h"
#include <stdlib.h>

int	builtin_exit(t_exec_context *ctxt)
{
	(void)ctxt;
	// int		ret;
	// int		nr_args;
	// t_cmd	*cur_arg;

	// if (!ctxt || !ctxt->cmd_lst)
	// 	exit(EXIT_FAILURE);
	// nr_args = 0;
	// while (ctxt->cmd_lst->argv->next)
	// {
	// 	cur_arg = ctxt->cmd_lst->argv->next;
	// 	nr_args++;
	// }
	// if (ctxt->there_is_one_cmd_and_is_builtin_exit)
	// 	ft_printf("exit\n");
	// if (nr_args == 0)
	// 	exit(ctxt->exit_state);
	// else if (nr_args == 1)
	// {
	// 	ret = ft_strtol(ctxt->cmd_lst->argv->next, ctxt->exit_state);
	// 	if (ret == -1)
	// 	{
	// 		ft_printf("exit: %s: numeric argument required\n",
	// 			ctxt->cmd_lst->argv->next);
	// 		exit(2);
	// 	}
	// 	exit(ctxt->exit_state);
	// }
	// else
	// {
	// 	ft_printf("exit: too many arguments\n");
	// 	exit(1);
	// }
	return (1);
}
