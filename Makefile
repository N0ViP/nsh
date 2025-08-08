CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
LIB		=	-lreadline
INCLUDE	=	./includes

MAIN_SRC = \
    sources/nsh.c \
    sources/printer_to_rm.c

UTILS_SRC = \
    utils/check_if_match.c  utils/init_list_info_struct.c  utils/skip_spaces.c \
    utils/check_token.c     utils/join_list.c              utils/smalloc.c  \
    utils/creat_node.c      utils/join_two_strings.c \
    utils/free.c            utils/list_add_back.c

STDFCTS_SRC = \
    stdfcts/ft_isalnum.c  stdfcts/ft_memcpy.c   stdfcts/ft_strcat.c   stdfcts/ft_strlen.c \
    stdfcts/ft_isalpha.c  stdfcts/ft_min.c      stdfcts/ft_strchr.c   stdfcts/ft_strndup.c \
    stdfcts/ft_isdigit.c  stdfcts/ft_realloc.c  stdfcts/ft_strcmp.c   stdfcts/ft_substr.c \
    stdfcts/ft_isspace.c  stdfcts/ft_split.c    stdfcts/ft_strjoin.c

TOKEN_SRC = \
    tokenization/free_token.c \
    tokenization/tokenization.c

PARSER_SRC = \
    parser/parse_tree.c \
    parser/error_check.c \
    parser/extract_redirs.c \
    parser/op_subsh.c \
    parser/print_error.c \
    parser/simple_cmd.c

EXEC_SRC = \
    execution/execute.c \
    execution/command.c \
    execution/pipeline.c \
    execution/bonus_logic.c \
    execution/redirection.c \
    execution/path.c \
    execution/error.c

SOURCE = $(MAIN_SRC) \
         $(UTILS_SRC) \
         $(STDFCTS_SRC) \
         $(TOKEN_SRC) \
         $(PARSER_SRC) \
         $(EXEC_SRC)

NAME	=	nsh
OBJS	=	$(SOURCE:.c=.o)

all: $(NAME)

%.o:%.c	$(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re