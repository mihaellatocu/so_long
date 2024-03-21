/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:56 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 19:06:08 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "lib/libft.h"
# include <stdbool.h>
# include <errno.h>
# include "get_next_line.h"
# include <string.h>
# include <stdio.h>

typedef struct s_context
{
	void	*mlx;
	void	*win;
	void	*img_cat;
	void	*img_empty;
	void	*img_devil;
	void	*img_coin;
	void	*img_wall;
	void	*img_exit;
	int		img_width;
	int		img_height;
	char	*relative_path;
	char	*path_empty;
	char	*path_devil;
	char	*path_coin;
	char	*path_wall;
	char	*path_exit;
	int		keyhook;
	int		x;
	int		y;
	int		updated_x;
	int		updated_y;
	int		exit_i;
	int		exit_j;
	int		collectables;
	int		total_collectables;
	int		exit;

	int		fd;
	char	*line;
	char	**map;
	char	**temp_map;
	int		len_line;
	int		nr_lines;

	int		moves;
}		t_context;

void	ft_strcpy(char *dst, char *src);
void	validate_args(int argc, char **argv);
int		map_lines(char **argv, t_context *c);
int		valid_map_len_lines(t_context *c);
int		valid_map_walls(t_context *c);
int		check_nr_collectables(t_context *c);
int		check_exit(t_context *c);
int		check_player(t_context *c);
void	valid_map(t_context *c);

bool	flood_fill(t_context *c, int row, int col);
void	collectables_or_exit_in_reach(t_context *c);
void	free_map(t_context *c);
void	load_map(t_context *c);
void	load_img_map(t_context *c);

char	*f_itoa(int nbr);
int		close_window(t_context *c);
int		deal_key(int key, t_context *c);
void	init(char **argv, t_context *c);
void	initialize_directions(int *dir_row, int *dir_col);

void	player_position(t_context *c);

#endif