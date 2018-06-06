/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:24:33 by arfohrer          #+#    #+#             */
/*   Updated: 2018/05/16 18:01:39 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 676

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	int				s_g;
	int				**grid;
}					t_coord;

int					ft_check_error(char **str);
int					ft_error(char *str);
int					ft_usage(void);
int					**create_grid(int size_grid);
int					**piece_top_left(int **tab);
int					fill_grid(t_coord coord, int ***matrice, int p, int index);
int					carre_haut(int p);
char				**ft_createtab(char *buf, int p);
void				ft_changesharp(char **dest);
int					***ft_fonction2(char **dest, int nbpiece);

#endif
