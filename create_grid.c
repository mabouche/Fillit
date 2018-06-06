/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:30:51 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/07 15:30:52 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	carre_haut(int p)
{
	int n;

	n = 2;
	while (n * n < p)
		n++;
	return (n);
}

int	**create_grid(int size_grid)
{
	int index;
	int index2;
	int **dest;

	dest = (int **)malloc(sizeof(int) * (size_grid * size_grid));
	if (dest == NULL)
		return (NULL);
	index = 0;
	index2 = 0;
	while (index < size_grid)
	{
		dest[index] = (int*)ft_memalloc(sizeof(int) * size_grid);
		index++;
	}
	return (dest);
}
