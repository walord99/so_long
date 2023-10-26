/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:56:07 by bplante           #+#    #+#             */
/*   Updated: 2023/10/26 02:35:20 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_map_data *map_data);

void	free_game(t_game *game)
{
	if (game->map_data)
		free_map(game->map_data);
	//mlx_terminate(game->mlx);
	free(game);
}

void	free_map(t_map_data *map_data)
{
	int	i;

	i = 0;
	if (map_data->map)
	{
		while (i < map_data->width)
			free(map_data->map[i++]);
		free(map_data->map);
	}
	free(map_data);
}
