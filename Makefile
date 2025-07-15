CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
LIB		=	-lreadline
INCLUDE	=	./includes
SOURCE = \
			sources/nsh.c \
			utils/list_add_back.c \
			utils/ft_substr.c \
			stdfcts/ft_isspace.c \
			stdfcts/ft_strlen.c \
			stdfcts/ft_strjoin.c \
			stdfcts/ft_split.c \
			utils/check_token.c \
			utils/ft_strchr.c \
			tokenization/free_token.c \
			tokenization/tokenization.c \
			utils/creat_node.c \
			utils/free_list.c \
			utils/skip_spaces.c \
			utils/smalloc.c \
			parser/parse_tree.c \
			parser/error_check.c \
			parser/extract_redirs.c \
			parser/op_subsh.c \
			parser/print_error.c \
			parser/simple_cmd.c \
			execution/execute.c \
			sources/printer_to_rm.c
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