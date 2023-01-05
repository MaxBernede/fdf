/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordcolors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:44 by kyuuh             #+#    #+#             */
/*   Updated: 2023/01/05 16:58:52 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	hexavalue(char *c, int x) // give the decimal value for R G or B
{
	int i;
	int ret;
	char *hexa;

	ret = 0;
	hexa = "0123456789ABCDEF";
	i = 0;
	while (hexa[i] && hexa[i] != ft_toupper(c[x]))
		++i;
	ret = (i * 16);
	i = 0;
	while (hexa[i] && hexa[i] != ft_toupper(c[x + 1]))
		++i;
	ret += i;
	return (ret);
}

void	getcolorintfromhexa(char *strcolor, coords **coor, s_leng leng) // fill the colors values
{
	int n;

	n = leng.x + (leng.len * leng.z);
	(*coor)[n].r = hexavalue(strcolor, 2);
	(*coor)[n].g = hexavalue(strcolor, 4);
	(*coor)[n].b = hexavalue(strcolor, 6);
	(*coor)[n].color = ((*coor)[n].r * 256 * 256 * 256) + ((*coor)[n].g * 256 * 256) + ((*coor)[n].b * 256) + 255;
	//printf("R G B %d %d %d total : %d\n",(*coor)[n].r,(*coor)[n].g,(*coor)[n].b,(*coor)[n].color);
}

void	fillcoor(coords **coor, char *splited,  s_leng leng) // fill the coordinates with values and color
{
	char	**intcolor;
	int x; // x z and n to make it easier to read
	int z;
	int n;

	x = leng.x;
	z = leng.z;
	n = x + (leng.len * z);
	intcolor = ft_split(splited, ',');
	(*coor)[n].x = x;
	(*coor)[n].z = z;
	(*coor)[n].y = ft_atoi(intcolor[0]);
	if (intcolor[1])
		getcolorintfromhexa(intcolor[1], coor, leng);
	else
		(*coor)[n].color = 0xFFFFFFFF;
}

void	fill(coords **coor, char *file, s_leng leng)
{
	int		fd;
	char	**splited;
	char	*line;

	fd = open(ft_strjoin("./test_maps/", file), O_RDONLY);
	line = get_next_line(fd);
	leng.z = 0;
	while (line)
	{
		leng.x = 0;
		splited = ft_split(line, ' ');
		while (splited[leng.x])
		{
			fillcoor(coor, splited[leng.x], leng);
			leng.x += 1;
		}
		line = get_next_line(fd);
		leng.z += 1;
	}
	close(fd);
}
