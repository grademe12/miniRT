CLFAGS = -Wall -Wextra -Werror
SRCS = ./srcs/constructor.c ./srcs/miniRT.c ./srcs/render_ppm.c ./srcs/sphere.c \
		./srcs/vector_utils.c ./srcs/vector_utils2.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

$(NAME) : $(OBJS)
	cc $(CLFAGS) -o $(NAME) $(OBJS) -I.

%.o: %.c
	cc $(CLFAGS) -c $< -o $@ -I.

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all