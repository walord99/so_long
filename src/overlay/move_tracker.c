/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tracker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:27:20 by bplante           #+#    #+#             */
/*   Updated: 2023/11/27 00:58:00 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_tracker(t_game *game)
{
    game->move_tracker = create_text(game, ft_strdup("0"), SQ_SIZE * 0.15, SQ_SIZE * 0.15);
}

void change_tracker(t_game *game)
{
    destroy_text(game->move_tracker, game->mlx);
	game->move_tracker = create_text(game, ft_itoa(game->move_count), SQ_SIZE * 0.15, SQ_SIZE * 0.15);
}