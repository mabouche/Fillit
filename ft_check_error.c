/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:16:20 by arfohrer          #+#    #+#             */
/*   Updated: 2018/05/09 12:12:40 by arfohrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_goodchar(char *str)
{
	int i;
	int point;
	int sharp;
	int newline;

	i = 0;
	point = 0;
	sharp = 0;
	newline = 0;
	while (str[i])
	{
		if (str[i] == '#')
			sharp++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			newline++;
		if ((i + 1) % 5 == 0 && str[i] != '\n')
			return (ft_error("error '\\n'"));
		i++;
	}
	if (sharp != 4 || point != 12 || newline != 4)
		return (ft_error("error"));
	return (1);
}

static int	ft_sharp(char *str)
{
	int	i;
	int touch;

	i = 0;
	touch = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				touch++;
			if (i >= 1 && str[i - 1] == '#')
				touch++;
			if (i <= 14 && str[i + 5] == '#')
				touch++;
			if (i >= 5 && str[i - 5] == '#')
				touch++;
		}
		i++;
	}
	if (touch < 6)
		return (ft_error("error"));
	return (1);
}

int			ft_check_error(char **str)
{
	int i;

	i = 0;
	if (str[0] == NULL)
		return (0);
	while (str[i])
	{
		if (ft_goodchar(str[i]) != 1)
			return (0);
		if (ft_sharp(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
