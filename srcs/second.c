/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   second.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 13:55:23 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 13:34:04 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	hook(void *param)
{
	t_all	*all;
	
	all = param;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
	if (mlx_is_key_down(all->mlx, MLX_KEY_UP))
		all->g_img->instances[0].y -= 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_DOWN))
		all->g_img->instances[0].y += 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
		all->g_img->instances[0].x -= 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
		all->g_img->instances[0].x += 25;
	if (mlx_is_key_down(all->mlx, MLX_KEY_0))
		all->g_img->instances[0].x += 25;
}

void	linex(mlx_image_t *g_img, coords *coor, int i)
{
	int		x;
	int		ymath;
	uint	color;
	int		y;
	int		ymathplus;

	x = 0;
	while ((x + coor[i].gridx) != coor[i + 1].gridx)
	{
		y = 0;
		ymath = mathx(coor, i, x);
		ymathplus = mathx(coor, i, x + 1);
		color = colorpoint(coor, i, x);
		while ((y + ymath) != ymathplus)
		{
			mlx_put_pixel(g_img, x + coor[i].gridx, \
			coor[i].gridy + ymath + y, color);
			if ((y + ymath) < ymathplus)
				++y;
			else if ((y + ymath) > ymathplus)
				--y;
		}
		mlx_put_pixel(g_img, x + coor[i].gridx, \
		coor[i].gridy + ymath + y, color);
		if (coor[i].gridx < coor[i + 1].gridx)
			++x;
		else
			--x;
	}
}

void	liney(mlx_image_t *g_img, coords *coor, int i, s_leng leng)
{
	int		y;
	int		ymath;
	int		x;
	int		yplus;
	uint	color;

	x = 0;
	while ((x + coor[i].gridx) != coor[i - leng.len].gridx)
	{
		y = 0;
		ymath = mathy(coor, i, x, leng);
		yplus = mathy(coor, i, (x + 1), leng);
		color = colorpointy(coor, i, x, leng);
		while ((y + ymath) != yplus)
		{
			mlx_put_pixel(g_img, x + coor[i].gridx, \
			coor[i].gridy + y + ymath, color);
			if ((y + ymath) < yplus)
				++y;
			else if ((y + ymath) > yplus)
				--y;
		}
		mlx_put_pixel(g_img, coor[i].gridx + x, coor[i].gridy + ymath, \
		color);
		if ((x + coor[i].gridx) < coor[i - leng.len].gridx)
			++x;
		else
			--x;	
	}
}

//DRAW THE DOTS AND LINES
void	gridline(coords *coor, s_leng leng, mlx_t	*mlx, mlx_image_t	*g_img)
{
	int	i;

	i = 0;
	while (i < (leng.len * leng.lines))
	{
		if (coor[i].x + 1 < leng.len)
			linex(g_img, coor, i);
		if (coor[i].z != 0)
			liney(g_img, coor, i, leng);
		ifprintpixel(coor, g_img, i);
		++i;
	}
}

//MAIN FOR MLX42
int	screen(coords *coor, s_leng leng)
{
	mlx_image_t	*background;
	t_all		all;

	all.zoom = 100;
	gridxy(coor, leng, all.zoom);
	all.mlx =  mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!all.mlx)
		return (0);
	background = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	fillback(background);
	mlx_image_to_window(all.mlx, background, 0, 0);
	all.g_img = mlx_new_image(all.mlx, maxintx(coor, leng, 'x'), \
	maxintx(coor, leng, 'y'));
	mlx_image_to_window(all.mlx, all.g_img, 0, 0);
	gridline(coor, leng, all.mlx, all.g_img);
	mlx_loop_hook(all.mlx, &hook, &all);
	mlx_loop(all.mlx);
	return (0);
}
