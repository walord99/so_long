/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:32:09 by bplante           #+#    #+#             */
/*   Updated: 2023/10/29 22:48:53 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*start;
	mlx_texture_t	*exit;
	mlx_texture_t	*collect_hi;
	mlx_texture_t	*char_frames[6];
	mlx_texture_t	*coin;
}					t_textures;

static t_textures	load_textures(void);
static void			unload_textures(t_textures textures);
static void			get_map_images(mlx_t *mlx, t_images *images);
static mlx_image_t	*texture_to_img_resized(mlx_t *mlx, mlx_texture_t *texture);

void	load_images(mlx_t *mlx, t_images *images)
{
	t_textures	textures;

	textures = load_textures();
	images->wall = texture_to_img_resized(mlx, textures.wall);
	images->floor = texture_to_img_resized(mlx, textures.floor);
	images->exit = texture_to_img_resized(mlx, textures.exit);
	images->start = texture_to_img_resized(mlx, textures.start);
	images->collect_hi = texture_to_img_resized(mlx, textures.collect_hi);
	images->player_frames[0] = texture_to_img_resized(mlx,
			textures.char_frames[0]);
	images->coin = texture_to_img_resized(mlx, textures.coin);
	unload_textures(textures);
}

t_textures	load_textures(void)
{
	t_textures	textures;

	textures.wall = mlx_load_png("textures/wall1.png");
	textures.floor = mlx_load_png("textures/floor2.png");
	textures.start = mlx_load_png("textures/start1.png");
	textures.exit = mlx_load_png("textures/exit1.png");
	textures.collect_hi = mlx_load_png("textures/collectHighlight.png");
	textures.char_frames[0] = mlx_load_png("textures/charFrames/satyr1.png");
	textures.coin = mlx_load_png("textures/coin1.png");
	return (textures);
}

void	unload_textures(t_textures textures)
{
	mlx_delete_texture(textures.exit);
	mlx_delete_texture(textures.start);
	mlx_delete_texture(textures.floor);
	mlx_delete_texture(textures.wall);
	mlx_delete_texture(textures.collect_hi);
	mlx_delete_texture(textures.char_frames[0]);
	mlx_delete_texture(textures.coin);
}

mlx_image_t	*texture_to_img_resized(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, SQ_SIZE, SQ_SIZE);
	return (img);
}
