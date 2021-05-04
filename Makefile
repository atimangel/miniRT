
SRC = main.c\
      ambient_reflection.c\
      cylinder.c\
      diffuse_reflection.c\
      hook_event.c\
      light.c\
      make_window.c\
      pixel_map.c\
      plane.c\
      sphere.c\
      square.c\
      triangle.c\
      specular_reflection.c\
      parse_rt.c\
      resolution.c\
      camera.c\
      parse_utils.c\

NAME = raytracing.out

libft = -I libft -L libft -lft
mlx = -I mlx -L mlx -lmlx
inclib = -I /usr/include/lib -lXext -lX11 -lm -lbsd

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRC) $(libft) $(mlx) $(inclib)

clean :

fclean : clean
	rm $(NAME)

re : fclean all
