CLFAGS = -Wall -Wextra -Werror
SRCS =	./srcs/add_argument.c ./srcs/constructor.c ./srcs/cylinder.c ./srcs/cylinder2.c ./srcs/cylinder3.c \
		./srcs/draw.c ./srcs/error_utils.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c \
		./srcs/init_info.c ./srcs/light.c ./srcs/mlx_utils.c ./srcs/parsing_argument.c \
		./srcs/parsing_line.c ./srcs/parsing_line2.c ./srcs/parsing_utils.c ./srcs/parsing.c \
		./srcs/pixel.c ./srcs/plane.c ./srcs/point_utils.c ./srcs/render_ppm.c ./srcs/shadow.c \
		./srcs/shoot_ray.c ./srcs/sphere.c ./srcs/utils.c ./srcs/utils2.c ./srcs/utils3.c \
		./srcs/vector_utils.c ./srcs/vector_utils2.c ./srcs/cylinder_shadow.c \
		./miniRT.c ./srcs/test.c
#		./srcs/matrix.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

$(NAME) : $(OBJS)
	cc $(CLFAGS) $(OBJS) -g -o $(NAME) \
	-I. -I./openGL \
	-L. -lmlx \
	-framework Metal -framework Metalkit
#	-L./openGL -lmlx 
#	-framework OpenGL -framework Appkit

%.o: %.c
	cc $(CLFAGS) -g -c $< -o $@ 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all