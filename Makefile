SRCS = make_window.c\
	hook_event.c\

NAME = a.out

mlx = -framework Appkit -framework opengl -lmlx -Lmlx -Imlx

libft = -I libft -L libft -l ft



$(NAME) :
	gcc $(mlx) $(libft) $(SRCS) main.c

all :
	gcc $(mlx) $(libft) $(SRCS) main.c
clean :

fclean :

re :
