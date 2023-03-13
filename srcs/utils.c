/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 00:24:32 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 15:44:30 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// find diff between the R G B value then *porcent to get color
int	grad_diff(int rstart, int rend, float pourcent)
{
	int	diff;
	int	ret;

	diff = rstart - rend;
	ret = rstart - (diff * pourcent / 100);
	return (ret);
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
