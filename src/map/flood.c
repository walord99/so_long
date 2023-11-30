/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:00:09 by bplante           #+#    #+#             */
/*   Updated: 2023/11/30 11:34:06 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_args
{
	int		collect_count;
	bool	exit;
	bool	**is_checked;
}			t_args;

static int	count_collectibles_and_get_start(t_map_data *map_data, int *start_x,
				int *start_y);
static void	map_flood(t_map_data *map_data, t_args *args, int x, int y);
static bool	**create_check_map(t_map_data *map_data);
static void	free_check_map(bool **check_map);

bool	is_map_completable(t_map_data *map_data)
{
	int		collect_count;
	int		start_x;
	int		start_y;
	t_args	args;

	start_x = 0;
	start_y = 0;
	collect_count = count_collectibles_and_get_start(map_data, &start_x,
			&start_y);
	args.collect_count = 0;
	args.exit = false;
	args.is_checked = create_check_map(map_data);
	map_flood(map_data, &args, start_x, start_y);
	free_check_map(args.is_checked);
	if (collect_count == args.collect_count && args.exit == true)
		return (true);
	ft_printf_fd("Error\nMap isn't completable: ", 2);
	if (collect_count != args.collect_count)
		ft_printf_fd("Unreachable collectable(s)\n", 2);
	else
		ft_printf_fd("Unreachable exit\n", 2);
	return (false);
}

int	count_collectibles_and_get_start(t_map_data *map_data, int *start_x,
		int *start_y)
{
	int	collect_count;
	int	x;
	int	y;

	collect_count = 0;
	y = 1;
	while (y < map_data->height - 1)
	{
		x = 1;
		while (x < map_data->width - 1)
		{
			if (map_data->map[x][y] == COLLECT)
				collect_count++;
			if (map_data->map[x][y] == START)
			{
				*start_x = x;
				*start_y = y;
			}
			x++;
		}
		y++;
	}
	return (collect_count);
}

void	map_flood(t_map_data *map_data, t_args *args, int x, int y)
{
	if (map_data->map[x][y] == WALL || args->is_checked[x][y] == true)
		return ;
	else if (map_data->map[x][y] == COLLECT)
		args->collect_count++;
	else if (map_data->map[x][y] == EXIT)
		args->exit = true;
	args->is_checked[x][y] = true;
	map_flood(map_data, args, x + 1, y);
	map_flood(map_data, args, x - 1, y);
	map_flood(map_data, args, x, y + 1);
	map_flood(map_data, args, x, y - 1);
	return ;
}

bool	**create_check_map(t_map_data *map_data)
{
	bool	**is_checked;
	int		i;

	is_checked = ft_calloc(sizeof(bool *), map_data->width + 1);
	i = 0;
	while (i < map_data->width)
		is_checked[i++] = ft_calloc(sizeof(bool), map_data->height);
	return (is_checked);
}

void	free_check_map(bool **check_map)
{
	int	i;
	int	size;

	i = 0;
	size = tab_len((void **)check_map);
	while (i < size)
		free(check_map[i++]);
	free(check_map);
}
