/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:44 by kyuuh             #+#    #+#             */
/*   Updated: 2023/01/06 00:18:06 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// void	printcoor(coords *coor, s_leng leng)
// {
// 	int	max;
// 	int	i;

// 	i = 0;
// 	max = leng.lines * leng.len;
// 	while (i < max)
// 	{
// 		printf("x : %d  y : %d\n", coor[i].gridx, coor[i].gridy);
// 		++i;
// 	}
// }

// check number of arguments for each line == leng.len
int	data(char *line)
{
	char	**splited;
	int		n;

	n = 0;
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	while (splited[n])
		++n;
	return (n);
}

// check if fd error or if theres no lines
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

int	main(int argc, char **argv)
{
	int		fd;
	coords	*coor;
	s_leng	leng;

	if (argc != 2)
	{
		printf("Number of args incorrect\n");
		return (0);
	}
	if (!countlines(&leng, argv[1]))
		return (0);
	coor = malloc(sizeof(coords) * leng.len * leng.lines);
	if (!coor)
	{
		printf("malloc error\n");
		return (0);
	}
	fill(&coor, argv[1], leng);
	screen(&coor, leng);
	return (0);
}
