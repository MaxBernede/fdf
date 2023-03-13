/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 00:24:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 12:43:45 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// fill black on background
void	fillback(mlx_image_t *background)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(background, x, y, 0x000000FF);
	}
}

// max value for x or y depending on the input char
int	maxintx(coords *coor, s_leng leng, char c)
{
	int	i;
	int	max;
	int	maxy;

	i = 0;
	max = 0;
	maxy = 0;
	while (i < (leng.len * leng.lines))
	{
		if (max < coor[i].gridx)
			max = coor[i].gridx;
		if (maxy < coor[i].gridy)
			maxy = coor[i].gridy;
		++i;
	}
	if (c == 'x')
		return (max + 1);
	else
		return (maxy + 1);
}

void	ifprintpixel(coords *coor, mlx_image_t	*g_img, int i)
{
	if (coor[i].gridx > 0 && coor[i].gridx < WIDTH && \
	coor[i].gridy > 0 && coor[i].gridx < HEIGHT)
		mlx_put_pixel(g_img, coor[i].gridx, coor[i].gridy, \
		coor[i].color);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	check_leaks(void)
{
	system("leaks fdf");
}
