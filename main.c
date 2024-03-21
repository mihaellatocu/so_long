/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:44:51 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 18:32:38 by mtocu            ###   ########.fr       */
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
	c->path_exit = "./resources/cat/exit.xpm";
	c->path_wall = "./resources/cat/wall.xpm";
}

// check if there is a map and allocate the memory for the maps
int	map_lines(char **argv, t_context *c)
{
	int		i;
	char	*line;

	i = -1;
	line = NULL;
	c->fd = open(argv[1], O_RDONLY);
	if (c->fd == -1)
		exit(1);
	while (1)
	{
		line = get_next_line(c->fd);
		if (line == NULL)
			break ;
		c->nr_lines++;
		free(line);
	}
	close(c->fd);
	if (c->nr_lines > 0)
	{
		c->map = (char **)malloc((sizeof(char *) * c->nr_lines));
		c->temp_map = (char **)malloc((sizeof(char *) * c->nr_lines));
		c->fd = open(argv[1], O_RDONLY);
		while (++i < c->nr_lines)
		{
			c->map[i] = get_next_line(c->fd);
			c->temp_map[i] = (char *)malloc(1 + (sizeof(char) * ft_strlen(c->map[i])));
			ft_strcpy(c->temp_map[i], c->map[i]);
		}
		close(c->fd);
		return (c->nr_lines);
	}
	return (0);
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
		mlx_key_hook(c.win, deal_key, &c);
		mlx_loop(c.mlx);
	}
	return (1);
}

// int deal_key(int key, t_context *c)
// {
// 	//  char *a = ft_itoa(c->moves);
// 	//  char *b = ft_strjoin("Moves ", a);
// 	// free(a);
// 	// mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0x000000, b); //ft_itoa(c->moves) );
// 	//free(f_itoa(c->moves));
// 	if (c->collectables == c->total_collectables)
// 	{
// 		c->map[c->exit_i][c->exit_j] = 'e';
// 	}
// 	printf("total collectables %d\n", c->total_collectables);
// 	if (key == XK_Escape)
// 		close_window(c);
// 	else if((key == XK_Up || key == 119) && c->map[c->y-1][c->x] != '1' && c->map[c->y-1][c->x] != 'E')
// 	{
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x *32, c->y*32);
// 		c-> y -= 1;
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x*32, c->y*32);
// 		c->moves++;
// 		if (c->map[c->y][c->x] == 'C')
// 		{
// 			c->collectables++;
// 			c->map[c->y][c->x] = '0';
// 		}
// 		if (c->map[c->y][c->x] == 'N')
// 			close_window(c);
// 		if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
// 			close_window(c);
// 	}
// 	else if((key == XK_Left || key == 97) && c->map[c->y][c->x -1] != '1' && c->map[c->y][c->x -1] != 'E')
// 	{
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x*32, c->y * 32);
// 		c-> x -= 1;
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x * 32, c->y  * 32);
// 		c->moves++;
// 		if (c->map[c->y][c->x] == 'C')
// 		{
// 			c->collectables++;
// 			c->map[c->y][c->x] = '0';
// 		}
// 		if (c->map[c->y][c->x] == 'N')
// 			close_window(c);
// 		if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
// 			close_window(c);
// 	}
// 	else if((key == XK_Down || key == 115) && c->map[c->y+1][c->x] != '1' && c->map[c->y+1][c->x] != 'E')
// 	{
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x*32, c->y*32);
// 		c-> y += 1;
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x*32, c->y*32);
// 		c->moves++;
// 		if (c->map[c->y][c->x] == 'C')
// 		{
// 			c->collectables++;
// 			c->map[c->y][c->x] = '0';
// 		}
// 		if (c->map[c->y][c->x] == 'N')
// 			close_window(c);
// 		if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
// 			close_window(c);
// 	}
// 	else if((key == XK_Right || key == 100) && c->map[c->y][c->x + 1] != '1' && c->map[c->y][c->x + 1] != 'E')
// 	{
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_empty, c->x * 32, c->y * 32);
// 		c-> x += 1;
// 		mlx_put_image_to_window(c->mlx, c->win, c->img_cat, c->x * 32, c->y * 32);
// 		c->moves++;
// 		if (c->map[c->y][c->x] == 'C')
// 		{
// 			c->collectables++;
// 			c->map[c->y][c->x] = '0';
// 		}
// 		if (c->map[c->y][c->x] == 'N')
// 			close_window(c);
// 		if (c->map[c->y][c->x] == 'e' && (c->collectables == c->total_collectables))
// 			close_window(c);
// 	}
// 	printf("\033[1;32mMoves: %d\033[0m\n", c->moves);
// 	//mlx_string_put(c->mlx, c->win, 5, c->nr_lines * 32 + 50, 0xffffff, "Moves:");
// 	//mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0xffffff, b); //ft_itoa(c->moves) );
// 	//free(moves);
// 	//char *a = ft_itoa(c->moves);
// 	//char *b = ft_strjoin("Moves ", a);
// 	//free(a);
// 	//mlx_string_put(c->mlx, c->win, 45, c->nr_lines * 32 + 50, 0x000000, b); //ft_itoa(c->moves) );
// 	printf("\033[1;32mCollectables: %d\033[0m\n", c->collectables);
// 	return (0);
// }