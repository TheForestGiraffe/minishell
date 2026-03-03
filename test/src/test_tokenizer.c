#include "parser_private.h"
#include <stdio.h>
#include <string.h>

#define PAD_WIDTH 55

typedef struct s_case {
	const char	*desc;
	char		*input;
	int			expect_ok; /* 1 = should succeed, 0 = should fail */
}	t_case;

static void	print_status(const char *label, int ok)
{
	int len = (int)strlen(label);

	printf("%s", label);
	if (len < PAD_WIDTH)
		printf("%*s", PAD_WIDTH - len, "");
	printf("[%s]\n", ok ? "OK" : "KO");
}

static int	run_case(const t_case *tc)
{
	t_token	*lst;
	int		got_ok;
	int		ok;

	lst = tokenizer(tc->input);
	got_ok = (lst != NULL);

	ok = (got_ok == tc->expect_ok);

	print_status(tc->desc, ok);

	if (lst)
		tls_delete_list(&lst);

	return ok;
}

int	main(void)
{
	t_case	tests[] = {
		{ "Single space", " ", 0 },
		{ "Empty string", "", 0},
		{ "Redir then quoted heredoc", "   <'<<'       ", 1 },
		{ "Mixed long input",
		  "       the \"Weather\"   is | very co<ld but it is not cold>>er 'than this' yester<<day", 1 },
		{ "Pipe inside quotes",
		  "this is a 'tom|ato' but \"falafel is better\" than nothi|ng at all", 1 },
		{ "Adjacent quote blocks", "echo 'hi'\"there\"", 1 },
		{ "No-space quotes", "echo'a'", 1 },
		{ "Messy quoted words", "         kh\"a abc\"kaka\"     samba\"", 1 },
		{ "Empty quotes", "''", 1 },
		{ "NULL input", NULL, 0 },
		{ "Single quote only", "'", 0 },
	};

	int failures = 0;
	size_t i;

	for (i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
		if (!run_case(&tests[i]))
			failures++;

	if (failures)
	{
		printf("test_build_cmd_lst: [KO]\n");
		return (1);
	}
	printf("test_build_cmd_lst: [OK]\n");
	return (0);
}