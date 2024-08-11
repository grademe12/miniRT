CLFAGS = -Wall -Wextra -Werror
SRCS = ./srcs/constructor.c miniRT.c ./srcs/render_ppm.c ./srcs/sphere.c \
		./srcs/vector_utils.c ./srcs/vector_utils2.c ./srcs/shadow.c \
		./srcs/light.c ./srcs/plane.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

$(NAME) : $(OBJS)
	cc $(CLFAGS) -g -o $(NAME) $(OBJS) -I. -lm

%.o: %.c
	cc $(CLFAGS) -g -c $< -o $@ -I.

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all