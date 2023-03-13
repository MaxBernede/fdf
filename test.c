void	linex(t_all *all, int i)
{
	t_nb	nb;
	uint	color;

	nb.x = 0;
	while ((nb.x + all->coor[i].gridx) != all->coor[i + 1].gridx)
	{
		nb.y = 0;
		nb.ymth = mathx(all, i, nb.x);
		nb.ynxt = mathx(all, i, nb.x + 1);
		color = colorpoint(all->coor, i, nb.x);
		while ((nb.y + nb.ymth) != nb.ynxt)
		{
			mlx_put_pixel(all->g_img, nb.x + all->coor[i].gridx, \
			all->coor[i].gridy + nb.ymth + nb.y, color);
			if ((nb.y + nb.ymth) < nb.ynxt)
				++nb.y;
			else if ((nb.y + nb.ymth) > nb.ynxt)
				--nb.y;
		}
		mlx_put_pixel(all->g_img, nb.x + all->coor[i].gridx, \
		all->coor[i].gridy + nb.ymth + nb.y, color);
		if (all->coor[i].gridx < all->coor[i + 1].gridx)
			++nb.x;
		else
			--nb.x;
	}
}