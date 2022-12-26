/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:00:05 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/04 18:17:44 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h> 

int	gen_window(t_param *param)
{
	int	len_x;
	int	len_y;

	len_x = BSIZE * param->mapsize.nb_column;
	len_y = BSIZE * param->mapsize.nb_line;
	param->win = mlx_new_window(param->mlx, len_x, len_y, "Sauvez les chatons");
	if (param->win == NULL)
		return (0);
	return (1);
}

t_image	drawing_sprite(t_param param, int i, int j)
{
	t_image	img;

	if (param.map[i][j].type == 0)
		img = ft_new_sprite(param.mlx, IMG_EMPTY);
	else if (param.map[i][j].type == 1)
		img = ft_new_sprite(param.mlx, IMG_WALL);
	else if (param.map[i][j].type == 2)
		img = ft_new_sprite(param.mlx, IMG_COLLECT);
	else if (param.map[i][j].type == 3)
		img = ft_new_sprite(param.mlx, IMG_EXIT);
	else if (param.map[i][j].type == 4)
		img = ft_new_sprite(param.mlx, param.play.current_img);
	else
	{
		img = ft_new_sprite(param.mlx, IMG_EMPTY);
		ft_putstr("Error \nPixel type unknown");
	}
	return (img);
}

t_image	re_drawing_sprite(t_param *param, int i, int j)
{
	t_image	img;

	if (param->map[i][j].type == 0)
		img = ft_new_sprite(param->mlx, IMG_EMPTY);
	else if (param->map[i][j].type == 1)
		img = ft_new_sprite(param->mlx, IMG_WALL);
	else if (param->map[i][j].type == 2)
		img = ft_new_sprite(param->mlx, IMG_COLLECT);
	else if (param->map[i][j].type == 3)
		img = ft_new_sprite(param->mlx, IMG_EXIT);
	else if (param->map[i][j].type == 4)
	{
		img = ft_new_sprite(param->mlx, param->play.current_img);
		param->play.tile = &param->map[i][j];
	}
	else
	{
		img = ft_new_sprite(param->mlx, IMG_EMPTY);
		ft_putstr("Error \nPixel type unknown");
	}
	return (img);
}
