/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:06:32 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 16:57:39 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 1080
#define HEIGHT 1080
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "./MLX42/include/MLX42/MLX42.h"

typedef struct coor
{
	int	x;
	int	y;
	int	z;
	int	gridx;
	int	gridy;
}	coords;

typedef struct leng
{
	int	len;
	int	lines;
}	s_leng;

void	gridxy(coords **coor, s_leng leng, int scale);
int		screen(coords **coor, s_leng leng);
void	gridline(coords **coor, s_leng leng, mlx_t	*mlx);
int		mathx(coords **coor, int i, int x);

#endif