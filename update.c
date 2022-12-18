/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:42:35 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/02 22:21:46 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h> 

int	hook_update(t_param *param)
{
	image_re_drawing(param);
	if (param->play.exit_flag == 1)
	{
		ft_putstr("Fin de jeu \n");
		cleaning_and_closure(param);
		exit(0);
	}
	return (1);
}

int	image_re_drawing(t_param *pm)
{
	int		i;
	int		j;
	int		k;
	int		*indice;
	t_image	img;

	indice = malloc(4 * sizeof(int));
	indice[0] = pm->play.prev_tile->pos.x;
	indice[1] = pm->play.prev_tile->pos.y;
	indice[2] = pm->play.tile->pos.x;
	indice[3] = pm->play.tile->pos.y;
	k = 0;
	while (k < 4)
	{
		i = indice[k];
		j = indice[k + 1];
		img = re_drawing_sprite(pm, i, j);
		img2wind(pm, img.ptr, i, j);
		if (img.ptr)
			mlx_destroy_image(pm->mlx, img.ptr);
		k = k + 2;
	}
	free(indice);
	return (0);
}

void	img2wind(t_param *pm, void *ptr, int i, int j)
{
	int	a;
	int	b;

	a = i * BSIZE;
	b = j * BSIZE + 1;
	mlx_put_image_to_window(pm->mlx, pm->win, ptr, b, a);
}
