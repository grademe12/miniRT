CLFAGS = -Wall -Wextra -Werror
SRCS = ./srcs/constructor.c miniRT.c ./srcs/render_ppm.c ./srcs/sphere.c \
		./srcs/vector_utils.c ./srcs/vector_utils2.c ./srcs/shadow.c \
		./srcs/light.c ./srcs/plane.c ./srcs/cylinder.c ./srcs/cylinder2.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

$(NAME) : $(OBJS)
	cc $(CLFAGS) $(OBJS) -g -o $(NAME) -I. -I./openGL -lm -L./openGL -lmlx \
	-framework OpenGL -framework Appkit

%.o: %.c
	cc $(CLFAGS) -g -c $< -o $@ 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all