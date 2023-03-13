/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colorpoint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 17:49:51 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 15:46:44 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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
		rgb.r = grad_diff(coor[i].r, coor[i - leng.len].r, pourcent);
		rgb.g = grad_diff(coor[i].g, coor[i - leng.len].g, pourcent);
		rgb.b = grad_diff(coor[i].b, coor[i - leng.len].b, pourcent);
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
		rgb.r = grad_diff(coor[i].r, coor[i + 1].r, pourcent);
		rgb.g = grad_diff(coor[i].g, coor[i + 1].g, pourcent);
		rgb.b = grad_diff(coor[i].b, coor[i + 1].b, pourcent);
		diff = (rgb.r * 16777216) + (rgb.g * 65536) + (rgb.b * 256) + 255;
	}
	else
		diff = coor[i].color;
	return (diff);
}
