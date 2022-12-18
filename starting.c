/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:29:58 by kyuuh             #+#    #+#             */
/*   Updated: 2022/12/18 15:18:12 by kyuuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "fdf.h"


void fill(variables **var,char *line,int lines, int len)
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
		var[x + (lines * len)]->x = x;
		var[x + (lines * len)]->y = lines;
		var[x + (lines * len)]->z = add;
		if (add)
			var[x + (lines * len)]->active = 1;
		else
			var[x + (lines * len)]->active = 0;
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
		printf("%s ",splited[n]);
		++n;
	}
	printf("\n");
	return (n);
}

int main (void)
{
	int		fd;
	char	*line;
	int		lines;
	int		len;
	variables *var;

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
	var = malloc(lines * len * sizeof(variables));
	fd = open("./test_maps/42.fdf", O_RDONLY);
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		fill(&var, line, lines, len);
		line = get_next_line(fd);
		++lines;
	}
	return (0);
}
