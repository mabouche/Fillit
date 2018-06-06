/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:47:29 by arfohrer          #+#    #+#             */
/*   Updated: 2018/05/16 17:12:06 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_createtab(char *buf, int p)
{
	unsigned int	index;
	unsigned int	index2;
	char			**dest;
	int				n;

	index = 0;
	index2 = 0;
	n = 0;
	dest = (char **)ft_memalloc(sizeof(buf) * ft_strlen(buf));
	if (dest == NULL)
		return (0);
	dest[p] = NULL;
	dest[index] = ft_strsub(buf, n, 20);
	n = 21;
	index2 += 21;
	index++;
	while (buf[index2 - 1])
	{
		dest[index] = ft_strsub(buf, n, 20);
		n += 21;
		index++;
		index2 += 21;
	}
	dest[index] = ft_strsub(buf, n, 19);
	return (dest);
}

void	ft_changesharp(char **dest)
{
	int index;
	int index2;
	int number;

	index = 0;
	index2 = 0;
	number = 49;
	while (dest[index])
	{
		while (dest[index][index2])
		{
			if (dest[index][index2] == '#')
				dest[index][index2] = number;
			if (dest[index][index2] == '.')
				dest[index][index2] = '0';
			index2++;
		}
		index2 = 0;
		number++;
		index++;
	}
}

void	ft_fonction(char *piece, int **matrice)
{
	int index;
	int c;
	int l;

	index = 0;
	l = 0;
	while (piece[index])
	{
		if (!(matrice[l] = (int*)malloc(sizeof(**matrice) * 4)))
			return ;
		c = 0;
		while (piece[index] != '\n')
		{
			matrice[l][c] = piece[index] - '0';
			c++;
			index++;
		}
		l++;
		index++;
	}
}

int		***ft_fonction2(char **dest, int nbpiece)
{
	int ***matrice;
	int index;

	index = 0;
	if (!(matrice = (int***)malloc(sizeof(*matrice) * nbpiece)))
		return (NULL);
	while (dest[index])
	{
		if (!(matrice[index] = (int**)malloc(sizeof(**matrice) * 5)))
			return (NULL);
		ft_fonction(dest[index], matrice[index]);
		index++;
	}
	return (matrice);
}
