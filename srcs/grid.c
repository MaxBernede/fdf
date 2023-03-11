/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 16:27:51 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/11 17:20:42 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// add the max negative value to only have positive ones
void	cleanpositive(coords **coor, s_leng leng, int minx, int miny)
{
	int	i;

	i = 0;
	if (minx < 0)
		minx *= -1;
	if (miny < 0)
		miny *= -1;
	while (i < (leng.len * leng.lines))
	{
		if (minx)
			(*coor)[i].gridx = (*coor)[i].gridx + minx;
		if (miny)
			(*coor)[i].gridy = (*coor)[i].gridy + miny;
		++i;
	}
}

//search for the min grid x and grid y values to print only positive numbers
void	cleangridxy(coords **coor, s_leng leng)
{
	int	i;
	int	minx;
	int	miny;

	i = 0;
	minx = 0;
	miny = 0;
	while (i < (leng.len * leng.lines))
	{
		if ((*coor)[i].gridx < minx)
			minx = (*coor)[i].gridx;
		if ((*coor)[i].gridy < miny)
			miny = (*coor)[i].gridy;
		++i;
	}
	if (minx < 0 || miny < 0)
		cleanpositive(coor, leng, minx, miny);
}

//scale is the zoom, I need to change the hardcoded values inside still
void	gridxy(coords *coor, s_leng leng, int scale)
{
	int	y;
	int	x;
	int	half;
	int	height;

	y = 0;
	half = scale / 2;
	height = 1;
	while (y < leng.lines)
	{
		x = 0;
		while (x < leng.len)
		{
			coor[x + (y * leng.len)].gridx = x * scale - (y * scale);
			coor[x + (y * leng.len)].gridy = y * half + (x * half) - \
			coor[x + (y * leng.len)].y * height;
			++x;
		}
		++y;
	}
	cleangridxy(&coor, leng);
}

//mathx return an int for the x position of the point to print
// print if theres value to the right, from left to right
int	mathx(coords *coor, int i, int x)
{
	float	y;
	float	m;
	float	total;
	int		o;

	y = (float)coor[i + 1].gridy - (float)coor[i].gridy;
	m = (float)coor[i + 1].gridx - (float)coor[i].gridx;
	total = y / m;
	o = total * x;
	return (o);
}

// give back the y coordinate
// print if theres value above, from bottom to top
int	mathy(coords *coor, int i, int x, s_leng leng)
{
	float	y;
	float	m;
	float	total;
	int		o;

	y = (float)coor[i - leng.len].gridy - (float)coor[i].gridy;
	m = (float)coor[i - leng.len].gridx - (float)coor[i].gridx;
	total = m / y;
	o = total * x;
	return (o);
}
