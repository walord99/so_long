/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/11/27 00:41:06 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->player.x;
	y = game->player.y;
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
		move(game, x, y);
	}
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 1)
		return (1);
	game = ft_calloc(sizeof(t_game), 1);
	game->images = ft_calloc(sizeof(t_images), 1);
	game->map_data = parse_map(argv[1]);
	if (game->map_data && is_map_valid(game->map_data))
	{
		game->mlx = mlx_init(game->map_data->width * SQ_SIZE,
				game->map_data->height * SQ_SIZE, "so_long", false);
		init_game(game);
		load_images(game->mlx, game->images);
		load_font(game);
		render_map(game);
		render_entities(game);
		render_tracker(game);
		mlx_key_hook(game->mlx, &keyhook, game);
		mlx_loop_hook(game->mlx, &loop_hook, game);
		mlx_loop(game->mlx);
	}
	free_game(game);
}
