NAME				=	miniRT

error				=	error.c
parse				=	float.c\
						parse.c\
						object.c\
						object_unique.c\
						struct.c
raytracing			=	raytracing.c\
						reflection.c\
						shoot_ray.c\
						shoot_ray_to_cylinder.c
ray_utils			=	vector.c\
						vector2.c\
						utils.c
utility				=	utils_cpy.c\
						utils_dup.c\
						utils_str.c\
						utils_mem.c\
						utils_num.c\
						utils_x.c\
						get_next_line.c


src					=	main.c\
						$(error:%=error/%)\
						$(parse:%=parse/%)\
						$(raytracing:%=raytracing/%)\
						$(ray_utils:%=ray_utils/%)\
						$(utility:%=utility/%)

error_bonus			=	$(error:%.c=%_bonus.c)
parse_bonus			=	$(parse:%.c=%_bonus.c)\
						bump_bonus.c
ray_utils_bonus		=	$(ray_utils:%.c=%_bonus.c)\
						vector3_bonus.c\
						filter_bonus.c
raytracing_bonus	=	$(raytracing:%.c=%_bonus.c)\
						shoot_ray_to_cone_bonus.c
utility_bonus		=	$(utility:%.c=%_bonus.c)

src_bonus			=	main_bonus.c\
						$(error_bonus:%=error/%)\
						$(parse_bonus:%=parse/%)\
						$(raytracing_bonus:%=raytracing/%)\
						$(ray_utils_bonus:%=ray_utils/%)\
						$(utility_bonus:%=utility/%)

SRCS				=	$(src:%=./src/%)
OBJ					=	$(SRCS:./src/%.c=./obj/%.o)
SRCS_BONUS			=	$(src_bonus:%=./src_bonus/%)
OBJ_BONUS			=	$(SRCS_BONUS:./src_bonus/%.c=./obj_bonus/%.o)

42flag				=	-Wall -Werror -Wextra
MLX42flag			=	-L "/opt/homebrew/opt/glfw/lib/" -lglfw
MLX42				=	./lib/MLX42/libmlx42.a

mlxflag				=	-L ./lib/mlx -I ./lib/mlx -lmlx -framework Appkit -framework opengl
mlx					=	./lib/mlx/libmlx.a

compiler			=	gcc

all		:	$(NAME)

./obj/%.o			:	./src/%.c
	@mkdir -p $(dir ./obj/$*)
	$(compiler) $(42flag) -c $< -o $@

$(NAME)	:	$(OBJ)
	@make -C ./lib/mlx/
	$(compiler) $(42flag) $(mlxflag) $(OBJ) -o $(NAME)

bonus	:	$(NAME)_bonus

./obj_bonus/%.o			:	./src_bonus/%.c
	@mkdir -p $(dir ./obj_bonus/$*)
	$(compiler) $(42flag) -c $< -o $@

$(NAME)_bonus	:	$(OBJ_BONUS)
	@make -C ./lib/mlx/
	$(compiler) $(42flag) $(mlxflag) $(OBJ_BONUS) -o $(NAME)_bonus


clean	:
	@make clean -C ./lib/mlx
	rm -rf ./obj ./obj_bonus

fclean	:	clean
	rm -rf $(NAME) $(NAME)_bonus

re		:	fclean all
