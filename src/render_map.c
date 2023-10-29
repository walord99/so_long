/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:38:14 by bplante           #+#    #+#             */
/*   Updated: 2023/10/25 15:13:57 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*start;
	mlx_texture_t	*exit;
	mlx_texture_t	*collect_hi;
}					t_textures;

static t_textures	load_textures(void);
static void			unload_textures(t_textures textures);
static void			put_tile_to_window(t_game *game, t_images *images, int x,
						int y);
static t_images		*get_map_images(mlx_t *mlx);

int	render_map(t_game *game)
{
	int			y;
	int			x;
	t_images	*images;

	images = get_map_images(game->mlx);
	x = 0;
	while (x < game->map_data->width)
	{
		y = 0;
		while (y < game->map_data->height)
		{
			put_tile_to_window(game, images, x, y);
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

t_textures	load_textures(void)
{
	t_textures	textures;

	textures.wall = mlx_load_png("textures/wall1.png");
	textures.floor = mlx_load_png("textures/floor2.png");
	textures.start = mlx_load_png("textures/start1.png");
	textures.exit = mlx_load_png("textures/exit1.png");
	textures.collect_hi = mlx_load_png("textures/collectHighlight.png");
	return (textures);
}

void	unload_textures(t_textures textures)
{
	mlx_delete_texture(textures.exit);
	mlx_delete_texture(textures.start);
	mlx_delete_texture(textures.floor);
	mlx_delete_texture(textures.wall);
}

t_images	*get_map_images(mlx_t *mlx)
{
	t_images	*images;
	t_textures	textures;

	images = ft_calloc(sizeof(t_images), 1);
	textures = load_textures();
	images->wall = mlx_texture_to_image(mlx, textures.wall);
	mlx_resize_image(images->wall, SQ_SIZE, SQ_SIZE);
	images->floor = mlx_texture_to_image(mlx, textures.floor);
	mlx_resize_image(images->floor, SQ_SIZE, SQ_SIZE);
	images->exit = mlx_texture_to_image(mlx, textures.exit);
	mlx_resize_image(images->exit, SQ_SIZE, SQ_SIZE);
	images->start = mlx_texture_to_image(mlx, textures.start);
	mlx_resize_image(images->start, SQ_SIZE, SQ_SIZE);
	images->collect_hi = mlx_texture_to_image(mlx, textures.collect_hi);
	mlx_resize_image(images->collect_hi, SQ_SIZE, SQ_SIZE);
	unload_textures(textures);
	return (images);
}
