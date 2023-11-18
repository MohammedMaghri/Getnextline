SRC = get_next_line.c copy.c lencount.c 
OBJS = ${SRC:.c=.o}
NAME = nextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(OBJS) 
	ar rcs $(NAME) $(SRC) 

