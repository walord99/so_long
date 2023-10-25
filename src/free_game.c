/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:56:07 by bplante           #+#    #+#             */
/*   Updated: 2023/10/25 14:04:57 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	if (game->map_data)
	{
		if (game->map_data->map)
			free(game->map_data->map);
		free(game->map_data);
	}
	mlx_terminate(game->mlx);
	free(game);
}
