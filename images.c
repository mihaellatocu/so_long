/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:22:11 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/20 19:39:54 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void update_img_size(t_context *ctx)
{
	// ctx->updated_x = ctx->x * 32;
	// ctx->updated_y = ctx->y * 32;
	ctx->x *= 32;
	ctx->y *= 32;
}

void	load_map(t_context *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->nr_lines)
	{
		j = 0;
		while (j < ctx->len_line)
		{
			if (ctx->map[i][j] == '1')
			{
				mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_wall, j * 32, i * 32);
			}
			if (ctx->map[i][j] == 'E')
			{
				mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_exit, j * 32, i * 32);
			}
			if (ctx->map[i][j] == 'C')
			{
				mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_coin, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}