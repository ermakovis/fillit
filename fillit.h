/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:49:22 by tcase             #+#    #+#             */
/*   Updated: 2019/04/21 22:50:07 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define SHP_BUFF 20

typedef struct		s_crd
{
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
}					t_crd;
	
typedef struct		s_shp
{
	char			**shape;
	int				height;
	int				width;
	struct s_shp	*next;
}					t_shp;

int		check_input(char *shape);
void	remove_shapes(t_shp **shp);
int		input(int fd, t_shp **shp);		
int		fillit(int fd);
#endif
