/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:15:18 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 19:59:13 by mtocu            ###   ########.fr       */
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
	//  char *a = ft_itoa(c->moves);
	//  char *b = ft_strjoin("Moves ", a);
	// free(a);
	// mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0x000000, b); //ft_itoa(c->moves) );
	//free(f_itoa(c->moves));
	if (c->collectables == c->total_collectables)
		c->map[c->exit_i][c->exit_j] = 'e';
	if (key == XK_Escape)
		close_window(c);
	else if ((key == XK_Up || key == 119) && c->map[c->y-1][c->x] != '1' && c->map[c->y-1][c->x] != 'E')
		move_up(c);
	else if ((key == XK_Left || key == 97) && c->map[c->y][c->x -1] != '1' && c->map[c->y][c->x -1] != 'E')
		move_left(c);
	else if ((key == XK_Down || key == 115) && c->map[c->y+1][c->x] != '1' && c->map[c->y+1][c->x] != 'E')
		move_down(c);
	else if ((key == XK_Right || key == 100) && c->map[c->y][c->x + 1] != '1' && c->map[c->y][c->x + 1] != 'E')
		move_right(c);
	printf("\033[1;32mMoves: %d\033[0m\n", c->moves);
	printf("\033[1;32mCollectables: %d\033[0m\n", c->collectables);
	return (0);
}

	//mlx_string_put(c->mlx, c->win, 5, c->nr_lines * 32 + 50, 0xffffff, "Moves:");
	//mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0xffffff, b); //ft_itoa(c->moves) );
	//free(moves);
	//char *a = ft_itoa(c->moves);
	//char *b = ft_strjoin("Moves ", a);
	//free(a);
	//mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0x000000, b); //ft_itoa(c->moves) );