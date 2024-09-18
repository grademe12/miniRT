CLFAGS = -Wall -Wextra -Werror
SRCS = 		./srcs/parsing.c ./srcs/parsing_line.c ./srcs/utils2.c  ./srcs/utils3.c\
		./srcs/utils.c miniRT.c ./srcs/get_next_line.c  ./srcs/get_next_line_utils.c \
		./srcs/init_info.c ./srcs/error_utils.c ./srcs/parsing_utils.c \
		./srcs/parsing_argument.c
# ./srcs/constructor.c miniRT.c ./srcs/render_ppm.c ./srcs/sphere.c \
# 		./srcs/vector_utils.c ./srcs/vector_utils2.c ./srcs/shadow.c \
# 		./srcs/light.c ./srcs/plane.c ./srcs/cylinder.c ./srcs/cylinder2.c \
# 		./srcs/cylinder3.c ./srcs/mlx_utils.c ./srcs/shoot_ray.c \
# 		./srcs/point_utils.c ./srcs/draw.c ./srcs/pixel.c 

OBJS = $(SRCS:.c=.o)
NAME = miniRT

$(NAME) : $(OBJS)
	cc $(CLFAGS) $(OBJS) -g -o $(NAME) 
#  -I. -I./openGL -lm -L./openGL -lmlx \
# // -framework OpenGL -framework Appkit

%.o: %.c
	cc $(CLFAGS) -g -c $< -o $@ 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all