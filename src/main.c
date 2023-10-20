/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/20 18:55:43 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 512
#define HEIGHT 512

void	keyhook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key = MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

int	main(int argc, char *argv[])
{
	mlx_t	*mlx;
	t_map	*map;

	map = parse_map(argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
	mlx_key_hook(mlx, &keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
