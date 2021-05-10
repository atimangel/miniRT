
SRC = main.c\
      ambient_reflection.c\
      cylinder.c\
      hook_event.c\
      light.c\
      make_window.c\
      pixel_map.c\
      plane.c\
      sphere.c\
      square.c\
      triangle.c\
      parse_rt.c\
      resolution.c\
      camera.c\
      parse_utils.c\
	  touch.c\
	  touch_utils.c\
	  reflection.c\
      specular_reflection.c\
      diffuse_reflection.c\


NAME = raytracing.out

libft = -I libft -L libft -lft
mlx = -I mlx -L mlx -lmlx
inclib = -framework Appkit -framework opengl
all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRC) $(libft) $(mlx) $(inclib)

clean :

fclean : clean
	rm $(NAME)

re : fclean all
