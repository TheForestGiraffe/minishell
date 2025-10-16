

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_list_pipeline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:10:00 by pecavalc          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:00 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "local_parser.h"
#include "libft.h"
#include <stdio.h>

void test(char *description, char *line, char ***expected_cmds, int *res);
void print_result(int ok, char *description);
static int verify_cmd_list(t_cmd *cmd_list, char ***expected_cmds);

int main(void)
{
    int res = 1;

    char *pipeline1_cmd1[] = {"ls", "-l", NULL};
    char *pipeline1_cmd2[] = {"grep", "main", NULL};
    char **pipeline1[] = {pipeline1_cmd1, pipeline1_cmd2, NULL};

    test("Pipeline: ls -l | grep main", "ls -l | grep main", pipeline1, &res);

    char *pipeline2_cmd1[] = {"echo", "hello", "world", NULL};
    char **pipeline2[] = {pipeline2_cmd1, NULL};

    test("Single command: echo hello world", "echo hello world", pipeline2, &res);

    char *pipeline3_cmd1[] = {"cat", NULL};
    char *pipeline3_cmd2[] = {"wc", "-l", NULL};
    char **pipeline3[] = {pipeline3_cmd1, pipeline3_cmd2, NULL};

    test("Pipeline with simple pipe: cat | wc -l", "cat | wc -l", pipeline3, &res);

    if (res == 1)
        printf("\ntest_cmd_list_pipeline: [OK]\n\n");
    else
        printf("\ntest_cmd_list_pipeline: [NOK]\n\n");

    return 0;
}

void test(char *description, char *line, char ***expected_cmds, int *res)
{
    t_cmd *cmd_list;

    cmd_list = parse(line);
    if (!cmd_list)
    {
        print_result(0, description);
        *res = -1;
        return;
    }

    if (verify_cmd_list(cmd_list, expected_cmds))
        print_result(1, description);
    else
    {
        print_result(0, description);
        *res = 0;
    }

    cmd_lst_delete_list(&cmd_list); // cleanup
}

static int verify_cmd_list(t_cmd *cmd_list, char ***expected_cmds)
{
    int i = 0;
    t_cmd *cur = cmd_list;

    while (cur && expected_cmds[i])
    {
        int j = 0;
        while (cur->argv[j] && expected_cmds[i][j])
        {
            if (ft_strncmp(cur->argv[j], expected_cmds[i][j],
                           ft_strlen(expected_cmds[i][j]) + 1) != 0)
                return 0;
            j++;
        }
        if (cur->argv[j] != NULL || expected_cmds[i][j] != NULL)
            return 0; // mismatch in number of arguments
        cur = cur->next;
        i++;
    }

    if (cur != NULL || expected_cmds[i] != NULL) // mismatch in number of commands
        return 0;

    return 1;
}

void print_result(int ok, char *description)
{
    if (ok)
        printf("%-50s [OK]\n", description);
    else
        printf("%-50s [NOK]\n", description);
}
