/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:10:56 by tcase             #+#    #+#             */
/*   Updated: 2019/04/21 22:49:44 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		get_shape_coords(char *shape, t_crd **crd)
{
	int			i;

	i = 0;
	(*crd)->xmin = 4;
	(*crd)->xmax = 0;
	(*crd)->ymin = 4;
	(*crd)->ymax = 0;
	while (i < 20)
	{
		if(shape[i] == '#')
		{
			if ((*crd)->xmin > i % 5)
				(*crd)->xmin = i % 5;
			if ((*crd)->xmax < i % 5)
				(*crd)->xmax = i % 5;
			if ((*crd)->ymin > i / 5)
				(*crd)->ymin = i / 5;
			if ((*crd)->ymax < i / 5)
				(*crd)->ymax = i / 5;
		}
		i++;
	}
	return (1);	
}

static void		create_shape(char *shape, t_shp **new, t_crd *crd, t_shp **shp)
{
	char	**tmp;
	int		i;
	int		y;
	int		ystart;

	i = 0;
	ystart = crd->ymin;
	y = (*new)->height;
	if (!(tmp = (char**)malloc(sizeof(char*) * ((*new)->height + 1))))
		remove_shapes(shp);
	while(i < y)
	{
		if (!(tmp[i] = (char*)malloc((*new)->width + 1)))
			remove_shapes(shp);
		ft_strncpy(tmp[i], &shape[crd->xmin +  (i + ystart) * 5], (*new)->width); 
		i++;
	}
	tmp[i] = 0;
	(*new)->shape = tmp;

}

static int		add_shape(char *shape, t_shp **shp, t_crd *crd)
{
	t_shp	*new;
	t_shp	*tmp;
	
	if (!(new = (t_shp*)malloc(sizeof(t_shp))))
		remove_shapes(shp);	
	new->width = crd->xmax - crd->xmin + 1;
	new->height = crd->ymax - crd->ymin + 1;
	if (!(new->shape = (char**)malloc(sizeof(char*) * (new->height + 1))))
		remove_shapes(shp);
	new->next = NULL;
	create_shape(shape, &new, crd, shp);
	if (!(*shp))
	{
		*shp = new;
		return (1);
	}
	tmp = *shp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

int		input(int fd, t_shp **shp)
{
	char		buff[SHP_BUFF + 1];
	int			ret;
	t_crd		*crd;

	if (!fd || !shp)
		return (0);
	while ((ret = (read(fd, buff, SHP_BUFF + 1))))
	{
		buff[SHP_BUFF] = 0;
		if (!(check_input(buff)))
			return (0);
		if (!(crd = (t_crd*)malloc(sizeof(t_crd))))
			return (0);
		get_shape_coords(buff, &crd);
		add_shape(buff, shp, crd);
		if (crd)
			free(crd);
	}
	return (1);
}
