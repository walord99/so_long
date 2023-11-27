/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:41:51 by bplante           #+#    #+#             */
/*   Updated: 2023/11/27 01:03:40 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_font(t_game *game)
{
	int		i;
	char	*fullpath;

	i = 32;
	while (i < 127)
	{
		fullpath = ft_strjoin_free("textures/font/", ft_strjoin_free(ft_itoa(i),
					".png", FREE_S1), FREE_S2);
		if (access(fullpath, R_OK) == 0)
			game->font[i - 32] = mlx_load_png(fullpath);
		free(fullpath);
		i++;
	}
}

void	unload_font(t_game *game)
{
	int	i;

	i = 0;
	while (i < 127 - 32)
	{
		if (game->font[i])
			mlx_delete_texture(game->font[i]);
		i++;
	}
}
