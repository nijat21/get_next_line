NAME=get_next_line.a

CC=cc


CFLAGS = -Wall -Wextra -Werror
CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
BUFFER_SIZE ?= 1
$(info Compiling with BUFFER_SIZE: $(BUFFER_SIZE))

SRCS := get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fv $(OBJS)

fclean:
	rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re