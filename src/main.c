/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/30 23:26:49 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	compare_collect_struct(t_collectible *s1, t_collectible *s2)
{
	if (s1->x == s2->x && s1->y == s2->y)
		return (true);
	return (false);
}

bool	move(t_game *game, int x, int y)
{
	t_collectible	data;
	t_collectible	*collect;

	if (game->map_data->map[x][y] != WALL)
	{
		game->player_x = x;
		game->player_y = y;
		game->images->player_frames[0]->instances->x = x * SQ_SIZE;
		game->images->player_frames[0]->instances->y = y * SQ_SIZE;
		if (game->map_data->map[x][y] == COLLECT)
		{
			data.x = x;
			data.y = y;
			collect = (t_collectible *)ft_lstfind_one((void *)game->collectables,
					(void *)&compare_collect_struct, &data)->content;
			game->images->coin->instances[collect->instance_nb].enabled = false;
		}
		if (game->map_data->map[x][y] == END)
			mlx_close_window(game->mlx);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		x;
	int		y;

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
		move(game, x, y);
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
