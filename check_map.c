/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:11:00 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/22 15:44:20 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_nr_collectables(t_context *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->nr_lines)
	{
		j = 0;
		while (j < c->len_line)
		{
			if (c->map[i][j] == 'C')
				++c->collectables;
			++j;
		}
		++i;
	}
	c->total_collectables = c->collectables;
	return (c->collectables);
}

int	check_exit(t_context *c)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (i < c->nr_lines)
	{
		j = 0;
		while (j < c->len_line)
		{
			if (c->map[i][j] == 'E')
			{
				c->exit_i = i;
				c->exit_j = j;
				++exit;
			}
			++j;
		}
		++i;
	}
	return (exit);
}

int	check_player(t_context *c)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < c->nr_lines)
	{
		j = 0;
		while (j < c->len_line)
		{
			if (c->map[i][j] == 'P')
				++player;
			++j;
		}
		++i;
	}
	return (player);
}

// Function to check if a cell is valid
static	bool	isval(t_context *c, int row, int col)
{
	return (row >= 0 && row < c->nr_lines && col >= 0 && \
		col < c->len_line && c->temp_map[row][col] != '1');
}

// Flood fill algorithm
bool	flood_fill(t_context *c, int row, int col)
{
	int	i;
	int	dir_row[4];
	int	dir_col[4];
	int	new_row;
	int	new_col;

	i = 0;
	initialize_directions(dir_row, dir_col);
	if (c->temp_map[row][col] == 'E')
		c->exit++;
	if (c->temp_map[row][col] == 'C')
		c->collectables--;
	c->temp_map[row][col] = 'V';
	while (i < 4)
	{
		new_row = row + dir_row[i];
		new_col = col + dir_col[i];
		if (isval(c, new_row, new_col) && c->temp_map[new_row][new_col] != 'V')
		{
			if (flood_fill(c, new_row, new_col))
				return (true);
		}
		i++;
	}
	return (false);
}
