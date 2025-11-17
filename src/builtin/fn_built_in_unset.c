/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_built_in_II.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:44:07 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/11/06 14:25:18 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "types.h"
#include "libft.h"

// - Validate it's a proper identifier

    // (letters, digits, underscores → but **not** starting with a digit)
    
// - Search your environment list for that key
// - If found → **delete that node**
// - If not found → do nothing (no error)

static int	validate_start_letter(t_token *current)
{
	if ((current->content)[0] != '_' && !ft_isalpha ((current->content)[0]))
	{
		ft_putstr_fd ("@validate_start_letter: Invalid identifier\n", 2);
		return (-1);
	}
	return (1);
}

static int	has_forbidden(t_token *current)
{
	if (ft_strchr (current->content, '='))
		return (1);
	return (0);
}

static int	validate_args(t_token *argv)
{
	t_token	*current;
	
	if (!(argv->next) || !(argv->next->content))
		return (0);
	current = argv->next;
	while (current)
	{
		if (validate_start_letter (current) == -1
			|| has_forbidden (current) == 1)
			return (-1);
		current = current->next; 
	}

	return (1);
}



int	builtin_unset(t_exec_context *ctxt)
{

	if (validate_args (ctxt->cmd_lst->argv) == -1)
		return (-1);



	printf("builtin_unset called\n");
	return (1);
}
