/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:32:09 by bplante           #+#    #+#             */
/*   Updated: 2023/11/06 19:20:30 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*texture_to_img_resized(mlx_t *mlx, mlx_texture_t *texture);

mlx_image_t	**load_frame_imgs(mlx_t *mlx, mlx_texture_t *txt[])
{
	int			i;
	mlx_image_t	**img;

	img = ft_calloc(sizeof(mlx_image_t *), ptr_arrlen((void **)txt) + 1);
	i = 0;
	while (txt[i])
	{
		img[i] = texture_to_img_resized(mlx, txt[i]);
		img[i]->enabled = false;
		i++;
	}
	return (img);
}

void	load_images(mlx_t *mlx, t_images *images)
{
	t_textures	textures;

	load_textures(&textures);
	images->wall = texture_to_img_resized(mlx, textures.wall);
	images->floor = texture_to_img_resized(mlx, textures.floor);
	images->exit = texture_to_img_resized(mlx, textures.exit);
	images->start = texture_to_img_resized(mlx, textures.start);
	images->collect_hi = texture_to_img_resized(mlx, textures.collect_hi);
	images->coin = texture_to_img_resized(mlx, textures.coin);
	images->player_frames = load_frame_imgs(mlx, textures.char_frames);
	unload_textures(&textures);
}

mlx_image_t	*texture_to_img_resized(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, SQ_SIZE, SQ_SIZE);
	return (img);
}
