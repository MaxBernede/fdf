/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordcolors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 11:18:44 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/11 16:36:58 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// give the decimal value for R G or B
int	hexavalue(char *c, int x)
{
	int		i;
	int		ret;
	char	*hexa;

	ret = 0;
	hexa = "0123456789ABCDEF";
	i = 0;
	while (i < 15 && hexa[i] != ft_toupper(c[x]))
		++i;
	ret = (i * 16);
	i = 0;
	while (i < 15 && hexa[i] != ft_toupper(c[x + 1]))
		++i;
	ret += i;
	return (ret);
}

// fill the colors values
void	getcolorintfromhexa(char *strcolor, coords *coor, s_leng leng)
{
	int	n;

	if (strcolor[ft_strlen(strcolor) - 1] == '\n')
		strcolor[ft_strlen(strcolor) - 1] = '\0';
	n = leng.x + (leng.len * leng.z);
	if (ft_strlen(strcolor) == 4)
	{
		coor[n].r = 0;
		coor[n].g = 0;
		coor[n].b = hexavalue(strcolor, 2);
	}
	else if (ft_strlen(strcolor) == 6)
	{
		coor[n].r = 0;
		coor[n].g = hexavalue(strcolor, 2);
		coor[n].b = hexavalue(strcolor, 4);
	}
	else
	{
		coor[n].r = hexavalue(strcolor, 2);
		coor[n].g = hexavalue(strcolor, 4);
		coor[n].b = hexavalue(strcolor, 6);
	}
	coor[n].color = (coor[n].r * 16777216) + (coor[n].g * 65536) + \
	(coor[n].b * 256) + 255;
}

// fill the coordinates with values and color
void	fillcoor(coords *coor, char *splited, s_leng leng)
{
	char	**intcolor;
	int		x;
	int		z;
	int		n;

	x = leng.x;
	z = leng.z;
	n = x + (leng.len * z);
	intcolor = ft_split(splited, ',');
	coor[n].x = x;
	coor[n].z = z;
	coor[n].y = ft_atoi(intcolor[0]);
	if (intcolor[1])
		getcolorintfromhexa(intcolor[1], coor, leng);
	else
		getcolorintfromhexa("0xFFFFFF", coor, leng);
	ft_free(intcolor);
}

void	fill(coords *coor, char *file, s_leng leng)
{
	int		fd;
	char	**splited;
	char	*line;
	char	*files;

	files = ft_strjoin("./test_maps/", file);
	fd = open(files, O_RDONLY);
	line = get_next_line(fd);
	leng.z = 0;
	while (line)
	{
		leng.x = 0;
		splited = ft_split(line, ' ');
		free(line);
		while (splited[leng.x])
		{
			fillcoor(coor, splited[leng.x], leng);
			leng.x += 1;
		}
		ft_free(splited);
		line = get_next_line(fd);
		leng.z += 1;
	}
	free(line);
	free(files);
	close(fd);
}
