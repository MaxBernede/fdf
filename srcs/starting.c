/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:29:58 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/20 11:23:03 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"


//gcc *.c ./get_next_line/*.c ./libft/*.c

// void	printall(int *var, int lines, int len)
// {
// 	int	n;
// 	int	x;

// 	x = 0;
// 	while (x < lines)
// 	{
// 		n = 0;
// 		while (n < len)
// 		{
// 			printf("%d", var[n + (x * len)]);
// 			++n;
// 		}
// 		printf("\n");
// 		++x;
// 	}
// }

// void	fill(int **var, int **activate, char *line, s_leng leng)
// {
// 	char	**splited;
// 	int		x;
// 	int		add;

// 	x = 0;
// 	add = 0;
// 	splited = ft_split(line, ' ');
// 	if (!splited)
// 		return ;
// 	while (splited[x])
// 	{
// 		add = ft_atoi(splited[x]);
// 		(*var)[x + (leng.lines * leng.len)] = add;
// 		(*activate)[x + (leng.lines * leng.len)] = add;
// 		++x;
// 	}
// }

// int	data(char *line)
// {
// 	char	**splited;
// 	int		n;

// 	n = 0;
// 	splited = ft_split(line, ' ');
// 	if (!splited)
// 		return (0);
// 	while (splited[n])
// 	{
// 		++n;
// 	}
// 	//printf("end of data\n");
// 	return (n);
// }

// void	countlines(s_leng *leng)
// {
// 	int		fd;
// 	int		lines;
// 	char	*line;

// 	lines = 0;
// 	fd = open("./test_maps/42.fdf", O_RDONLY);
// 	line = get_next_line(fd);
// 	(*leng).len = data(line);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		++lines;
// 	}
// 	close(fd);
// 	(*leng).lines = lines;
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	s_leng	leng;	
// 	int		*var;
// 	int		*activate;

// 	countlines(&leng);
// 	var = malloc(leng.lines * leng.len * sizeof(int));
// 	activate = malloc(leng.lines * leng.len * sizeof(int));
// 	fd = open("./test_maps/42.fdf", O_RDONLY);
// 	line = get_next_line(fd);
// 	leng.lines = 0;
// 	while (line)
// 	{
// 		fill(&var, &activate, line, leng);
// 		line = get_next_line(fd);
// 		++leng.lines;
// 	}
// 	//printf("end of fill\n");
// 	printall(var, leng.lines, leng.len);
// 	return (0);
// }
