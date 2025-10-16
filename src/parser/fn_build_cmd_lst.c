/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_build_cmd_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:57:06 by pecavalc          #+#    #+#             */
/*   Updated: 2025/10/16 13:20:30 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_parser.h"

t_cmd	*build_cmd_lst(t_token *token_lst)
{
	t_cmd *cmd_lst;
	t_cmd *cur_cmd;

	if (!token_lst)
		return (NULL);
	cmd_lst = NULL;
	cur_cmd = cmd_lst_create();
	if (!cur_cmd)
		return (NULL);
	if (cmd_lst_add_back(&cmd_lst, cur_cmd) == -1)
		return (NULL);
	while (token_lst)
	{
		if (token_lst->type == WORD)
		{
			if (add_word(token_lst->content, cur_cmd) == -1)
			{
				cmd_lst_delete_list(&cmd_lst);
				return (NULL);
			}
		}
		
		// To be continued here.

		token_lst = token_lst->next;
	}
	return (cmd_lst);
}
