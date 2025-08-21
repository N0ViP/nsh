#ifndef	HEREDOC_H
# define HEREDOC_H

#include "nsh.h"

char        *get_tty_name(void);
void        heredoc_mode_signals(void);
char        *heredoc_expander(char *str);
char	    *num_to_str(unsigned long v);
int         open_heredoc(char *delimiter);
bool        create_file(int *wfd, int *rfd);
bool        look_for_heredocs(t_tree *root);
int         process_heredocs(t_tree *branch);
bool        look_for_quotes(char **delimiter);
int         expanded_heredoc_file(int old_rfd);
char        *join_list_strings(t_list_info *info);
bool        write_to_heredoc(int wfd, char *delimiter);
bool        process_line(int wfd, char *line, char *delimiter);
void        write_line_by_line(int wfd, char *buffer, size_t length);
bool        read_file_into_buffer(int old_rfd, char **buffer, size_t *length);
char        *compose_name(char *prefix, char *tty_name, size_t counter, char *sufix);


#endif
