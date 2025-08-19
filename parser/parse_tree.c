# include "nsh.h"

t_tree	*parse_in_tree(t_list *tokens)
{
	t_tree	*root;

	set_current_section(GLOBALE);
	root = parse_tokens(tokens);
	destroy_section(TOKENIZE);
	return (root);
}
