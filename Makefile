CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
LIB		=	-lreadline
INCLUDE	=	./includes
SOURCE	=	sources/nsh.c	utils/add_node_back.c	utils/ft_substr.c		\
			stdfcts/ft_isspace.c	utils/skip_spaces.c						\
			tokenization/free_token.c	utils/creat_node.c					\
			tokenization/tokenization.c  utils/free_list.c
NAME	=	nsh
OBJS	=	$(SOURCE:.c=.o)

all: $(NAME)

%.o:%.c	$(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE) $(LIB)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re