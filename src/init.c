/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:53:43 by bplante           #+#    #+#             */
/*   Updated: 2023/10/29 21:48:15 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_data->width)
	{
		y = 0;
		while (y < game->map_data->height)
		{
			if (game->map_data->map[x][y] == START)
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map_data->map[x][y] == COLLECT)
			{
				game->collectables = ft_lstadd_back(game->collectables,
						init_collectible(x, y));
			}
			y++;
		}
		x++;
	}
}

t_collectible	*init_collectible(int x, int y)
{
	t_collectible	*collectable;

	collectable = ft_calloc(sizeof(t_collectible), 1);
	collectable->x = x;
	collectable->y = y;
	return (collectable);
}
