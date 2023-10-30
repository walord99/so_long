/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:38:14 by bplante           #+#    #+#             */
/*   Updated: 2023/10/29 21:53:15 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile_to_window(t_game *game, t_images *images, int x, int y);

int	render_map(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (x < game->map_data->width)
	{
		y = 0;
		while (y < game->map_data->height)
		{
			put_tile_to_window(game, game->images, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

void	put_tile_to_window(t_game *game, t_images *images, int x, int y)
{
	t_tile_type	map_tile;

	map_tile = game->map_data->map[x][y];
	if (map_tile == WALL)
		mlx_image_to_window(game->mlx, images->wall, x * SQ_SIZE, y * SQ_SIZE);
	else if (map_tile == EMPTY || map_tile == COLLECT)
		mlx_image_to_window(game->mlx, images->floor, x * SQ_SIZE, y * SQ_SIZE);
	else if (map_tile == START)
		mlx_image_to_window(game->mlx, images->start, x * SQ_SIZE, y * SQ_SIZE);
	else
		mlx_image_to_window(game->mlx, images->exit, x * SQ_SIZE, y * SQ_SIZE);
	if (map_tile == COLLECT)
		mlx_image_to_window(game->mlx, images->collect_hi, x * SQ_SIZE, y
			* SQ_SIZE);
}
