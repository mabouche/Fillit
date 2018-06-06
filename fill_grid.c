/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:22:54 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/16 17:51:06 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_piece(int **piece, t_coord coord, int **start, int size_grid)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (l <= 3)
	{
		while (c <= 3)
		{
			if (piece[l][c] != 0 && (coord.x + c >= size_grid ||
						coord.y + l >= size_grid))
				return (0);
			if (piece[l][c] != 0 && start[coord.y + l][coord.x + c] != 0)
				return (0);
			c++;
		}
		c = 0;
		l++;
	}
	return (1);
}

int		**fill_piece(int **piece, t_coord coord, int **start)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (l <= 3)
	{
		while (c <= 3)
		{
			if (piece[l][c] != 0)
				start[coord.y + l][coord.x + c] = piece[l][c];
			c++;
		}
		c = 0;
		l++;
	}
	return (start);
}

int		**erase_piece(int piece, int **start, int size_grid)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < size_grid)
	{
		while (x < size_grid)
		{
			if (start[y][x] == piece)
				start[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (start);
}

int		fill_grid(t_coord coord, int ***matrice, int p, int index)
{
	if (index != (p))
	{
		coord.x = 0;
		coord.y = 0;
		while ((coord.x * coord.y) < (coord.s_g * coord.s_g))
		{
			if (test_piece(matrice[index], coord, coord.grid, coord.s_g))
			{
				coord.grid = fill_piece(matrice[index], coord, coord.grid);
				if (fill_grid(coord, matrice, p, ++index) == 1)
					return (1);
				coord.grid = erase_piece(--index + 1, coord.grid, coord.s_g);
			}
			if (coord.x < coord.s_g)
				coord.x++;
			else
			{
				coord.x = 0;
				coord.y++;
			}
		}
		return (0);
	}
	return (1);
}
