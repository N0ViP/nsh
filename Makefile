CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LIB		=	-lreadline
INCLUDE	=	./includes
NAME	=	minishell

MAIN_SRC = \
    sources/main.c \
    sources/read_cmd.c \
    sources/new_shell.c \
    sources/exit_shell.c \
    sources/signal_setup.c \
    sources/more_signals.c

HEREDOC_SRC = \
    heredoc/num_to_str.c \
    heredoc/open_heredoc.c \
    heredoc/process_line.c \
    heredoc/compose_name.c \
    heredoc/expand_heredoc.c \
    heredoc/look_for_quotes.c \
    heredoc/heredoc_expander.c \
    heredoc/process_heredocs.c \
    heredoc/write_to_heredoc.c \
    heredoc/write_and_expand.c \
    heredoc/join_list_strings.c \
    heredoc/look_for_heredocs.c \
    heredoc/read_file_into_buffer.c

ALLOC_SRC = \
    mem_track/smalloc.c \
    mem_track/close_fds.c \
    mem_track/clear_data.c \
    mem_track/destroy_all.c \
    mem_track/fds_tracker.c \
    mem_track/find_sections.c \
    mem_track/add_allocation.c \
    mem_track/new_allocation.c \
    mem_track/create_section.c \
    mem_track/current_section.c \
    mem_track/destroy_section.c \
    mem_track/free_one_pointer.c \
    mem_track/track_open_files.c \
    mem_track/clean_before_prompt.c

BUILT_SRC = \
    built_in/cd.c \
    built_in/env.c \
    built_in/pwd.c \
    built_in/echo.c \
    built_in/exit.c \
    built_in/unset.c \
    built_in/export.c \
    built_in/cd_helper.c \
    built_in/update_cwd.c \
    built_in/iam_a_child.c \
    built_in/exit_helper.c \
    built_in/run_built_in.c \
    built_in/built_in_check.c

EXPAND_SRC = \
    expansion/expand.c \
    expansion/process_arg.c \
    expansion/word_spliting.c \
    expansion/match_wildcard.c \
    expansion/wildcard_offset.c \
    expansion/expansion_utils.c \
    expansion/check_if_dollar.c \
    expansion/init_info_struct.c \
    expansion/get_wildcard_flag.c \
    expansion/expand_dollar_word.c \
    expansion/expand_regular_word.c \
    expansion/regular_word_checker.c \
    expansion/double_quotes_checker.c \
    expansion/add_in_wildcard_hashmap.c \
    expansion/expand_single_quote_word.c \
    expansion/expand_double_quotes_word.c

GETENV_SRC = \
    getenv/getenv.c \
    getenv/init_env.c \
    getenv/add_in_env.c \
    getenv/ft_strcmp_env.c \
    getenv/get_var_value.c \
    getenv/set_var_value.c \
    getenv/remove_from_env.c

UTILS_SRC = \
    utils/join_list.c \
    utils/creat_node.c \
    utils/lst_to_arr.c \
    utils/check_token.c \
    utils/skip_spaces.c \
    utils/list_add_back.c \
    utils/check_if_match.c \
    utils/join_two_strings.c \
    utils/join_list_content.c \
    utils/init_list_info_struct.c \
    utils/re_init_list_info_struct.c

STDFCTS_SRC = \
    stdfcts/ft_min.c \
    stdfcts/ft_abs.c \
    stdfcts/ft_itoa.c \
    stdfcts/ft_split.c \
    stdfcts/ft_numlen.c \
    stdfcts/ft_substr.c \
    stdfcts/ft_strcmp.c \
    stdfcts/ft_strchr.c \
    stdfcts/ft_memcpy.c \
    stdfcts/ft_strcat.c \
    stdfcts/ft_strlen.c \
    stdfcts/ft_strrchr.c \
    stdfcts/ft_isspace.c \
    stdfcts/ft_strjoin.c \
    stdfcts/ft_isalnum.c \
    stdfcts/ft_isalpha.c \
    stdfcts/ft_strndup.c \
    stdfcts/ft_isdigit.c \
    stdfcts/ft_realloc.c

TOKEN_SRC = \
    tokenization/tokenization.c

PARSER_SRC = \
    parser/op_subsh.c \
    parser/simple_cmd.c \
    parser/parse_tree.c \
    parser/print_error.c \
    parser/error_check.c \
    parser/parse_tokens.c \
    parser/extract_redirs.c

EXEC_SRC = \
    execution/error.c \
    execution/or_and.c \
    execution/command.c \
    execution/execute.c \
    execution/subshell.c \
    execution/pipeline.c \
    execution/fork_before.c \
    execution/path_errors.c \
    execution/redirection.c \
    execution/exit_status.c \
    execution/check_curr_dir.c \
    execution/path_resolution.c \
    execution/search_in_paths.c \
    execution/right_left_pipe.c \
    execution/expand_cmd_args.c \
    execution/redirect_to_file.c \
    execution/expand_filenames.c

SOURCE = $(MAIN_SRC) \
         $(EXEC_SRC) \
         $(UTILS_SRC) \
         $(TOKEN_SRC) \
         $(BUILT_SRC) \
         $(ALLOC_SRC) \
         $(PARSER_SRC) \
         $(EXPAND_SRC) \
         $(GETENV_SRC) \
         $(HEREDOC_SRC) \
         $(STDFCTS_SRC)

OBJS	=	$(SOURCE:.c=.o)

all: $(NAME)

%.o:%.c	$(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
