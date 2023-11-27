/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:27:21 by bplante           #+#    #+#             */
/*   Updated: 2023/11/27 00:58:44 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	resize_char(mlx_image_t *img);

t_text	*create_text(t_game *game, char *str, int x, int y)
{
	t_text	*text;
	int		i;
	int		j;

	text = ft_calloc(sizeof(t_text), 1);
	if (!text || ft_strlen(str) == 0)
		return (NULL);
	text->str = str;
	text->chars = ft_calloc(sizeof(mlx_image_t *), ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (game->font[str[i] - 32])
		{
			text->chars[j] = mlx_texture_to_image(game->mlx, game->font[str[i]
					- 32]);
			resize_char(text->chars[j]);
			mlx_image_to_window(game->mlx, text->chars[j], x, y);
			x += text->chars[j++]->width + SQ_SIZE * 0.05;
		}
		i++;
	}
	return (text);
}

void	destroy_text(t_text *text, mlx_t *mlx)
{
	int i = 0;
	while(text->chars[i])
		mlx_delete_image(mlx, text->chars[i++]);
	free(text->chars);
	free(text->str);
	free(text);
}

void	resize_char(mlx_image_t *img)
{
	mlx_resize_image(img, (SQ_SIZE * TEXT_RATIO / img->height * img->width),
		SQ_SIZE * TEXT_RATIO);
}
