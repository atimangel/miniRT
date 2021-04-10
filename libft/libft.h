/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.ke>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:45:14 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 14:58:19 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
**Part 1
*/
size_t			ft_strlen(const char *str);

int				ft_memcmp(const void *buf1, const void *buf2, size_t count);
int				ft_strncmp(const char *string1, const char *string2,
		size_t count);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strdup(const char *str);

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t nitems, size_t size);

void			*ft_memchr(const void *buf, int c, size_t count);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);

size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

int				ft_isalpha(int	a);
int				ft_isdigit(int	a);
int				ft_isalnum(int	a);
int				ft_isascii(int	a);
int				ft_isprint(int	a);

int				ft_toupper(int	a);
int				ft_tolower(int	a);
int				ft_atoi(const char *string);
/*
**Part 2
*/
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
**Bonus
*/
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void *constent);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*del)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
/*
**Bonus MiniRT ARRAY & VECTOR
*/
/*
**Vector
*/
typedef struct s_vector3
{
	double v[4];
}				t_vec3;

double	ft_vec3_len(t_vec3 v);
t_vec3	ft_vec3_nomalize(t_vec3 v);
t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_remove(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_scale(t_vec3 v, double scala);
t_vec3	ft_vec3_dot_product(t_vec3 v1, t_vec3 v2);
double	ft_vec3_cos(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_cross_product(t_vec3 v1, t_vec3 v2);
//vec3transformcoord 변환된 벡터를 얻어주는 함수vector는 4개의 성분으로 (x,y,z,1)이다. 좌표 평행이동을 허용한다.
//vec3transformnomal (x, y, z, 0)으로 좌표 평행이동을 금지한다.
/*
**Array
*/
typedef struct s_array16
{
	double	a[4][4];
}				t_a16;

t_a16		ft_matrix_identity(void);
t_a16		ft_matrix_transpose(t_a16 array);
t_a16		ft_matrix_inverse(t_a16 array, double determinant);
t_a16		ft_matrix_translation(t_a16 *array, double x, double y, double z);
t_a16		ft_matrix_rotation_x(t_a16 array, double radian);
t_a16		ft_matrix_rotation_y(t_a16 array, double radian);
t_a16		ft_matrix_rotation_z(t_a16 array, double radian);
t_a16		ft_matrix_scailing(t_a16 array, double x, double y, double z);
#endif
