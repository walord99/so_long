/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:41:06 by bplante           #+#    #+#             */
/*   Updated: 2023/11/07 00:42:06 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	compare_collect_struct(t_collectible *s1, t_collectible *s2)
{
	if (s1->x == s2->x && s1->y == s2->y)
		return (true);
	return (false);
}

void	game_state_end(t_game *game)
{
	game->game_state = END;
	mlx_close_window(game->mlx);
}

void	move_frames(mlx_image_t *imgs[], int x, int y)
{
	int	i;

	i = 0;
	while (imgs[i])
	{
		imgs[i]->instances->x = x;
		imgs[i]->instances->y = y;
		i++;
	}
}

void	collect(t_game *game, int x, int y)
{
	t_collectible	data;
	t_collectible	*collect;

	data.x = x;
	data.y = y;
	collect = (t_collectible *)ft_lstfind_one((void *)game->collectables,
			(void *)&compare_collect_struct, &data)->content;
	if (!collect->is_collected)
	{
		game->images->coin->instances[collect->instance_nb].enabled = false;
		game->collected++;
		collect->is_collected = true;
	}
}

void	move(t_game *game, int x, int y)
{
	if (game->map_data->map[x][y] == WALL)
		return ;
	game->move_count++;
	ft_printf("%i\n", game->move_count);
	game->player.x = x;
	game->player.y = y;
	move_frames(game->images->player_frames, x * SQ_SIZE, y * SQ_SIZE);
	if (game->map_data->map[x][y] == COLLECT)
		collect(game, x, y);
	if (game->map_data->map[x][y] == EXIT
		&& game->collected == game->collectables_amount)
		game_state_end(game);
}
