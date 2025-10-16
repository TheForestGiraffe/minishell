/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_add_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:57:06 by pecavalc          #+#    #+#             */
/*   Updated: 2025/10/16 13:06:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_parser.h"

static int	init_argv(t_cmd *cur_cmd, char *word);
static char		**realloc_argv(t_cmd *cur_cmd);
static int	copy_argv_and_add_word(t_cmd *cur_cmd, char **new_argv, char *word);

int	add_word(char *word, t_cmd *cur_cmd)
{
	char	**new_argv;

	if (!word || !cur_cmd)
		return (-1);
	if (!cur_cmd->argv)
	{
		if (init_argv(cur_cmd, word) == -1)
			return (-1);
		return (1);
	}
	new_argv = realloc_argv(cur_cmd);
	if (!new_argv)
		return (-1);
	if (copy_argv_and_add_word(cur_cmd, new_argv, word) == -1)
		return (-1);
	free(cur_cmd->argv);
	cur_cmd->argv = new_argv;
	return (1);
}
static int	init_argv(t_cmd *cur_cmd, char *word)
{
	if (!cur_cmd || !word)
	{
		ft_putstr_fd("@init_argv: NULL input\n", 2);
		return (-1);
	}
	cur_cmd->argv = malloc(sizeof(char *) * 2);
	if (!cur_cmd->argv)
	{
		perror("@init_argv");
		return (-1);
	}
	cur_cmd->argv[1] = NULL;
	cur_cmd->argv[0] = ft_strdup(word);
	if (!cur_cmd->argv[0])
	{
		perror("@init_argv, ft_strdup");
		free(cur_cmd->argv);
		cur_cmd->argv = NULL;
		return (-1);
	}
	return (1);
}

static char **realloc_argv(t_cmd *cur_cmd)
{
	int		i;
	char	**new_argv;

	if (!cur_cmd || !cur_cmd->argv)
	{
		ft_putstr_fd("@realloc_argv: NULL Input\n", 2);
		return (NULL);
	}
	i = 0;
	while (cur_cmd->argv[i])
		i++;
	new_argv = malloc(sizeof(char *) * (i + 2));
	if (!new_argv)
	{
		perror("@realloc_argv");
		return (NULL);
	}
	return (new_argv);
}

static int	copy_argv_and_add_word(t_cmd *cur_cmd, char **new_argv, char *word)
{
	int		i;

	if (!cur_cmd || !cur_cmd->argv || !word)
	{
		ft_putstr_fd("@insert_word: NULL Input\n", 2);
		return (-1);
	}
	i = 0;
	while (cur_cmd->argv[i])
	{
		new_argv[i] = cur_cmd->argv[i];
		i++;
	}
	new_argv[i] = ft_strdup(word);
	if (!new_argv[i])
	{
		free(new_argv);
		return (-1);
	}
	new_argv[++i] = NULL;
	return (1);
}
