/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:05:10 by tcase             #+#    #+#             */
/*   Updated: 2019/04/21 22:44:34 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			fillit(int fd)
{
	t_shp		*shapes;
	t_shp		*tmp;
	char		**print;
	int			i;

	i = 0;
	shapes = NULL;	
	input(fd, &shapes);
	tmp = shapes;
	while (tmp)
	{
		print = tmp->shape;
	  	while (*print)
		{
			printf("%s\n", *print);
			print++;
		}
		i++;
		tmp = tmp->next;
	}

	remove_shapes(&shapes);
	return (0);
}
