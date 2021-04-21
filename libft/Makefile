# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 17:18:50 by snpark            #+#    #+#              #
#    Updated: 2021/01/01 08:55:43 by snpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c\
	   ft_memset.c\
       ft_bzero.c\
       ft_calloc.c\
       ft_isalnum.c\
       ft_isalpha.c\
       ft_isascii.c\
       ft_isdigit.c\
       ft_isprint.c\
       ft_itoa.c\
       ft_memccpy.c\
       ft_memcpy.c\
       ft_memcmp.c\
       ft_memchr.c\
       ft_memmove.c\
       ft_putnbr_fd.c\
       ft_putchar_fd.c\
       ft_putendl_fd.c\
       ft_putstr_fd.c\
       ft_split.c\
       ft_strchr.c\
	   ft_strrchr.c\
       ft_strdup.c\
       ft_strjoin.c\
       ft_strlcat.c\
       ft_strlcpy.c\
       ft_strlen.c\
       ft_strmapi.c\
       ft_strncmp.c\
       ft_strnstr.c\
	   ft_strtrim.c\
       ft_substr.c\
       ft_tolower.c\
       ft_toupper.c\

BONUS_SRCS = ft_lstnew.c\
			 ft_lstadd_front.c\
			 ft_lstsize.c\
			 ft_lstlast.c\
			 ft_lstadd_back.c\
			 ft_lstdelone.c\
			 ft_lstclear.c\
			 ft_lstiter.c\
			 ft_lstmap.c\
			 ft_matrix_identity_bonus.c\
		 	 ft_matrix_rotation_z_bonus.c\
			 ft_matrix_inverse_bonus.c\
		 	 ft_matrix_scailing_bonus.c\
			 ft_matrix_rotation_x_bonus.c\
		 	 ft_matrix_translation_bonus.c\
			 ft_matrix_rotation_y_bonus.c\
		 	 ft_matrix_transpose_bonus.c\
			 ft_vec3_add_bonus.c\
	 		 ft_vec3_len_bonus.c\
			 ft_vec3_cos_bonus.c\
	 		 ft_vec3_normalize_bonus.c\
			 ft_vec3_cross_product_bonus.c\
			 ft_vec3_remove_bonus.c\
			 ft_matrix_determinant_bonus.c\
			ft_vec3_transform_coord_bonus.c\
			ft_vec3_transform_normal_bonus.c\
			ft_putvec_bonus.c\
			ft_puta16_bonus.c\
			ft_vec3_bonus.c\
			ft_vec3_scale_bonus.c\
			ft_vec3_dot_product_bonus.c\
			ft_matrix_bonus.c\

BONUS_OBJS = $(BONUS_SRCS:.c=.o);
OBJS = $(SRCS:.c=.o);

NAME = libft.a

CC = gcc
CCFLAG = -Wall -Werror -Wextra
ARFLAG = -rc

all : $(NAME)

$(NAME) : $(OBJS)
	ar $(ARFLAG) $@ $^

bonus : $(BONUS_OBJS)
	ar $(ARFLAG) $(NAME) $^

clean :
	rm -rf *.o

fclean : clean
	rm -rf libft.a

re : fclean all
