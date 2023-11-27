/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:56:07 by bplante           #+#    #+#             */
/*   Updated: 2023/11/27 01:04:06 by bplante          ###   ########.fr       */
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
	if (game->font)
		unload_font(game);
	if (game->move_tracker)
	{
		free(game->move_tracker->str);
		free(game->move_tracker);
		free(game->move_tracker->chars);
	}
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
