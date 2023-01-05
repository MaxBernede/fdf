/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:55:23 by kyuuh             #+#    #+#             */
/*   Updated: 2023/01/06 00:02:11 by kyuuh            ###   ########.fr       */
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
		g_img->instances[0].y -= 25;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 25;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 25;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 25;
	if (mlx_is_key_down(mlx, MLX_KEY_J))
		printf("Hello ");
}

void	linex(mlx_image_t	**g_img, coords **coor, int i)
{
	int x;
	int ymath;
	uint color;

	x = 0;
	while ((x + (*coor)[i].gridx) != (*coor)[i + 1].gridx)
	{
		ymath = mathx(coor, i, x);
		color = colorpoint(coor, i, x);
		mlx_put_pixel(*g_img, x + (*coor)[i].gridx, (*coor)[i].gridy + ymath, color);
		if ((*coor)[i].gridx < (*coor)[i + 1].gridx)
			++x;
		else
			--x;
	}
}

void	liney(mlx_image_t	**g_img, coords **coor, int i, s_leng leng)
{
	int y;
	int xmath;

	y = 0;
	while ((y + (*coor)[i].gridy) != (*coor)[i - leng.len].gridy)
	{
		xmath = mathy(coor, i, y, leng);
		mlx_put_pixel(*g_img, (*coor)[i].gridx + xmath, y + (*coor)[i].gridy, (*coor)[i].color);
		if ((*coor)[i].gridy > (*coor)[i - leng.len].gridy)
			--y;
		else
			++y;
	}
}

//DRAW THE DOTS AND LINES
void	gridline(coords **coor, s_leng leng, mlx_t	*mlx, mlx_image_t	**g_img)
{
	int i;

	i = 0;
	printf("entree\n");
	while (i < (leng.len * leng.lines))
	{
		if ((*coor)[i].x + 1 < leng.len)
			linex(g_img, coor, i);
		if ((*coor)[i].z != 0)
			liney(g_img, coor, i, leng);
		mlx_put_pixel(*g_img, (*coor)[i].gridx, (*coor)[i].gridy, (*coor)[i].color);
		// printf("i de %d  grix %d et gridy %d\n",i, (*coor)[i].gridx, (*coor)[i].gridy);
		++i;
	}
}

void	fillback(mlx_image_t	**background) // fill black on background
{
	int x;
	int y;

	y = -1;
	while(++y <= HEIGHT)
	{
		x = -1;
		while(++x <= WIDTH)
			mlx_put_pixel(*background, x, y, 0x000000FF);
	}
}

int	maxintx(coords **coor, s_leng leng, char c) // max value for x or y depending on the input char
{
	int i;
	int max;
	int maxy;

	i = 0;
	max = 0;
	maxy = 0;
	while (i < (leng.len * leng.lines))
	{
		if (max < (*coor)[i].gridx)
			max = (*coor)[i].gridx;
		if (maxy < (*coor)[i].gridy)
			maxy = (*coor)[i].gridy;
		++i;
	}
	if (c == 'x')
		return (max + 1);
	else
		return (maxy + 1);
}

//MAIN FOR MLX42
int	screen(coords **coor, s_leng leng)
{
	mlx_t	*mlx;
	mlx_image_t	*background;


	gridxy(coor, leng, 10);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (0);

	background = mlx_new_image(mlx, WIDTH, HEIGHT);
	fillback(&background);
	mlx_image_to_window(mlx, background, 0, 0);
	//memset(background->pixels, 0, background->width * background->height * sizeof(int));

	g_img = mlx_new_image(mlx, maxintx(coor,leng, 'x'), maxintx(coor,leng, 'y'));
	mlx_image_to_window(mlx, g_img, 0, 0);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	gridline(coor, leng, mlx, &g_img);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	//mlx_terminate(mlx);
	// return (EXIT_SUCCESS);
	return (0);
}