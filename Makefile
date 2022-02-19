NAME			=	miniRT

error			=	error.c
parse			=	float.c\
					parse.c\
					object.c\
					object_unique.c\
					struct.c

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
					$(utility:%=utility/%)

SRCS			=	$(src:%=./src/%)
OBJ				=	$(SRCS:./src/%.c=./obj/%.o)

42flag			=	-Wall -Werror -Wextra

compiler		=	gcc

./obj/%.o		:	./src/%.c
	@mkdir -p $(dir ./obj/$*)
	$(compiler) $(42flag) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(compiler) $(42flag) $(OBJ) -o $(NAME)

clean	:
	rm -rf ./obj 

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all
