/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:46:17 by tcase             #+#    #+#             */
/*   Updated: 2019/04/21 19:50:01 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		check_tetris(char *shape)
{
	int			i;
	int			link;

	i = 0;
	link = 0;
	while (i < 20)
	{
		if (shape[i] == '#')
		{
			if ((i + 1) <= 19 && shape[i + 1] == '#')
				link++;
			if ((i - 1) >= 0 && shape[i - 1] == '#')
				link++;
			if ((i + 5) <= 19 && shape[i + 5] == '#')
				link++;
			if ((i - 5) >= 0 && shape[i - 5] == '#')
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

static int		check_shape(char *shape)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (shape[i])
	{
		if (shape[i] != '#' && shape[i] != '.' && shape[i] != '\n')
			return (0);
		if (shape[i] == '#')
			count++;
		if (shape[4 + i / 5 * 5] != '\n')
			return (0);
		i++;
	}
	if (i != 20 || count != 4)
		return (0);
	return (1);
}

int				check_input(char *shape)
{
	if (!(check_shape(shape)))
		return (0);
	if (!(check_tetris(shape)))
		return (0);
	return (1);
}
