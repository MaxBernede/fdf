/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 11:06:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 16:17:42 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1080
# define HEIGHT 1080
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include "libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct coor
{
	int				x;
	int				y;
	int				z;
	int				gridx;
	int				gridy;
	int				r;
	int				g;
	int				b;
	unsigned int	color;
}	coords;

typedef struct all
{
	coords		*coor;
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	int			nb_lines;
	int			nb_len;
	int			zoom;
	int			a;
	int			b;
}	t_all;

typedef struct leng
{
	int	len;
	int	lines;
	int	x;
	int	y;
}	s_leng;

typedef struct rgb
{
	int	r;
	int	g;
	int	b;
}	s_colors;

//colorpoint.c
uint			colorpointy(coords *coor, int i, int x, s_leng leng);
uint			colorpoint(coords *coor, int i, int x);

//coordcolors.c
int				hexavalue(char *c, int x);
void			getcolorintfromhexa(char *strcolor, t_all *all);
void			fillcoor(t_all *all, char *splited);
void			fill(t_all *all, char *file);

//grid.c
void			cleanpositive(coords *coor, s_leng leng, int minx, int miny);
void			cleangridxy(coords *coor, s_leng leng);
void			gridxy(coords *coor, s_leng leng, int scale);
int				mathx(coords *coor, int i, int x);
int				mathy(coords *coor, int i, int x, s_leng leng);

//main.c
int				map_data(t_all *all, char *file, int lines);
int				main(int argc, char **argv);

//second.c
void			hook(void *param);
void			linex(mlx_image_t *g_img, coords *coor, int i);
void			liney(mlx_image_t *g_img, coords *coor, int i, s_leng leng);
void			gridline(coords *coor, s_leng leng, mlx_t	*mlx, mlx_image_t	*g_img);
int				screen(coords *coor, s_leng leng);

//utils.c
int				grad_diff(int rstart, int rend, float pourcent);
int				maxintx(coords *coor, s_leng leng, char c);
void			ifprintpixel(coords *coor, mlx_image_t	*g_img, int i);

//utils2.c
int				count_len_map(char *line);
void			placebackground(mlx_image_t *background);
int				returnstr(char *str, int ret);
void			ft_free(char **str);
void			check_leaks(void);

#endif