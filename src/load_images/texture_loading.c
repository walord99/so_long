/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:10:33 by bplante           #+#    #+#             */
/*   Updated: 2023/11/26 23:29:59 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_textures *txt)
{
	txt->wall = mlx_load_png("textures/wall1.png");
	txt->floor = mlx_load_png("textures/floor2.png");
	txt->start = mlx_load_png("textures/start1.png");
	txt->exit = mlx_load_png("textures/exit1.png");
	txt->collect_hi = mlx_load_png("textures/collectHighlight.png");
	txt->coin = mlx_load_png("textures/coin1.png");
	txt->char_frames = load_frames_textures("textures/charFrames/satyr", 6);
}

void	unload_textures(t_textures *textures)
{
	mlx_delete_texture(textures->exit);
	mlx_delete_texture(textures->start);
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->collect_hi);
	mlx_delete_texture(textures->coin);
	unload_frame_textures(textures->char_frames);
	free(textures->char_frames);
}

mlx_texture_t	**load_frames_textures(char *base_path, int frame_amount)
{
	int				i;
	char			*full_path;
	mlx_texture_t	**txt_ptr;

	txt_ptr = ft_calloc(sizeof(mlx_texture_t *), frame_amount + 1);
	i = 0;
	while (i++ < frame_amount)
	{
		full_path = ft_strjoin_free(base_path, ft_strjoin_free(ft_itoa(i),
					".png", FREE_S1), FREE_S2);
		txt_ptr[i - 1] = mlx_load_png(full_path);
		free(full_path);
	}
	return (txt_ptr);
}

void	unload_frame_textures(mlx_texture_t *txt[])
{
	int	i;

	i = 0;
	while (txt[i])
	{
		mlx_delete_texture(txt[i]);
		i++;
	}
}
