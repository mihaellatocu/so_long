/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:44:51 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/20 19:58:46 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	load_map(t_context *ctx);
//void player_position(t_context *ctx);
//int map_lines(char **argv, t_context *ctx);

void	ft_putnr(char c)
{
	write(1, &c, 1);
}

int close_window(t_context *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->img_cat); // remove cat
	mlx_destroy_image(ctx->mlx, ctx->img_empty); // remove empty image
	mlx_destroy_image(ctx->mlx, ctx->img_wall); // remove walls img
	mlx_destroy_image(ctx->mlx, ctx->img_exit); // remove exit img
	mlx_destroy_image(ctx->mlx, ctx->img_coin); // remove coin img
	mlx_destroy_window(ctx->mlx, ctx->win);
	mlx_destroy_display(ctx->mlx);
	free(ctx->mlx); 
	free_map(ctx);
	//mlx_loop_end(ctx->mlx);
	//return (0);
	exit(1);
}

int deal_key(int key, t_context *ctx)
{
	printf("%d\n", key);
	if (key == XK_Escape)
	{
		mlx_destroy_image(ctx->mlx, ctx->img_cat);
		mlx_destroy_image(ctx->mlx, ctx->img_empty);
		mlx_destroy_image(ctx->mlx, ctx->img_wall); // remove walls img
		mlx_destroy_image(ctx->mlx, ctx->img_exit); // remove exit img
		mlx_destroy_image(ctx->mlx, ctx->img_coin); // remove coin img
		mlx_destroy_window(ctx->mlx, ctx->win);
		mlx_destroy_display(ctx->mlx);
		free(ctx->mlx);
		free_map(ctx);
		exit(1);
	}
	printf("elem harta %c\n", ctx->map[ctx->y/32][ctx->x/32]);
	if(key == XK_Up && ctx->map[ctx->y/32][ctx->x/32] != '1')
	{

		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> y -= 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	if(key == XK_Left)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> x -= 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	if(key == XK_Down)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> y += 32;
		printf("poz y este : %d\n", ctx->y/32);
		printf("poz x este : %d\n", ctx->x/32);
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
		
	}
	if(key == XK_Right)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> x += 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	ctx->moves++;
	printf("\033[1;32mMoves: %d\033[0m\n", ctx->moves);
	return (0);
}

void init(char **argv, t_context *ctx)
{
	(void)argv;
	ctx->mlx = NULL;
	ctx->win = NULL;
	ctx->x = 0;
	ctx->y = 0;
	ctx->len_line = 0;
	ctx->nr_lines = 0;
	ctx->relative_path = "./resources/cat/idle.xpm";
	ctx->path_empty = "./resources/cat/empty.xpm";
	ctx->collectables = 0;
	ctx->exit = 0;
	ctx->moves = 0;
	// ctx->path_devil = "./resources/cat/devil.xpm";
	ctx->path_coin = "./resources/cat/coin.xpm";
	ctx->path_exit = "./resources/cat/exit.xpm";
	ctx->path_wall = "./resources/cat/wall.xpm";
	//map_lines(argv, ctx);
	
	
} 
// check if there is a map and allocate the memory for the maps
int map_lines(char **argv, t_context *ctx)//too many lines
{
	int i;
	char  *line = NULL;

	i = -1;
	ctx->fd = open(argv[1], O_RDONLY);
	if (ctx->fd == -1)
		exit(1);
	while (1)
	{
		line = get_next_line(ctx->fd);
		if (line == NULL)
			break ;
		ctx->nr_lines++;
		free(line);
	}
	close(ctx->fd);
	if (ctx->nr_lines > 0)
	{
		ctx->map = (char**)malloc((sizeof(char*) * ctx->nr_lines));
		ctx->temp_map = (char**)malloc((sizeof(char*) * ctx->nr_lines));
		ctx->fd = open(argv[1], O_RDONLY);
		while(++i < ctx->nr_lines)
		{
			ctx->map[i] = get_next_line(ctx->fd);
			ctx->temp_map[i] = (char *)malloc(1 + (sizeof(char) * ft_strlen(ctx->map[i])));
			ft_strcpy(ctx->temp_map[i], ctx->map[i]);
			printf("%s\n", ctx->temp_map[i]);
		}
		close(ctx->fd);
		printf("\n");
		return (ctx->nr_lines);
	}
	return (0);
}


void player_position(t_context *ctx)
{
	//int **position = NULL;
	int i = 0, j = 0;
	//int counter_player = 0;
	
	while (i < ctx->nr_lines)
	{
		j = 0;
		ctx->len_line = ft_strlen(ctx->map[i]);
		while (j < ctx->len_line )
		{
			if (ctx->map[i][j] == 'P')
			{
				ctx->y = i; //i * 32;
				printf("position line %d ", ctx->y);
				ctx->x = j; //j * 32;
				printf("position column %d\n", ctx->x);
			}
			j++;
		}
		i++;
	}
	//return (0);
}


int main(int argc, char **argv)
{
	t_context ctx;

	validate_args(argc, argv);
	init(argv, &ctx);
	if (argc == 2)
	{
		map_lines(argv, &ctx);//allocate memory both matrics
		valid_map(&ctx);
		player_position(&ctx);
		collectables_or_exit_in_reach(&ctx);

		ctx.mlx = mlx_init();//initiate the connection
		if (ctx.mlx == NULL)
			return (-1);
		ctx.win = mlx_new_window(ctx.mlx, ctx.len_line * 32, ctx.nr_lines * 32 + 100, "Hi So_long");// creating the window
		if (ctx.win == NULL)
			return (free(ctx.mlx), -1);
	
		update_img_size(&ctx); //updating the size of x and Y with 32px
		
		ctx.img_cat = mlx_xpm_file_to_image(ctx.mlx, ctx.relative_path, &ctx.img_width, &ctx.img_height);// ading the player img to a tile
		mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img_cat, ctx.x, ctx.y); // adding the player in a specific place
		
		ctx.img_empty = mlx_xpm_file_to_image(ctx.mlx, ctx.path_empty, &ctx.img_width, &ctx.img_height);// ading empty img to a tile
		
		ctx.img_wall = mlx_xpm_file_to_image(ctx.mlx, ctx.path_wall, &ctx.img_width, &ctx.img_height);//loading wall img
		ctx.img_exit = mlx_xpm_file_to_image(ctx.mlx, ctx.path_exit, &ctx.img_width, &ctx.img_height); //loading exit img
		ctx.img_coin = mlx_xpm_file_to_image(ctx.mlx, ctx.path_coin, &ctx.img_width, &ctx.img_height);
		
		load_map(&ctx);
	
		mlx_hook(ctx.win, 17, 1L << 0, close_window, &ctx);//closing window from x
		
		mlx_key_hook(ctx.win, deal_key, &ctx); // moving the player on map and close with X
		mlx_loop(ctx.mlx); //keeping the window open

		free(ctx.mlx); 
		free_map(&ctx);
		
	}

	
	int i = -1;
	printf(" ------------------  \n");
	while(++i < ctx.nr_lines)
	{
		printf("%s\n", ctx.temp_map[i]);
	}

	return (1);
}
