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
}					t_textures;

static t_textures	load_textures(void);
static void			unload_textures(t_textures textures);
static mlx_image_t	*select_image(t_game *game, t_textures textures,
						t_tile_type map_tile);

int	render_map(t_game *game)
{
	int			y;
	int			x;
	t_textures	textures;

	textures = load_textures();
	x = 0;
	while (x < game->map_data->width)
	{
		y = 0;
		while (y < game->map_data->height)
		{
			mlx_image_to_window(game->mlx, select_image(game, textures,
					game->map_data->map[x][y]), x * SQ_SIZE, y * SQ_SIZE);
			y++;
		}
		x++;
	}
	unload_textures(textures);
	return (0);
}

mlx_image_t	*select_image(t_game *game, t_textures textures,
		t_tile_type map_tile)
{
	mlx_image_t	*img;

	if (map_tile == WALL)
		img = mlx_texture_to_image(game->mlx, textures.wall);
	else if (map_tile == EMPTY || map_tile == COLLECT)
		img = mlx_texture_to_image(game->mlx, textures.floor);
	else if (map_tile == START)
		img = mlx_texture_to_image(game->mlx, textures.start);
	else
		img = mlx_texture_to_image(game->mlx, textures.exit);
	mlx_resize_image(img, SQ_SIZE, SQ_SIZE);
	return (img);
}

t_textures	load_textures(void)
{
	t_textures	textures;

	textures.wall = mlx_load_png("textures/wall1.png");
	textures.floor = mlx_load_png("textures/floor2.png");
	textures.start = mlx_load_png("textures/start1.png");
	textures.exit = mlx_load_png("textures/exit1.png");
	return (textures);
}

void	unload_textures(t_textures textures)
{
	mlx_delete_texture(textures.exit);
	mlx_delete_texture(textures.start);
	mlx_delete_texture(textures.floor);
	mlx_delete_texture(textures.wall);
}