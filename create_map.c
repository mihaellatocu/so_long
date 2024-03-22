/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:52:29 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/22 11:52:54 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_lines(char **argv, t_context *c)
{
	char	*line;

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
}

// check if there is a map and allocate the memory for the maps
int	map_lines(char **argv, t_context *c)
{
	int		i;

	i = -1;
	count_lines(argv, c);
	if (c->nr_lines > 0)
	{
		c->map = (char **)malloc((sizeof(char *) * c->nr_lines));
		c->temp_map = (char **)malloc((sizeof(char *) * c->nr_lines));
		c->fd = open(argv[1], O_RDONLY);
		while (++i < c->nr_lines)
		{
			c->map[i] = get_next_line(c->fd);
			c->temp_map[i] = (char *)malloc(1 + (sizeof(char) * \
				ft_strlen(c->map[i])));
			ft_strcpy(c->temp_map[i], c->map[i]);
		}
		close(c->fd);
		return (c->nr_lines);
	}
	return (0);
}
