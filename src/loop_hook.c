/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:15:54 by bplante           #+#    #+#             */
/*   Updated: 2023/10/30 00:35:36 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
    game->images->player_frames[0]->instances->x = game->player_x * SQ_SIZE;
    game->images->player_frames[0]->instances->y = game->player_y * SQ_SIZE;
    
}
