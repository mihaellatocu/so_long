/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:22:11 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/22 15:14:02 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put(t_context *c, void *img, int j, int i)
{
	mlx_put_image_to_window(c->mlx, c->win, img, j, i);
}

void	load_map(t_context *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->nr_lines)
	{
		j = 0;
		while (j < c->len_line)
		{
			if (c->map[i][j] == '1')
				put(c, c->img_wall, j * 32, i * 32);
			else if (c->map[i][j] == 'E')
				put(c, c->img_exit, j * 32, i * 32);
			else if (c->map[i][j] == 'C')
				put(c, c->img_coin, j * 32, i * 32);
			else if (c->map[i][j] == 'P')
				put(c, c->img_cat, j * 32, i * 32);
			else if (c->map[i][j] == 'N')
				put(c, c->img_devil, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

//Load img on map from path files
void	load_img_map(t_context *c)
{
	c->img_cat = mlx_xpm_file_to_image(c->mlx, c->relative_path, &c->img_width, \
								&c->img_height);
	c->img_empty = mlx_xpm_file_to_image(c->mlx, c->path_empty, &c->img_width, \
								&c->img_height);
	c->img_wall = mlx_xpm_file_to_image(c->mlx, c->path_wall, &c->img_width, \
								&c->img_height);
	c->img_exit = mlx_xpm_file_to_image(c->mlx, c->path_exit, &c->img_width, \
								&c->img_height);
	c->img_coin = mlx_xpm_file_to_image(c->mlx, c->path_coin, &c->img_width, \
								&c->img_height);
	c->img_coin_alt = mlx_xpm_file_to_image(c->mlx, c->path_coin_alt, \
								&c->img_width, &c->img_height);
	c->img_devil = mlx_xpm_file_to_image(c->mlx, c->path_devil, &c->img_width, \
								&c->img_height);
}

int	animation(t_context *c)
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
			{
				mlx_put_image_to_window(c->mlx, c->win, c->img_coin, j * 32, \
					i * 32);
				mlx_do_sync(c->mlx);
				mlx_put_image_to_window(c->mlx, c->win, c->img_coin_alt, \
					j * 32, i * 32);
				mlx_do_sync(c->mlx);
			}
			j++;
		}
		i++;
	}
	return (0);
}
