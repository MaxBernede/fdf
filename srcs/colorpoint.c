/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colorpoint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 17:49:51 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/12 19:00:08 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// find diff between the R G B value then *porcent to get color
int	diffpoint(int rstart, int rend, float pourcent)
{
	int	diff;
	int	ret;

	diff = rstart - rend;
	ret = rstart - (diff * pourcent / 100);
	return (ret);
}

uint	colorpointy(coords *coor, int i, int x, s_leng leng)
{
	uint		diff;
	float		pourcent;
	float		m;
	s_colors	rgb;

	m = (float)coor[i - leng.len].gridx - (float)coor[i].gridx;
	diff = coor[i - leng.len].color - coor[i].color;
	pourcent = (float)x / m * 100;
	if (diff)
	{
		rgb.r = diffpoint(coor[i].r, coor[i  - leng.len].r, pourcent);
		rgb.g = diffpoint(coor[i].g, coor[i  - leng.len].g, pourcent);
		rgb.b = diffpoint(coor[i].b, coor[i  - leng.len].b, pourcent);
		diff = (rgb.r * 16777216) + (rgb.g * 65536) + (rgb.b * 256) + 255;
	}
	else
		diff = coor[i].color;
	return (diff);
}

// find the right color for each pixel printed in linex or liney
uint	colorpoint(coords *coor, int i, int x)
{
	uint		diff;
	float		pourcent;
	float		m;
	s_colors	rgb;

	m = (float)coor[i + 1].gridx - (float)coor[i].gridx;
	diff = coor[i + 1].color - coor[i].color;
	pourcent = (float)x / m * 100;
	if (diff)
	{
		rgb.r = diffpoint(coor[i].r, coor[i + 1].r, pourcent);
		rgb.g = diffpoint(coor[i].g, coor[i + 1].g, pourcent);
		rgb.b = diffpoint(coor[i].b, coor[i + 1].b, pourcent);
		diff = (rgb.r * 16777216) + (rgb.g * 65536) + (rgb.b * 256) + 255;
	}
	else
		diff = coor[i].color;
	return (diff);
}
