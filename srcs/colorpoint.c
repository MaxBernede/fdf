/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:49:51 by kyuuh             #+#    #+#             */
/*   Updated: 2023/01/05 22:12:36 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

int		diffpoint(int rstart, int rend, float pourcent)
{
	int diff;
	int ret;

	diff = rstart - rend;
	ret = rstart - (diff * pourcent/100);
	return (ret);
}

uint	colorpoint(coords **coor, int i, int x) // find the right color for each pixel printed in linex or liney
{
	uint diff;
	float pourcent;
	float m;
	s_colors rgb;

	m = (float)(*coor)[i + 1].gridx - (float)(*coor)[i].gridx;
	diff = (*coor)[i + 1].color - (*coor)[i].color;
	pourcent = (float)x / m * 100;
	if (diff)
	{
		rgb.r = diffpoint((*coor)[i].r, (*coor)[i + 1].r, pourcent);
		rgb.g = diffpoint((*coor)[i].g, (*coor)[i + 1].g, pourcent);
		rgb.b = diffpoint((*coor)[i].b, (*coor)[i + 1].b, pourcent);
		// printf("values r g b %d %d %d\n",(*coor)[i].r, (*coor)[i].g, (*coor)[i].b);
		// printf("diff entre r g b %d %d %d\n",rgb.r, rgb.g, rgb.b);
		diff = (rgb.r * 256 * 256 * 256) + (rgb.g * 256 * 256)  + (rgb.b * 256) + 255;
	}
	else
		diff = (*coor)[i].color;
	return (diff);
}
