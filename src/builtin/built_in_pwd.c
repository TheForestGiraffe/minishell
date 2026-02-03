/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:44:01 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/02/04 00:03:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <parser.h>
#include "builtin_private.h"
#include "execute_private.h"
#include "libft.h"

int	builtin_pwd(t_exec_context *ctxt)
{
	char	*text;

	(void)ctxt;
	text = getcwd(NULL, 0);
	if (!text)
	{
		perror ("@pwd:");
		return (-1);
	}
	printf ("%s\n", text);
	free (text);
	return (1);
}
