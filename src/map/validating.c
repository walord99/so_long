/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:03:27 by bplante           #+#    #+#             */
/*   Updated: 2023/11/07 00:47:21 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_map_walled(t_map_data *map_data);
static bool	check_error_msg(int exit_counter, int start_counter);
static bool	exit_start_check(t_map_data *map_data);
static bool	invalid_character_check(t_map_data *map_data);

// TODO make sure map is valid
bool	is_map_valid(t_map_data *map_data)
{
	if (!invalid_character_check(map_data))
		return (false);
	if (!exit_start_check(map_data))
		return (false);
	if (!is_map_walled(map_data))
		return (false);
	if (!is_map_completable(map_data))
		return (false);
	return (true);
}

bool	is_map_walled(t_map_data *map_data)
{
	bool	ret_val;
	int		i;

	ret_val = true;
	i = 0;
	while (i < map_data->width)
	{
		if (map_data->map[i][0] != WALL || map_data->map[i][map_data->height
			- 1] != WALL)
			ret_val = false;
		i++;
	}
	i = 0;
	while (i < map_data->height)
	{
		if (map_data->map[0][i] != WALL || map_data->map[map_data->width
			- 1][i] != WALL)
			ret_val = false;
		i++;
	}
	if (!ret_val)
		ft_printf("Error\nMap isn't walled properly\n");
	return (ret_val);
}

bool	exit_start_check(t_map_data *map_data)
{
	int	exit_counter;
	int	start_counter;
	int	x;
	int	y;

	exit_counter = 0;
	start_counter = 0;
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (map_data->map[x][y] == START)
				start_counter++;
			else if (map_data->map[x][y] == EXIT)
				exit_counter++;
			x++;
		}
		y++;
	}
	return (check_error_msg(exit_counter, start_counter));
}

bool	check_error_msg(int exit_counter, int start_counter)
{
	bool	ret_val;

	ret_val = false;
	if (start_counter == 0)
		ft_printf("Error\nNo starting tile\n");
	else if (start_counter > 1)
		ft_printf("Error\nMore than one starting tile\n");
	else if (exit_counter == 0)
		ft_printf("Error\nNo exit tile\n");
	else
		ret_val = true;
	return (ret_val);
}

bool	invalid_character_check(t_map_data *map_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (map_data->map[x][y] == ERROR)
			{
				ft_printf("Error\nInvalid character at (%i, %i)\n", x, y);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
