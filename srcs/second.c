/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:23 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 18:31:37 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

//*10 is the amount of power of the value changed
void	gridxy(coords **coor, s_leng leng, int scale)
{
	int y;
	int x;

	y = 0;
	while (y < leng.lines)
	{
		x = 0;
		while (x < leng.len)
		{
			(*coor)[x + (y*leng.len)].gridx = x * scale - (y * scale);
			(*coor)[x + (y*leng.len)].gridy = y * scale + (x * scale);
			//- (*coor)[x + (y * leng.len)].y * 10
			++x;
		}
		++y;
	}
}

void	linex(mlx_t	*mlx, coords **coor, int i)
{
	int x;
	int ymath;

	x = 0;
	while ((x + (*coor)[i].gridx) < (*coor)[i + 1].gridx)
	{
		ymath = mathx(coor, i, x);
		mlx_image_to_window(mlx, g_img, x + (*coor)[i].gridx + OFX, (*coor)[i].gridy + ymath + OFY);
		//mlx_image_to_window(mlx, g_img, x + (*coor)[i].gridx + OFX, (*coor)[i].gridy + HEIGHT/3);
		++x;
	}
}

void	liney(mlx_t	*mlx, coords **coor, int i, s_leng leng)
{
	int y;
	int xmath;

	y = 0;
	while ((y + (*coor)[i].gridy) > (*coor)[i - leng.len].gridy)
	{
		xmath = mathy(coor, i, y, leng);
		mlx_image_to_window(mlx, g_img, (*coor)[i].gridx + xmath + OFX, y + (*coor)[i].gridy + OFY);
		--y;
	}
}

//DRAW THE DOTS AND LINES
void	gridline(coords **coor, s_leng leng, mlx_t	*mlx)
{
	int i;

	i = 0;
	while (i < (leng.len * leng.lines))
	{
		if ((*coor)[i].x < leng.len)
			linex(mlx, coor, i);
		if ((*coor)[i].z != 0)
			liney(mlx, coor, i, leng);
		mlx_image_to_window(mlx, g_img, (*coor)[i].gridx + OFX, (*coor)[i].gridy + OFY);
		++i;
	}
}

//MAIN FOR MLX42
int	screen(coords **coor, s_leng leng)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (0);
	g_img = mlx_new_image(mlx, 1, 1);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	gridline(coor, leng, mlx);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}