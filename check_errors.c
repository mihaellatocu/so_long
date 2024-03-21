/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:06 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 18:36:04 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->nr_lines)
	{
		free(c->map[i]);
		free(c->temp_map[i]);
		i++;
	}
	free(c->map);
	free(c->temp_map);
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

void	valid_map(t_context *c)
{
	errno = 22;
	if (!valid_map_len_lines(c))
	{
		perror("\033[1;31mError:\n Map is not rectangular\033[0m");
		free_map(c);
		exit(1);
	}
	if (!valid_map_walls(c))
	{
		perror("\033[1;31mError:\n The frame is incorrect\033[0m");
		free_map(c);
		exit(1);
	}
	if (check_exit(c) != 1)
	{
		perror("\033[1;31mError:\n There are no valid exits\033[0m");
		free_map(c);
		exit(1);
	}
	if (check_nr_collectables(c) == 0)
	{
		perror("\033[1;31mError:\n There are no collectables\033[0m");
		free_map(c);
		exit(1);
	}
}

void	collectables_or_exit_in_reach(t_context *c)
{
	if (check_player(c) != 1)
	{
		perror("\033[1;31mError:\n The nr of players is invalid\033[0m");
		free_map(c);
		exit(1);
	}
	flood_fill (c, c->y, c->x);
	if (c->collectables != 0 || c->exit != 1)
	{
		perror("\033[1;31mError: Player cannot reach to the exit or \
						all collectables.\033[0m");
		free_map(c);
		exit(1);
	}
}
