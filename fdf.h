/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 11:06:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 13:33:40 by mbernede      ########   odam.nl         */
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
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	int			zoom;
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

void			ft_free(char **str);
void			check_leaks(void);
void			ifprintpixel(coords *coor, mlx_image_t	*g_img, int i);

int				maxintx(coords *coor, s_leng leng, char c);
void			fillback(mlx_image_t *background);

void			gridxy(coords *coor, s_leng leng, int scale);
int				screen(coords *coor, s_leng leng);
void			gridline(coords *coor, s_leng leng, mlx_t *mlx, mlx_image_t *g_img);

void			gridxy(coords *coor, s_leng leng, int scale);
int				mathx(coords *coor, int i, int x);
int				mathy(coords *coor, int i, int x, s_leng leng);

void			fill(coords *coor, char *file, s_leng leng);

unsigned int	colorpointy(coords *coor, int i, int x, s_leng leng);
unsigned int	colorpoint(coords *coor, int i, int x);

#endif