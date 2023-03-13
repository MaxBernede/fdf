/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   second.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 13:55:23 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 18:19:45 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	linex(t_all *all, int i)
{
	int		x;
	int		ymath;
	uint	color;
	int		y;
	int		ymathplus;

	x = 0;
	while ((x + all->coor[i].gridx) != all->coor[i + 1].gridx)
	{
		y = 0;
		ymath = mathx(all, i, x);
		ymathplus = mathx(all, i, x + 1);
		color = colorpoint(all->coor, i, x);
		while ((y + ymath) != ymathplus)
		{
			mlx_put_pixel(all->g_img, x + all->coor[i].gridx, \
			all->coor[i].gridy + ymath + y, color);
			if ((y + ymath) < ymathplus)
				++y;
			else if ((y + ymath) > ymathplus)
				--y;
		}
		mlx_put_pixel(all->g_img, x + all->coor[i].gridx, \
		all->coor[i].gridy + ymath + y, color);
		if (all->coor[i].gridx < all->coor[i + 1].gridx)
			++x;
		else
			--x;
	}
}

void	liney(t_all *all, int i)
{
	int		y;
	int		ymath;
	int		x;
	int		yplus;
	uint	color;

	x = 0;
	while ((x + all->coor[i].gridx) != all->coor[i - all->nb_len].gridx)
	{
		y = 0;
		ymath = mathy(all, i, x);
		yplus = mathy(all, i, (x + 1));
		color = colorpointy(all, i, x);
		while ((y + ymath) != yplus)
		{
			mlx_put_pixel(all->g_img, x + all->coor[i].gridx, \
			all->coor[i].gridy + y + ymath, color);
			if ((y + ymath) < yplus)
				++y;
			else if ((y + ymath) > yplus)
				--y;
		}
		mlx_put_pixel(all->g_img, all->coor[i].gridx + x, all->coor[i].gridy + ymath, \
		color);
		if ((x + all->coor[i].gridx) < all->coor[i - all->nb_len].gridx)
			++x;
		else
			--x;	
	}
}

//DRAW THE DOTS AND LINES
void	gridline(t_all *all)
{
	int	i;

	i = 0;
	while (i < (all->nb_len * all->nb_lines))
	{
		if (all->coor[i].x + 1 < all->nb_len)
			linex(all, i);
		if (all->coor[i].z != 0)
			liney(all, i);
		ifprintpixel(all->coor, all->g_img, i);
		++i;
	}
}

//MAIN FOR MLX42
int	screen(t_all *all)
{
	mlx_image_t	*background;

	gridxy(all);
	all->mlx =  mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!all->mlx)
		return (0);
	background = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if (!background)
		return(returnstr("\nBackground image creation failed\n", 0));
	fill_background(background);
	mlx_image_to_window(all->mlx, background, 0, 0);
	all->g_img = mlx_new_image(all->mlx, maxintx(all, 'x'), maxintx(all, 'y'));
	if (!all->g_img)
		return(returnstr("\nMap creation failed\n", 0));
	mlx_image_to_window(all->mlx, all->g_img, 0, 0);
	gridline(all);
	all->g_img->instances[0].x -=  maxintx(all, 'x') / 3;
	all->g_img->instances[0].y -=  maxintx(all, 'y') / 3;
	mlx_loop_hook(all->mlx, &hook, all);
	mlx_loop(all->mlx);
	return (0);
}
