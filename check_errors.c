/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:06 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/20 12:58:41 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->nr_lines)
	{
		free(ctx->map[i]);
		free(ctx->temp_map[i]);
		i++;
	}
	free(ctx->map);
	free(ctx->temp_map);
}

void	validate_args(int argc, char **argv)
{
	int	len;

	errno = 22;
	if (argc < 2)
	{
		errno = 2;
		perror("\033[1;35mError:\n Map not provided\033[0m");
		exit(1);
	}
	if (argc != 2)
	{
		perror("\033[1;35mError:\n Multiple arguments\033[0m");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(argv[1], ".ber", len))
	{
		perror("\033[1;35mError:\n The map should be in '.ber' format\033[0m");
		exit(EXIT_FAILURE);
	}
}

void	valid_map(t_context *ctx)
{
	errno = 22;
	if (!valid_map_len_lines(ctx))
	{
		perror("\033[1;31mError:\n Map is not rectangular\033[0m"); // clear the map as well
		free_map(ctx);
		exit(1);
	}
	if (!valid_map_walls(ctx))
	{
		perror("\033[1;31mError:\n The frame is incorrect\033[0m");
		free_map(ctx);
		exit(1);
	}
	if (check_exit(ctx) != 1)
	{
		perror("\033[1;31mError:\n There are no valid exits\033[0m");
		free_map(ctx);
		exit(1);
	}
	if (check_nr_collectables(ctx) == 0)
	{
		perror("\033[1;31mError:\n There are no collectables\033[0m");
		free_map(ctx);
		exit(1);
	}
}

void	collectables_or_exit_in_reach(t_context *ctx)
{
	if (check_player(ctx) != 1)
	{
		perror("\033[1;31mError:\n The nr of players is invalid\033[0m");
		free_map(ctx);
		exit(1);
	}
	flood_fill (ctx, ctx->y, ctx->x);
	printf("collectables: %d | exits:  %d\n", ctx->collectables, ctx->exit);
	if (ctx->collectables != 0 || ctx->exit != 1)
	{
		perror("\033[1;31mError: Player cannot reach to the exit or all collectables.\033[0m");
		free_map(ctx);
		exit(1);
	}
}
