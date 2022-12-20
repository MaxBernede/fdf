/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:27:51 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 17:18:36 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

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
	printf("o de %d\n", o);
	return (o);
}