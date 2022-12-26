/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:23 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/26 17:03:27 by kyuuh            ###   ########.fr       */
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
			(*coor)[x + (y*leng.len)].gridy = y * scale/2 + (x * scale / 2) - (*coor)[x + (y * leng.len)].y * 5;
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
	while ((x + (*coor)[i].gridx) != (*coor)[i + 1].gridx)
	{
		ymath = mathx(coor, i, x);
		mlx_image_to_window(mlx, g_img, x + (*coor)[i].gridx + OFX, (*coor)[i].gridy + ymath + OFY);
		if ((*coor)[i].gridx < (*coor)[i + 1].gridx)
			++x;
		else
			--x;
	}
}

void	liney(mlx_t	*mlx, coords **coor, int i, s_leng leng)
{
	int y;
	int xmath;

	y = 0;
	while ((y + (*coor)[i].gridy) != (*coor)[i - leng.len].gridy)
	{
		xmath = mathy(coor, i, y, leng);
		mlx_image_to_window(mlx, g_img, (*coor)[i].gridx + xmath + OFX, y + (*coor)[i].gridy + OFY);
		if ((*coor)[i].gridy > (*coor)[i - leng.len].gridy)
			--y;
		else
			++y;
	}
}

//DRAW THE DOTS AND LINES
void	gridline(coords **coor, s_leng leng, mlx_t	*mlx)
{
	int i;

	i = 0;
	printf("entree\n");
	while (i < (leng.len * leng.lines))
	{
		if ((*coor)[i].x + 1 < leng.len)
			linex(mlx, coor, i);
		if ((*coor)[i].z != 0)
			liney(mlx, coor, i, leng);
		mlx_image_to_window(mlx, g_img, (*coor)[i].gridx + OFX, (*coor)[i].gridy + OFY);
		++i;
	}
}

// void	printscreen(mlx_t	*mlx;)
// {
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 	{
// 		mlx_close_window(mlx);
// 		return ;
// 	}
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// }

//MAIN FOR MLX42
int	screen(coords **coor, s_leng leng)
{
	mlx_t	*mlx;
	mlx_image_t	*background;


	gridxy(coor, leng, 30);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (0);

	background = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, background, 0, 0);
	memset(background->pixels, 100, background->width * background->height * sizeof(int));

	g_img = mlx_new_image(mlx, 1, 1);
	mlx_image_to_window(mlx, g_img,OFX - 10,OFY - 10);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_put_pixel(g_img, OFX - 10, OFY - 10, 0xd7adad);
	gridline(coor, leng, mlx);
	// printscreen(mlx);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}