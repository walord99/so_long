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
}

int key_press(int keysym, t_game *game)
{
	printf("key down: %i\n", keysym);
	if (keysym == XK_Escape)
		end_game(game);
}

int key_release(int keysym, t_game *game)
{
	printf("key up: %i\n", keysym);
}

int mouse_hook(int keysym, t_game *game)
{
	printf("mouse: %i\n", keysym);
}

int no_event(t_game *game)
{
	return 0;
}

int	main(void)
{
	t_game game;
	game.mlx = mlx_init();
	if(!game.mlx)
		return 1;
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long!");

	mlx_mouse_hook(game.win, mouse_hook, &game);
	mlx_loop_hook(game.mlx, no_event, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);

	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
