/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/03 13:08:41 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
}

int key_hook(int keycode, t_game *game)
{
	printf("%i\n", keycode);
	if (keycode == 65307)
		end_game(game);
}

int mouse_hook(int keycode, t_game *game)
{
	printf("%i\n", keycode);
}

int	main(void)
{
	t_game game;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long!");

	mlx_key_hook(game.win , key_hook, &game);
	mlx_mouse_hook(game.win, mouse_hook, &game);
	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
