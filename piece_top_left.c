/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_top_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:00:23 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/07 11:00:24 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		top_max(int **tab)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (c <= 3)
	{
		if ((tab[l][c] != 0))
			return (1);
		c++;
	}
	return (0);
}

int		left_max(int **tab)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (l <= 3)
	{
		if ((tab[l][c] != 0))
			return (1);
		l++;
	}
	return (0);
}

void	put_left(int **tab)
{
	int i;

	i = left_max(tab);
	while (i == 0)
	{
		tab[0][0] = tab[0][1];
		tab[1][0] = tab[1][1];
		tab[2][0] = tab[2][1];
		tab[3][0] = tab[3][1];
		tab[0][1] = tab[0][2];
		tab[1][1] = tab[1][2];
		tab[2][1] = tab[2][2];
		tab[3][1] = tab[3][2];
		tab[0][2] = tab[0][3];
		tab[1][2] = tab[1][3];
		tab[2][2] = tab[2][3];
		tab[3][2] = tab[3][3];
		tab[0][3] = 0;
		tab[1][3] = 0;
		tab[2][3] = 0;
		tab[3][3] = 0;
		i = left_max(tab);
	}
}

void	put_top(int **tab)
{
	int i;

	i = top_max(tab);
	while (i == 0)
	{
		tab[0][0] = tab[1][0];
		tab[0][1] = tab[1][1];
		tab[0][2] = tab[1][2];
		tab[0][3] = tab[1][3];
		tab[1][0] = tab[2][0];
		tab[1][1] = tab[2][1];
		tab[1][2] = tab[2][2];
		tab[1][3] = tab[2][3];
		tab[2][0] = tab[3][0];
		tab[2][1] = tab[3][1];
		tab[2][2] = tab[3][2];
		tab[2][3] = tab[3][3];
		tab[3][0] = 0;
		tab[3][1] = 0;
		tab[3][2] = 0;
		tab[3][3] = 0;
		i = top_max(tab);
	}
}

int		**piece_top_left(int **tab)
{
	if (left_max(tab) == 0)
		put_left(tab);
	if (top_max(tab) == 0)
		put_top(tab);
	return ((int **)tab);
}
