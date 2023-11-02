/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_images_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:38:14 by bplante           #+#    #+#             */
/*   Updated: 2023/11/02 14:31:00 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile_to_window(t_game *game, t_images *images, int x, int y);
static void add_frames_to_window(mlx_t *mlx, mlx_image_t *imgs[], int x, int y);

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

int	render_entities(t_game *game)
{
	t_list			*collectables;
	t_collectible	*collectable;

	add_frames_to_window(game->mlx, game->images->player_frames,
		game->player.x * SQ_SIZE, game->player.y * SQ_SIZE);
	collectables = game->collectables;
	while (collectables)
	{
		collectable = (t_collectible *)collectables->content;
		mlx_image_to_window(game->mlx, game->images->coin, collectable->x
			* SQ_SIZE, collectable->y * SQ_SIZE);
		collectable->instance_nb = game->images->coin->count - 1;
		collectables = collectables->next;
	}
	return (0);
}

void add_frames_to_window(mlx_t *mlx, mlx_image_t *imgs[], int x, int y)
{
	int i = 0;
	while(imgs[i])
	{
		mlx_image_to_window(mlx, imgs[i], x, y);
		i++;
	}
	imgs[0]->enabled = true;
}