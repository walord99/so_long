/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:56:07 by bplante           #+#    #+#             */
/*   Updated: 2023/11/02 14:10:31 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_map_data *map_data);

void	free_game(t_game *game)
{
	if (game->map_data)
		free_map(game->map_data);
	if (game->mlx)
		mlx_terminate(game->mlx);
	game->collectables = ft_lstclear(game->collectables, &free);
	if (game->images)
		free(game->images->player_frames);
	free(game->images);
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
