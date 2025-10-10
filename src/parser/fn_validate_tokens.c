/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_validate_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:17:15 by pecavalc          #+#    #+#             */
/*   Updated: 2025/10/10 20:07:38 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "local_parser.h"

static int validate_vertical_bars(t_token *curr_token, t_token *token_lst);

int	validate_tokens(t_token *token_lst)
{
	t_token	*curr_token;

	if (!token_lst)
		return (-1);
	curr_token = token_lst;
	while (curr_token)
	{
		if (validate_vertical_bars(curr_token, token_lst) == -1)
			return (-1);
		curr_token = curr_token->next;
	}
	return (0);
}

/*	Validate vertical bars:
*	1. Check if the pipe opeartor | is the first character -> error
*	2. Check if two or more | exist -> OR and multiple pipes are not supported
*	3. Check if the last character is a pipe -> error
*/
static int validate_vertical_bars(t_token *curr_token, t_token *token_lst) 
{
	if ((curr_token == token_lst) && (curr_token->type == PIPE))
	{
		ft_putstr_fd("minishell: syntax error near token '|'\n", 2);
		return (-1);
	}
	if ((curr_token->type == PIPE) && (curr_token->next))
	{
		if (curr_token->next->type == PIPE)
		{
			ft_putstr_fd("minishel: syntax error near token '|'\n", 2);
			return (-1);
		}
	}
	if ((curr_token->type == PIPE) && (!curr_token->next))
	{
		ft_putstr_fd("minishel: syntax error near token '|'\n", 2);
		return (-1);
	}
	return (0);
}
