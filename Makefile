NAME			=	miniRT

error			=	error.c
parse			=	float.c\
					parse.c\
					object.c\
					object_unique.c\
					struct.c
raytracing		=	raytracing.c\
					reflection.c\
					shoot_ray.c\
					shoot_ray_to_cylinder.c

ray_utils		=	vector.c\
					utils.c

utility			=	utils_cpy.c\
					utils_dup.c\
					utils_str.c\
					utils_mem.c\
					utils_num.c\
					utils_x.c\
					get_next_line.c


src				=	main.c\
					$(error:%=error/%)\
					$(parse:%=parse/%)\
					$(raytracing:%=raytracing/%)\
					$(ray_utils:%=ray_utils/%)\
					$(utility:%=utility/%)

SRCS			=	$(src:%=./src/%)
OBJ				=	$(SRCS:./src/%.c=./obj/%.o)

42flag			=	-Wall -Werror -Wextra
MLX42flag		=	-L "/opt/homebrew/opt/glfw/lib/" -lglfw
MLX42			=	./lib/MLX42/libmlx42.a

mlxflag			=	-L ./lib/mlx -I ./lib/mlx -lmlx -framework Appkit -framework opengl
mlx				=	./lib/mlx/libmlx.a

compiler		=	gcc

./obj/%.o		:	./src/%.c
	@mkdir -p $(dir ./obj/$*)
	$(compiler) $(42flag) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@make -C ./lib/mlx/
	$(compiler) $(42flag) $(mlxflag) $(OBJ) -o $(NAME)

clean	:
	@make clean -C ./lib/mlx
	rm -rf ./obj 

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all
