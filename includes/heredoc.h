#ifndef	HEREDOC_H
# define HEREDOC_H

#include "nsh.h"

extern int  heredoc_exit; // is it allowed

char        *get_tty_name(void);
void        heredoc_signals(void);
char	    *num_to_str(unsigned long v);
int         open_heredoc(char *delimiter);
bool        look_for_heredocs(t_tree *root);
int         process_heredocs(t_tree *branch);
bool        look_for_quotes(char **delimiter);
char        *join_list_strings(t_list_info *info);
bool        write_to_heredoc(int wfd, char *delimiter);
void        joine_string(t_list  *node, char *to_fill, size_t total);
bool        process_line(int wfd, char *line, bool was_quoted, char *delimiter);
char        *compose_name(char *prefix, char *tty_name, size_t counter, char *sufix);


#endif
