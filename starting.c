/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:29:58 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/18 15:49:42 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "fdf.h"

//gcc *.c ./get_next_line/*.c ./libft/*.c

void	printall(int *var, int lines, int len)
{
	int n;
	int x;

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

void	fill(int **var,char *line,int lines, int len)
{
	char **splited;
	int x;
	int add;

	x = 0;
	add = 0;
	splited = ft_split(line, ' ');
	if (!splited)
		return ;
	while (splited[x])
	{
		add = ft_atoi(splited[x]);
		printf("lines len atoi %d %d %d\n",lines, len, add);
		(*var)[x + (lines * len)] = add;
		++x;
	}
}

int	data(char *line)
{
	char **splited;
	int n;

	n = 0;
	splited = ft_split(line, ' ');
	if (!splited)
		return (0);
	while (splited[n])
	{
		++n;
	}
	printf("end of data\n");
	return (n);
}

int main (void)
{
	int		fd;
	char	*line;
	int		lines;
	int		len;
	int		*var;
	int		*activate;

	lines = 0;
	fd = open("./test_maps/42.fdf", O_RDONLY);
	line = get_next_line(fd);
	len = data(line);
	while (line)
	{
		line = get_next_line(fd);
		++lines;
	}
	close(fd);
	var = malloc(lines * len * sizeof(int));
	activate = malloc(lines * len * sizeof(int));
	fd = open("./test_maps/42.fdf", O_RDONLY);
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		fill(&var, line, lines, len);
		//envoyer lines et len en struct pour pouvoir creer la deuxieme string 
		line = get_next_line(fd);
		++lines;
	}
	printf("end of fill\n");
	printall(var, lines, len);
	return (0);
}
