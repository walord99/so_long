/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:53:43 by bplante           #+#    #+#             */
/*   Updated: 2023/10/31 16:58:04 by bplante          ###   ########.fr       */
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
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map_data->map[x][y] == COLLECT)
			{
				game->collectables = ft_lstadd_back(game->collectables,
						init_collectible(x, y));
				game->collectables_amount++;
			}
			y++;
		}
		x++;
	}
	game->game_state = PLAYING;
}

t_collectible	*init_collectible(int x, int y)
{
	t_collectible	*collectable;

	collectable = ft_calloc(sizeof(t_collectible), 1);
	collectable->x = x;
	collectable->y = y;
	collectable->is_collected = false;
	return (collectable);
}
