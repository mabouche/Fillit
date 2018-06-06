/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:10:53 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/16 17:11:05 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void		free_grid(int **grid, int p)
{
	int i;

	i = 0;
	while (i < p)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static	int			ft_openreadclose(char *name, char *buf)
{
	int fd;
	int ret;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_error("Failed to open."));
	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		return (ft_error("Failed to read."));
	else if (ret == 0)
		return (ft_error("Nothing to read."));
	else if (ret > 545)
		return (ft_error("More than 26 tetriminos."));
	else if ((ret % 21) - 20 != 0)
		return (ft_error("Too many character."));
	buf[ret] = '\0';
	close(fd);
	return (ret);
}

static	void		print_grid(int **grid, int size_grid, int x, int y)
{
	int index;

	index = 0;
	while (y < size_grid)
	{
		while (x < size_grid)
		{
			if (grid[y][x] == 0)
			{
				ft_putchar('.');
				x++;
			}
			else
			{
				grid[y][x] += 64;
				ft_putchar(grid[y][x]);
				x++;
			}
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

static	void		solver(int ***matrice, int p)
{
	int		index;
	t_coord	coord;

	index = 0;
	while (index < p)
	{
		piece_top_left(matrice[index]);
		index++;
	}
	index = 0;
	coord.s_g = (carre_haut(p * 4));
	coord.grid = create_grid(coord.s_g);
	while (fill_grid(coord, matrice, p, index) == 0)
	{
		free_grid(coord.grid, coord.s_g);
		coord.s_g++;
		coord.grid = create_grid(coord.s_g);
	}
	print_grid(coord.grid, coord.s_g, 0, 0);
}

int					main(int ac, char **av)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**dest;
	int		p;
	int		***matrice;

	if (ac != 2)
		return (ft_usage());
	if ((ret = ft_openreadclose(av[1], buf)) == 0)
		return (0);
	p = (ret - 20) / 21 + 1;
	dest = ft_createtab(buf, p);
	if (!(ft_check_error(dest)))
		return (0);
	ft_changesharp(dest);
	matrice = ft_fonction2(dest, p);
	solver(matrice, p);
	return (0);
}
