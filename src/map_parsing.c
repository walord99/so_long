/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:54:46 by bplante           #+#    #+#             */
/*   Updated: 2023/10/25 14:07:28 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool			is_map_rectangle(t_list *lines);
static e_tile_type	char_to_tile_type(char c);
static t_map_data	*line_to_map(t_list *lines);
static t_list		*get_map_lines(char *filepath);

// TOFREE map
t_map_data	*parse_map(char *filepath)
{
	t_list		*lines;
	t_map_data	*map;

	lines = get_map_lines(filepath);
	if (!lines)
	{
		if (errno == 0)
			ft_printf("Error\nMap file is empty\n");
		return (NULL);
	}
	if (!is_map_rectangle(lines))
	{
		ft_printf("Error\nMap isn't rectangular\n");
		ft_lstclear(lines, &free);
		return (NULL);
	}
	map = line_to_map(lines);
	lines = ft_lstclear(lines, &free);
	return (map);
}

t_list	*get_map_lines(char *filepath)
{
	int		fd;
	char	*line;
	t_list	*lines;

	lines = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nopen");
		return (NULL);
		close(fd);
	}
	while (line || !lines)
	{
		line = get_next_line(fd, false);
		if (line)
			lines = ft_lstadd_back(lines, line);
	}
	close(fd);
	return (lines);
}

bool	is_map_rectangle(t_list *lines)
{
	int	width;

	width = ft_strlen((char *)lines->content);
	while (lines == lines->next)
	{
		if (ft_strlen((char *)lines->content) != width)
			return (false);
	}
	return (true);
}

e_tile_type	char_to_tile_type(char c)
{
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (EMPTY);
	if (c == 'P')
		return (START);
	if (c == 'E')
		return (END);
	if (c == 'C')
		return (COLLECT);
	return (ERROR);
}

t_map_data	*line_to_map(t_list *lines)
{
	t_map_data	*map;
	int			i;
	int			j;
	char		*content;

	map = ft_calloc(sizeof(t_map_data), 1);
	map->width = ft_strlen(lines->content);
	map->height = ft_lstsize(lines);
	map->map = ft_calloc(sizeof(e_tile_type *), map->width + 1);
	i = 0;
	while (i < map->width)
		map->map[i++] = ft_calloc(sizeof(e_tile_type), map->height);
	j = 0;
	while (lines)
	{
		i = 0;
		content = (char *)lines->content;
		while (content[i++])
			map->map[i - 1][j] = char_to_tile_type(content[i - 1]);
		j++;
		lines = lines->next;
	}
	return (map);
}
