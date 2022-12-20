/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:06:32 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 11:42:42 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 1080
#define HEIGHT 1080
#include <memory.h>

typedef struct coor
{
	int	x;
	int	y;
	int	z;
	int	gridx;
	int	grixy;
}	coords;

typedef struct leng
{
	int	len;
	int	lines;
}	s_leng;

#endif