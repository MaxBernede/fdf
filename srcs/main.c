/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 11:18:44 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 13:34:27 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	returnstr(char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
	return (ret);
}

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
	ft_free(splited);
	return (n);
}

// check if fd error or if theres no lines
int	countlines(s_leng *leng, char *file, int lines)
{
	int		fd;
	char	*line;
	char	*files;

	files = ft_strjoin("./test_maps/", file);
	fd = open(files, O_RDONLY);
	if (fd == -1)
	{
		free(files);
		return (returnstr("File incorrect or inaccessible\n", 1));
	}
	line = get_next_line(fd);
	leng->len = data(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++lines;
	}
	free(line);
	close(fd);
	free(files);
	leng->lines = lines;
	return (0);
}

int	main(int argc, char **argv)
{
	coords	*coor;
	s_leng	leng;

	atexit(check_leaks);
	if (argc != 2)
		return (returnstr("Number of args incorrect\n", 1));
	if (countlines(&leng, argv[1], 0))
		return (1);
	coor = malloc(sizeof(coords) * leng.len * leng.lines);
	if (!coor)
		return (returnstr("Malloc error\n", 1));
	fill(coor, argv[1], leng);
	screen(coor, leng);
	free(coor);
	return (0);
}
