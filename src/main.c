/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:08:28 by bplante           #+#    #+#             */
/*   Updated: 2023/10/03 13:08:41 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img_data	img;
	char *pixel;
	int color = 0x00FF00;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1, 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    pixel = &img.addr[0];
	pixel[0] = 255;
	pixel[1] = 255;
	pixel[2] = 255;
	pixel[3] = 0;
	pixel[4] = 255;
	pixel[5] = 255;
	pixel[6] = 255;
	pixel[7] = 0;
	mlx_put_image_to_window(mlx, mlx_win, img.img, 1, 1);
	mlx_loop(mlx);

}
