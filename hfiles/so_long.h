/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:53:47 by bplante           #+#    #+#             */
/*   Updated: 2023/11/07 00:42:32 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define SQ_SIZE 200

typedef enum e_game_state
{
	PLAYING,
	END
}					t_game_state;

typedef enum e_tile_type
{
	WALL,
	EMPTY,
	START,
	EXIT,
	COLLECT,
	ERROR
}					t_tile_type;

typedef struct s_map_data
{
	int				height;
	int				width;
	t_tile_type		**map;
}					t_map_data;

typedef struct s_collectible
{
	int				x;
	int				y;
	int				current_frame;
	int				instance_nb;
	bool			is_collected;

}					t_collectible;

typedef struct s_player
{
	int				x;
	int				y;
	int				current_frame;
}					t_player;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*start;
	mlx_texture_t	*exit;
	mlx_texture_t	*collect_hi;
	mlx_texture_t	**char_frames;
	mlx_texture_t	*coin;
}					t_textures;

typedef struct s_images
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*start;
	mlx_image_t		*exit;
	mlx_image_t		*collect_hi;
	mlx_image_t		**player_frames;
	mlx_image_t		*coin;
}					t_images;

typedef struct s_game
{
	t_map_data		*map_data;
	mlx_t			*mlx;
	t_player		player;
	t_list			*collectables;
	t_images		*images;
	int				collectables_amount;
	int				collected;
	int				move_count;
	t_game_state	game_state;
	double			animate_delay;
}					t_game;

void				init_game(t_game *game);
t_collectible		*init_collectible(int x, int y);
void				free_game(t_game *game);

int					render_map(t_game *game);
int					render_entities(t_game *game);

void				loop_hook(void *param);

t_map_data			*parse_map(char *filepath);
bool				is_map_valid(t_map_data *map_data);
bool				is_map_completable(t_map_data *map_data);

void				load_images(mlx_t *mlx, t_images *images);
void				load_textures(t_textures *textures);
void				unload_textures(t_textures *textures);
void				unload_frame_textures(mlx_texture_t *txt[]);
mlx_texture_t		**load_frames_textures(char *base_path, int frame_amount);

void				move(t_game *game, int x, int y);

#endif
