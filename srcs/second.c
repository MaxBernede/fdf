/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:23 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 14:20:34 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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

int	screen(coords **coor, s_leng leng)
{
	mlx_t	*mlx;
	int i;

	i = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (0);
	g_img = mlx_new_image(mlx, 180, 180);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	while (i < WIDTH)
	{
		mlx_image_to_window(mlx, g_img, i, 10);
		i += 10;
	}
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}