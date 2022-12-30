/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:27:51 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/30 18:03:07 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// add the max negative value to only have positive ones
void	cleanpositive(coords **coor, s_leng leng, int minx, int miny)
{
	int i;

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
			(*coor)[i].gridy= (*coor)[i].gridy + miny;
		++i;
	}
}

//search for the min grid x and grid y values then clean above
void	cleangridxy(coords **coor, s_leng leng)
{
	int i;
	int minx;
	int miny;

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
	cleangridxy(coor, leng);
}

int mathx(coords **coor, int i, int x)
{
	float y;
	float m;
	float total;
	int o;

	y = (float)(*coor)[i + 1].gridy - (float)(*coor)[i].gridy;
	m = (float)(*coor)[i + 1].gridx - (float)(*coor)[i].gridx;
	total = y / m;
	o = total * x;
	return (o);
}

int mathy(coords **coor, int i, int x, s_leng leng)
{
	float y;
	float m;
	float total;
	int o;

	y = (float)(*coor)[i - leng.len].gridy - (float)(*coor)[i].gridy;
	m = (float)(*coor)[i - leng.len].gridx - (float)(*coor)[i].gridx;
	total = m / y;
	o = total * x;
	return (o);
}