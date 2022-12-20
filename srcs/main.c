/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:44 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 12:23:36 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"

void	printcoor(coords coor, int lines, int len)
{
	int	n;
	int	x;

	x = 0;
	while (x < lines)
	{
		n = 0;
		while (n < len)
		{
			printf("%d", var[n + (x * len)]);
			++n;
		}
		printf("\n");
		++x;
	}
}

void	fill(coords **coor, char *file, s_leng leng)
{
	int fd;
	char	**splited;
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
			(*coor)[x + (leng.len * z)].x = x;
			(*coor)[x + (leng.len * z)].z = z;
			(*coor)[x + (leng.len * z)].y = ft_atoi(splited[x]);
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
	printcoor(coor);
	return (0);
}