/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/30 00:55:53 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_move_valid(t_game *game, int x, int y)
{
	if (game->map_data->map[x][y] == WALL)
		return (false);
	else
		return (true);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int x;
	int y;

	game = (t_game *)param;
	x = game->player_x;
	y = game->player_y;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_A)
			x -= 1;
		if (keydata.key == MLX_KEY_D)
			x += 1;
		if (keydata.key == MLX_KEY_W)
			y -= 1;
		if (keydata.key == MLX_KEY_S)
			y += 1;
		if (is_move_valid(game, x, y))
		{
			game->player_x = x;
			game->player_y = y;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		exit;

	game = ft_calloc(sizeof(t_game), 1);
	game->images = ft_calloc(sizeof(t_images), 1);
	game->map_data = parse_map(argv[1]);
	if (game->map_data)
	{
		game->mlx = mlx_init(game->map_data->width * SQ_SIZE,
				game->map_data->height * SQ_SIZE, "so_long", false);
		init_game(game);
		load_images(game->mlx, game->images);
		render_map(game);
		render_entities(game);
		mlx_key_hook(game->mlx, &keyhook, game);
		mlx_loop_hook(game->mlx, &loop_hook, game);
		mlx_loop(game->mlx);
	}
	free_game(game);
}
