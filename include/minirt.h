/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:50 by snpark            #+#    #+#             */
/*   Updated: 2022/02/18 22:47:28 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "./type.h"
# include "./resource.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//parse
void		parse(const char *const filename, t_rt *const img_format);
t_vector	parse_vector(const char **line);
t_vector	parse_normal_vector(const char **line);
t_color		parse_color(const char **line);
float		parse_angle(const char **line);
float		parse_ratio(const char **line);
float		parse_length(const char **line);

void		parse_ambient(const char *line, t_rt *img_format, t_bool *flag);
void		parse_light(const char *line, t_rt *img_format, t_bool *flag);
void		parse_camera(const char *line, t_rt *img_format, t_bool *flag);
void		parse_sphere(const char *line, t_rt *img_format, t_bool *flag);
void		parse_plane(const char *line, t_rt *img_format, t_bool *flag);
void		parse_cylinder(const char *line, t_rt *img_format, t_bool *flag);

void		skip_space(const char **str);

t_bool		is_rtfile(char *filename);
t_bool		get_next_line(int fd, char **dest);

//utils
int			ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t len);
char		*ft_strncpy(char *dst, const char *src, size_t len);
void		ft_strmove(char *str, unsigned int move);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *str);
char		*ft_strndup(const char *str, size_t n);

//utils x alloc and free
void		*xcalloc(size_t bytes);
void		xfree(void *obj);
int			xopen(const char *path, int oflag);
ssize_t		xread(int filedes, void *buf, size_t nbyte);

int			ft_atoi(const char **s);
float		ft_atof(const char **s);

//error
void		report_error(const char *str);
#endif
