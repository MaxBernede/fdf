/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordcolors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 11:18:44 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 16:16:47 by mbernede      ########   odam.nl         */
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
void	getcolorintfromhexa(char *strcolor, t_all *all)
{
	int	n;

	if (strcolor[ft_strlen(strcolor) - 1] == '\n')
		strcolor[ft_strlen(strcolor) - 1] = '\0';
	n = all->b + (all->nb_len * all->a);
	if (ft_strlen(strcolor) == 4)
	{
		all->coor[n].r = 0;
		all->coor[n].g = 0;
		all->coor[n].b = hexavalue(strcolor, 2);
	}
	else if (ft_strlen(strcolor) == 6)
	{
		all->coor[n].r = 0;
		all->coor[n].g = hexavalue(strcolor, 2);
		all->coor[n].b = hexavalue(strcolor, 4);
	}
	else
	{
		all->coor[n].r = hexavalue(strcolor, 2);
		all->coor[n].g = hexavalue(strcolor, 4);
		all->coor[n].b = hexavalue(strcolor, 6);
	}
	all->coor[n].color = (all->coor[n].r * 16777216) + (all->coor[n].g * 65536) + \
	(all->coor[n].b * 256) + 255;
}

// fill the coordinates with values and color
void	fillcoor(t_all *all, char *splited)
{
	char	**intcolor;
	int		x;
	int		z;
	int		n;

	z = all->a;
	x = all->b;
	n = x + (all->nb_len * z);
	intcolor = ft_split(splited, ',');
	all->coor[n].x = x;
	all->coor[n].z = z;
	all->coor[n].y = ft_atoi(intcolor[0]);
	if (intcolor[1])
		getcolorintfromhexa(intcolor[1], all);
	else
		getcolorintfromhexa("0xFFFFFF", all);
	ft_free(intcolor);
}

void	fill(t_all *all, char *file)
{
	int		fd;
	char	**splited;
	char	*line;
	char	*files;

	files = ft_strjoin("./test_maps/", file);
	fd = open(files, O_RDONLY);
	line = get_next_line(fd);
	all->a = 0;
	while (line)
	{
		all->b = 0;
		splited = ft_split(line, ' ');
		free(line);
		while (splited[all->b])
		{
			fillcoor(all, splited[all->b]);
			all->b += 1;
		}
		ft_free(splited);
		line = get_next_line(fd);
		all->a += 1;
	}
	free(line);
	free(files);
	close(fd);
}
