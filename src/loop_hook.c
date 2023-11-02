/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:54 by bplante           #+#    #+#             */
/*   Updated: 2023/11/02 15:49:38 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate(t_game *game, t_list *coll_list)
{
	t_collectible	*coll;

	game->animate_delay += game->mlx->delta_time;
	if (game->animate_delay < 0.2)
		return ;
	while (coll_list)
	{
		coll_list = coll_list->next;
	}
	game->images->player_frames[game->player.current_frame]->enabled = false;
	game->player.current_frame = (game->player.current_frame + 1) % 6;
	game->images->player_frames[game->player.current_frame]->enabled = true;
	game->animate_delay = 0;
}

void	loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->game_state == PLAYING)
		animate(game, game->collectables);
}
