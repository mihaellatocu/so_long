/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:44:51 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/22 14:46:10 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_context *c)
{
	mlx_destroy_image(c->mlx, c->img_cat);
	mlx_destroy_image(c->mlx, c->img_empty);
	mlx_destroy_image(c->mlx, c->img_wall);
	mlx_destroy_image(c->mlx, c->img_exit);
	mlx_destroy_image(c->mlx, c->img_coin);
	mlx_destroy_image(c->mlx, c->img_coin_alt);
	mlx_destroy_image(c->mlx, c->img_devil);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	free_map(c);
	exit(1);
}

void	init(char **argv, t_context *c)
{
	(void)argv;
	c->mlx = NULL;
	c->win = NULL;
	c->x = 0;
	c->y = 0;
	c->updated_x = 0;
	c->updated_y = 0;
	c->len_line = 0;
	c->nr_lines = 0;
	c->relative_path = "./resources/cat/idle.xpm";
	c->path_empty = "./resources/cat/empty.xpm";
	c->collectables = 0;
	c->total_collectables = 0;
	c->exit = 0;
	c->moves = 0;
	c->path_devil = "./resources/cat/devil.xpm";
	c->path_coin = "./resources/cat/coin.xpm";
	c->path_coin_alt = "./resources/cat/coin_alt.xpm";
	c->path_exit = "./resources/cat/exit.xpm";
	c->path_wall = "./resources/cat/wall.xpm";
}

void	player_position(t_context *c)
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
			if (c->map[i][j] == 'P')
			{
				c->y = i;
				c->x = j;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_context	c;

	validate_args(argc, argv);
	init(argv, &c);
	if (argc == 2)
	{
		map_lines(argv, &c);
		valid_map(&c);
		player_position(&c);
		collectables_or_exit_in_reach(&c);
		c.mlx = mlx_init();
		if (c.mlx == NULL)
			return (-1);
		c.win = mlx_new_window(c.mlx, c.len_line * 32, \
					c.nr_lines * 32 + 100, "So_long");
		if (c.win == NULL)
			return (free(c.mlx), -1);
		load_img_map(&c);
		load_map(&c);
		mlx_hook(c.win, 17, 1L << 0, close_window, &c);
		mlx_loop_hook(c.mlx, animation, &c);
		mlx_key_hook(c.win, deal_key, &c);
		mlx_loop(c.mlx);
	}
	return (1);
}
