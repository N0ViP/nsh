# include "nsh.h"

t_tree	*parse_in_tree(t_list *tokens)
{
	t_tree	*root;

	root = parse_tokens(tokens);
	destroy_section(TOKENIZATION);
	return (root);
}
