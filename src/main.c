/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/24 22:55:53 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 512
#define HEIGHT 512

void	keyhook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

int	main(int argc, char *argv[])
{
	t_game *game;
	game = ft_calloc(sizeof(t_game), 1);

	game->map = parse_map(argv[1]);
	if(!game->map)
		return EXIT_FAILURE;
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
	mlx_key_hook(game->mlx, &keyhook, game->mlx);
	render_map(game);
	mlx_image_t *img = mlx_texture_to_image(game->mlx, mlx_load_png("textures/wall1.png"));
	mlx_image_to_window(game->mlx, img, 1, 1);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
}
