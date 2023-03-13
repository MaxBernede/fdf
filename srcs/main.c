/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kyuuh <kyuuh@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 11:18:44 by kyuuh         #+#    #+#                 */
/*   Updated: 2023/03/13 15:41:59 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

// check if fd error or if theres no lines
int	map_data(t_all *all, char *file, int lines)
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
	all->nb_len = count_len_map(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++lines;
	}
	free(line);
	close(fd);
	free(files);
	all->nb_lines = lines;
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;
	coords	*coor;
	s_leng	leng;

	//atexit(check_leaks);
	if (argc != 2)
		return (returnstr("Number of args incorrect\n", 1));
	if (map_data(&all, argv[1], 0))
		return (1);
	coor = malloc(sizeof(coords) * all.nb_len * all.nb_lines);
	if (!coor)
		return (returnstr("Malloc error\n", 1));
	leng.len = all.nb_len;
	leng.lines = all.nb_lines;
	fill(coor, argv[1], leng);
	screen(coor, leng);
	free(coor);
	return (0);
}
