SRCS = make_window.c\
	hook_event.c\
	pixel_map.c\
	sphere.c\
	plane.c\

NAME = a.out

mlx = -framework Appkit -framework opengl -lmlx -Lmlx -Imlx

libft = -I libft -L libft -l ft



$(NAME) :
	gcc $(mlx) $(libft) $(SRCS) main.c

all :
	gcc $(mlx) $(libft) $(SRCS) main.c
clean :
	rm a.out
fclean :

re : clean all
