# include "nsh.h"

// redirections parse errors
//wtf ((ls | cat)<<d)

bool parse_check(t_list *tokens)
{
    int depth = 0;
    char *op_found = NULL;
    t_token *prev = NULL;
    while (tokens)
    {
        t_token *curr = (t_token*)tokens->content;
        if (curr->type == OP_OPEN_PARENTHESE)
        {
            depth++;
            if (!tokens->next)
            {
                parse_error("(");
                return false;
            }
            if(prev)
            {
                if (!(prev->type >= OP_OR && prev->type <= OP_PIPE) && prev->type != OP_OPEN_PARENTHESE)
                {
                    parse_error("(");
                    return false;
                }
            }
            t_token *next = (t_token *)tokens->next->content;
            if ((next->type >= OP_OR && next->type <= OP_REDIR_IN)
                || next->type == OP_CLOSED_PARENTHESE
                || (prev && prev->type == WORD))
            {
                parse_error(next->value);
                return false;
            }
        }
        else if (curr->type == OP_CLOSED_PARENTHESE)
        {
            if (depth == 0)
            {
                parse_error(curr->value);
                return false;
            }
            if (tokens->next)
            {
                t_token *next = (t_token *)tokens->next->content;
                if ((!(next->type >= OP_OR && next->type <= OP_REDIR_IN)
                    && next->type != OP_CLOSED_PARENTHESE))
                {
                    parse_error(next->value);
                    return false;
                }
            }
            if (!prev || prev->type >= OP_OR && prev->type <= OP_REDIR_IN)
            {
                parse_error(curr->value);
                return false;
            }
            depth--;
        }
        else if (curr->type >= OP_OR && curr->type <= OP_PIPE)
        {
            if(!tokens->next || !prev)
            {
                parse_error(curr->value);
                return false;
            }
            if (prev->type >= OP_OR && prev->type <= OP_REDIR_IN)
            {
                parse_error(prev->value);
                return false;
            }
        }
        prev = curr;
        tokens = tokens->next;
    }
    if (depth > 0)
    {
        parse_error("(");
        return false;
    }
    return true;
}
