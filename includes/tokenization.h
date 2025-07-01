#ifndef TOKENIZATION_H
# define TOKENIZATION_H

t_tokens	*tokenize(char *cmd);
void		free_tokens(t_tokens *tokens);

#endif