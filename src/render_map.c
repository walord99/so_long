/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:38:14 by bplante           #+#    #+#             */
/*   Updated: 2023/10/25 00:01:55 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(t_game *game)
{
	int	y;
	int	x;
    mlx_image_t *img;
    img = mlx_texture_to_image(game->mlx, mlx_load_png("textures/wall1.png"));
    mlx_resize_image(img, SQUARE_SIZE, SQUARE_SIZE);
	x = 0;
	while (x < game->map->width)
	{
		y = 0;
        while(y < game->map->height)
        {
            mlx_image_to_window(game->mlx, img, x * SQUARE_SIZE, y * SQUARE_SIZE);
            y++;
        }
        x++;
	}
}
