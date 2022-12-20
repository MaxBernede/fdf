/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:23 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 14:56:33 by kyuuh            ###   ########.fr       */
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

//change gridxy for real y coordinates
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
			(*coor)[x + (y*leng.len)].gridx = x * scale;
			(*coor)[x + (y*leng.len)].gridy = y * scale;
			++x;
		}
		++y;
	}
}

void	gridline(coords **coor, s_leng leng, mlx_t	*mlx)
{
	int i;

	i = 0;
	while (i < (leng.len * leng.lines))
	{
		mlx_image_to_window(mlx, g_img, (*coor)[i].gridx + WIDTH/3, (*coor)[i].gridy + HEIGHT/3);
		++i;
	}
}

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