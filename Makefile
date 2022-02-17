NAME			=	miniRT

utility			=	utils_cpy.c\
					utils_dup.c\
					utils_str.c\
					utils_mem.c\
					utils_x.c

src				=	$(utility:%=utility/%)

SRCS			=	$(src:%=./src/%)
OBJ				=	$(SRCS:./src/%.c=./obj/%.o)
main			=	./src/main.c

42flag			=	-Wall -Werror -Wextra

compiler		=	gcc

./obj/%.o		:	./src/%.c
	@mkdir -p $(dir ./obj/$*)
	$(compiler) $(42flag) -c $< -o $@

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(compiler) $(42flag) $(main) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all
