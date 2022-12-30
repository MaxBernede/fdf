/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:06:32 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/26 17:12:23 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 1080
#define HEIGHT 1080
#define OFX WIDTH/2
#define OFY HEIGHT/3
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
void	gridline(coords **coor, s_leng leng, mlx_t	*mlx, mlx_image_t	**g_img);
int		mathx(coords **coor, int i, int x);
int		mathy(coords **coor, int i, int x, s_leng leng);

#endif