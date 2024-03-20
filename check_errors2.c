/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:33 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/19 19:05:42 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checking if the map is rectangular
int	valid_map_len_lines(t_context *ctx)
{
	int	i;
	int	j;
	int	len_line;

	i = 0;
	j = 0;
	len_line = 0;
	while (i < ctx-> nr_lines)
	{
		len_line = ft_strlen(ctx->map[i]);
		j = i + 1;
		while (j < ctx->nr_lines) // compare with the next line
		{
			if (len_line != ft_strlen(ctx->map[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//checking if the walls are valid
int	valid_map_walls(t_context *ctx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ctx->nr_lines)
	{
		j = 0;
		ctx->len_line = ft_strlen(ctx->map[i]);
		//printf("len line --%d\n", ctx->len_line);
		while (j < ctx->len_line)
		{
			if (ctx->map[0][j] != '1' || ctx->map[i][0] != '1' || \
ctx->map[i][ctx->len_line - 1] != '1' || ctx->map[ctx->nr_lines -1][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
