/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:34:00 by pecavalc          #+#    #+#             */
/*   Updated: 2025/10/12 23:32:33 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_parser.h"

//TODO: Remove after implementing build cmd_list

t_cmd	*parse(char *line)
{
	t_token	*token_lst;
	t_cmd	*cmd_lst;

	cmd_lst = NULL;
	token_lst = tokenizer(line);
	if (!token_lst)
		return (NULL);
	if ((check_token_sequence(token_lst) == 0)
		|| check_token_sequence(token_lst) == -1)
		return (NULL);
	return (cmd_lst);
}
