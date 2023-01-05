/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:44 by kyuuh             #+#    #+#             */
/*   Updated: 2023/01/05 01:32:14 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	printcoor(coords *coor, s_leng leng)
{
	int max;
	int i;

	i = 0;
	max = leng.lines * leng.len;
	while (i < max)
	{
		//printf("x : %d  y : %d\n", coor[i].gridx, coor[i].gridy);
		++i;
	}
}

void	fill(coords **coor, char *file, s_leng leng)
{
	int fd;
	char	**splited;
	char	**intcolor;
	int		x;
	char	*line;
	int		z;

	fd = open(ft_strjoin("./test_maps/", file), O_RDONLY);
	line = get_next_line(fd);
	z = 0;
	while (line)
	{
		x = 0;
		splited = ft_split(line, ' ');
		while (splited[x])
		{
			intcolor = ft_split(splited[x], ',');
			(*coor)[x + (leng.len * z)].x = x;
			(*coor)[x + (leng.len * z)].z = z;
			(*coor)[x + (leng.len * z)].y = ft_atoi(intcolor[0]);
			if (intcolor[1])
			{
				printf("couleur\n");
				(*coor)[x + (leng.len * z)].color = ft_atoi(intcolor[1]);
			}
			else
			{
				printf("BLANC\n");
				(*coor)[x + (leng.len * z)].color = 0xFFFFFF;
			}
			++x;
		}
		line = get_next_line(fd);
		++z;
	}
	close(fd);
}

int	data(char *line)
{
	char	**splited;
	int		n;

	n = 0;
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	while (splited[n])
	{
		++n;
	}
	return (n);
}

int	countlines(s_leng *leng, char *file)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(ft_strjoin("./test_maps/", file), O_RDONLY);
	if (fd == -1)
	{
		printf("Arg Incorrect\n");
		return (0);
	}
	line = get_next_line(fd);
	(*leng).len = data(line);
	while (line)
	{
		line = get_next_line(fd);
		++lines;
	}
	close(fd);
	(*leng).lines = lines;
	return (1);
}

int main(int argc, char **argv)
{
	int		fd;
	coords *coor;
	s_leng	leng;

	if (argc != 2)
	{
		printf("Number of args incorrect\n");
		return (0);
	}
	if (!countlines(&leng,argv[1]))
		return (0);
	coor = malloc(sizeof(coords)* leng.len * leng.lines);
	if (!coor)
	{
		printf("malloc error\n");
		return (0);
	}
	fill(&coor, argv[1], leng);
	printcoor(coor, leng);
	screen(&coor, leng);
	return (0);
}