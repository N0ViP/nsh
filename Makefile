CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
LIB		=	-lreadline
INCLUDE	=	./includes

MAIN_SRC = \
    sources/main.c \
    sources/read_cmd.c \
    sources/new_shell.c \
    sources/signal_setup.c \
    # sources/printer_to_rm.c

HEREDOC_SRC = \
    heredoc/heredoc.c 

ALLOC_SRC = \
    allocation/smalloc.c \
    allocation/clear_data.c \
    allocation/destroy_all.c \
    allocation/find_sections.c \
    allocation/add_allocation.c \
    allocation/new_allocation.c \
    allocation/create_section.c \
    allocation/destroy_section.c \
    allocation/free_one_pointer.c \
    allocation/clean_before_prompt.c

BUILT_SRC = \
    built_in/env.c \
    built_in/echo.c \
    built_in/exit.c \
    built_in/unset.c \
    built_in/export.c

EXPAND_SRC = \
    expansion/expand.c \
    expansion/check_if_dollar.c \
    expansion/expand_wildcard.c \
    expansion/expansion_utils.c \
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
    getenv/create_env_arr.c \
    getenv/remove_from_env.c

UTILS_SRC = \
    utils/free.c \
    utils/join_list.c \
    utils/creat_node.c \
    utils/lst_to_arr.c \
    utils/check_token.c \
    utils/skip_spaces.c \
    utils/list_add_back.c \
    utils/check_if_match.c \
    utils/join_two_strings.c \
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
    execution/built_ins_check.c \
    execution/expand_cmd_args.c \
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

NAME	=	nsh
OBJS	=	$(SOURCE:.c=.o)

all: $(NAME)

%.o:%.c	$(INCLUDE)  ##
	$(CC) $(CFLAGS) -c $< -o $@ -I/usr/local/opt/readline/include -I $(INCLUDE) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L/usr/local/opt/readline/lib $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re