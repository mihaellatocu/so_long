/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:22:11 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 18:10:13 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				mlx_put_image_to_window(c->mlx, c->win, c->img_wall, j * 32, i * 32);
			if (c->map[i][j] == 'E')
			{
				mlx_put_image_to_window(c->mlx, c->win, c->img_exit, j * 32, i * 32);
				c->exit_i = i;
				c->exit_j = j;
			}
			if (c->map[i][j] == 'C')
				mlx_put_image_to_window(c->mlx, c->win, c->img_coin, j * 32, i * 32);
			if (c->map[i][j] == 'P')
				mlx_put_image_to_window(c->mlx, c->win, c->img_cat, j * 32, i * 32);
			if (c->map[i][j] == 'N')
				mlx_put_image_to_window(c->mlx, c->win, c->img_devil, j * 32, i * 32);
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
	c->img_devil = mlx_xpm_file_to_image(c->mlx, c->path_devil, &c->img_width, \
								&c->img_height);
}
