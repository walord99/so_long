/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/18 19:17:41 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 512
#define HEIGHT 512

bool	is_map_rectangle(t_list *lines)
{
	int	width;

	width = ft_strlen(lines->content);
	while (lines = lines->next)
	{
		if (ft_strlen(lines->content) != width)
			return (false);
	}
	return (true);
}

e_tile_type	char_to_tile_type(char c)
{
	if (c = '1')
		return (WALL);
	if (c = '0')
		return (EMPTY);
	if (c = 'P')
		return (START);
	if (c = 'E')
		return (END);
	if (c = 'C')
		return (COLLECT);
	return (ERROR);
}

t_map	*line_to_map(t_list *lines)
{
	t_map	*map;
	int		i;
	int		j;
	char	*content;

	map = ft_calloc(sizeof(t_map), 1);
	map->size.x = ft_strlen(lines->content);
	map->size.y = ft_lstsize(lines);
	map->map = ft_calloc(sizeof(e_tile_type *), map->size.x + 1);
	i = 0;
	while (i < map->size.x)
		map->map[i++] = ft_calloc(sizeof(e_tile_type), map->size.y);
	i = 0;
	j = 0;
	while (lines)
	{
		content = (char *)lines->content;
		while (content[i])
		{
			map->map[i][j] = char_to_tile_type(content[i]);
			i++;
		}
		j++;
	}
	return map;
}

bool	is_map_valid(t_map *map)
{
}

t_list	*get_map_lines(char *filepath)
{
	int		fd;
	char	*line;
	t_list	*lines;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
		close(fd);
	}
	do
	{
		line = get_next_line(fd);
		lines = ft_lstadd_back(NULL, line);
	} while (line);
	close(fd);
	return (lines);
}

// TOFREE map
t_map	*parse_map(char *filepath)
{
	t_list	*lines;
	t_map	*map;

	lines = get_map_lines(filepath);
	if (!is_map_rectangle(lines))
	{
		ft_lstclear(lines, &free);
		return (NULL);
	}
	map = line_to_map(lines);
	ft_lstclear(lines, &free);
	return (map);
}

void	keyhook(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key = MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

int	main(int argc, char *argv[])
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
	mlx_key_hook(mlx, &keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
