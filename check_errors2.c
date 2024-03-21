/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:33 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 18:37:05 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checking if the map is rectangular
int	valid_map_len_lines(t_context *c)
{
	int	i;
	int	j;
	int	len_line;

	i = 0;
	j = 0;
	len_line = 0;
	while (i < c-> nr_lines)
	{
		len_line = ft_strlen(c->map[i]);
		j = i + 1;
		while (j < c->nr_lines)
		{
			if (len_line != ft_strlen(c->map[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//checking if the walls are valid
int	valid_map_walls(t_context *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < c->nr_lines)
	{
		j = 0;
		c->len_line = ft_strlen(c->map[i]);
		while (j < c->len_line)
		{
			if (c->map[0][j] != '1' || c->map[i][0] != '1' || \
c->map[i][c->len_line - 1] != '1' || c->map[c->nr_lines -1][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
