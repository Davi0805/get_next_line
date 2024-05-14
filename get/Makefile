NAME = get_next_line.a
CC = gcc
INCLUDE = get_next_line.h
FLAGS = -Wall -Wextra -Werror
AR = ar rc

SRCS = get_next_line.c get_next_line_utils.c

OBJ = *.o

all: $(NAME)

$(NAME):
	$(CC)  $(FLAGS) -c $(SRCS)
	$(AR)  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re