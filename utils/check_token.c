#include "utils.h"

enum operator	check_token(char *token)
{
	enum operator	type;

	if (token[0] == '|' && token[1] == '|')
	{
		type = OR;
	}
	else if (token[0] == '&' && token[1] == '&')
	{
		type = AND;
	}
	else if (token[0] == '<' && token[1] == '<')
	{
		type = HEREDOC;
	}
	else if (token[0] == '>' && token[1] == '>')
	{
		type = APPEND_REDIRECTION;
	}
	else if (token[0] == '|')
	{
		type = PIPE;
	}
	else if (token[0] == '>')
	{
		type = REDIRECTION;
	}
	else if (token[0] == '<')
	{
		type = INPUT_REDIRECTION;
	}
	else
	{
		type = WORD;
	}
	return (type);
}
