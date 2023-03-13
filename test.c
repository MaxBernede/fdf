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
			fillcoor(coor, splited[all->b], leng);
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