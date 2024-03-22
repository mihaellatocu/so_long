/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:15:18 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/22 15:09:05 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_context *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x * 32, c->y * 32);
	c-> y -= 1;
	mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x * 32, c->y * 32);
	c->moves++;
	if (c->map[c->y][c->x] == 'C')
	{
		c->collectables++;
		c->map[c->y][c->x] = '0';
	}
	if (c->map[c->y][c->x] == 'N')
		close_window(c);
	if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
		close_window(c);
}

static void	move_left(t_context *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x * 32, c->y * 32);
	c-> x -= 1;
	mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x * 32, c->y * 32);
	c->moves++;
	if (c->map[c->y][c->x] == 'C')
	{
		c->collectables++;
		c->map[c->y][c->x] = '0';
	}
	if (c->map[c->y][c->x] == 'N')
		close_window(c);
	if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
		close_window(c);
}

static void	move_down(t_context *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x * 32, c->y * 32);
	c-> y += 1;
	mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x * 32, c->y * 32);
	c->moves++;
	if (c->map[c->y][c->x] == 'C')
	{
		c->collectables++;
		c->map[c->y][c->x] = '0';
	}
	if (c->map[c->y][c->x] == 'N')
		close_window(c);
	if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
		close_window(c);
}

static void	move_right(t_context *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x * 32, c->y * 32);
	c-> x += 1;
	mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x * 32, c->y * 32);
	c->moves++;
	if (c->map[c->y][c->x] == 'C')
	{
		c->collectables++;
		c->map[c->y][c->x] = '0';
	}
	if (c->map[c->y][c->x] == 'N')
		close_window(c);
	if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
		close_window(c);
}

int	deal_key(int key, t_context *c)
{
	char	*a;

	a = ft_itoa(c->moves);
	mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0x000000, a);
	free(a);
	if (c->collectables == c->total_collectables)
		c->map[c->exit_i][c->exit_j] = 'e';
	if (key == XK_Escape)
		close_window(c);
	else if ((key == XK_Up || key == 119) && c->map[c->y - 1][c->x] != '1'
		&& c->map[c->y - 1][c->x] != 'E')
		move_up(c);
	else if ((key == XK_Left || key == 97) && c->map[c->y][c->x - 1] != '1' \
		&& c->map[c->y][c->x - 1] != 'E')
		move_left(c);
	else if ((key == XK_Down || key == 115) && c->map[c->y + 1][c->x] != '1' \
		&& c->map[c->y + 1][c->x] != 'E')
		move_down(c);
	else if ((key == XK_Right || key == 100) && c->map[c->y][c->x + 1] != '1' \
		&& c->map[c->y][c->x + 1] != 'E')
		move_right(c);
	a = ft_itoa(c->moves);
	mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0xffffff, a);
	mlx_string_put(c->mlx, c->win, 5, c->nr_lines * 32 + 50, 0xffffff, "Mvs:");
	return (free(a), 0);
}
