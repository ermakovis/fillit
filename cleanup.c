/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:42:35 by tcase             #+#    #+#             */
/*   Updated: 2019/04/21 16:38:56 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		remove_shapes(t_shp **shp)
{
	t_shp		*tmp;
	t_shp		*cur;
	char		**tmparr;
	char		*tmpstr;

	tmp = *shp;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		if (cur->shape)
		{
			tmparr = cur->shape;
			while (*tmparr)
			{
				tmpstr = *tmparr;
				tmparr++;
				free(tmpstr);
			}
		}
		free(cur->shape);

		if (cur)
			free(cur);
	}
	exit (0);
}
