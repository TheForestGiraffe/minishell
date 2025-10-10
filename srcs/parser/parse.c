/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:34:00 by pecavalc          #+#    #+#             */
/*   Updated: 2025/10/10 17:50:29 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_parser.h"

t_cmd	*parse(char *line)
{
	t_token	*token_lst;
	t_cmd	*cmd_lst;

	token_lst = tokenize(line);
	if (!token_lst)
		return (NULL);
	if (validate_syntax(token_lst) == -1)
		return (NULL);
	return (cmd_lst);
}

// Create files within the parser (?)