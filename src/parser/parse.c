/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:34:00 by pecavalc          #+#    #+#             */
/*   Updated: 2025/11/10 18:25:58 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_parser.h"
#include <stddef.h>

t_cmd	*parse(char *line, char **envp)
{
	t_token	*token_lst;
	t_cmd	*cmd_lst;

	token_lst = tokenizer(line);
	if (!token_lst)
		return (NULL);
	if ((check_token_sequence(token_lst) == 0)
		|| check_token_sequence(token_lst) == -1
		|| expand_tokens(token_lst, envp) == -1)
	{
		tls_delete_list (&token_lst);
		return (NULL);
	}
	cmd_lst = build_cmd_lst(token_lst, envp);
	if (!cmd_lst)
	{
		tls_delete_list (&token_lst);
		return (NULL);
	}
	tls_delete_list (&token_lst);
	return (cmd_lst);
}
