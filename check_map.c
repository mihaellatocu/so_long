/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:11:00 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 11:31:49 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_nr_collectables(t_context *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->nr_lines)
	{
		j = 0;
		while (j < ctx->len_line)
		{
			if (ctx->map[i][j] == 'C')
				++ctx->collectables;
			++j;
		}
		++i;
	}
	ctx->total_collectables = ctx->collectables;
	return (ctx->collectables);
}

int	check_exit(t_context *ctx)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (i < ctx->nr_lines)
	{
		j = 0;
		while (j < ctx->len_line)
		{
			if (ctx->map[i][j] == 'E')
				++exit;
			++j;
		}
		++i;
	}
	return (exit);
}

int	check_player(t_context *ctx)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < ctx->nr_lines)
	{
		j = 0;
		while (j < ctx->len_line)
		{
			if (ctx->map[i][j] == 'P')
				++player;
			++j;
		}
		++i;
	}
	return (player);
}

// Function to check if a cell is valid
static	bool	is_valid(t_context *ctx, int row, int col)
{
	return (row >= 0 && row < ctx->nr_lines && col >= 0 && col < ctx->len_line && ctx->temp_map[row][col] != '1');
}

// Flood fill algorithm
bool	flood_fill(t_context *ctx, int row, int col)
{
	int	i;

	i = 0;
	int	dir_row[4] = {-1, 0, 1, 0};
	int	dir_col[4] = {0, 1, 0, -1};

	if (ctx->temp_map[row][col] == 'E')
	{
		//printf ("Found the exit\n");
		ctx->exit++;
		//printf("Exit found from flood fill function %d\n", ctx->exit);
	}
	if (ctx->temp_map[row][col] == 'C')
	{
		//printf("nr of collectables before are:         %d\n", ctx->collectables);
		ctx->collectables--;
		//printf("nr of collectables after finding C is:  %d\n", ctx->collectables);
		// if (ctx->collectables == 0 && exit == 1)
		//     return true;
	}
	ctx->temp_map[row][col] = 'V'; // visited
	//Recursively checking neighboring cells
	while (i < 4)
	{
		int	new_row = row + dir_row[i];
		int	new_col = col + dir_col[i];
		if (is_valid(ctx, new_row, new_col) && ctx->temp_map[new_row][new_col] != 'V')
		{
			if (flood_fill(ctx, new_row, new_col))
				return (true);
		}
		i++;
	}
	return (false);
}
