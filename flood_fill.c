/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:12:05 by lsipile           #+#    #+#             */
/*   Updated: 2022/11/13 06:20:44 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include<stddef.h>

int	flood_fill(t_param *param, int i, int j)
{
	if ((i > param -> mapsize.nb_line - 1) || i < 0)
		return (1);
	if ((j > param -> mapsize.nb_column - 1) || j < 0)
		return (1);
	if (param -> map[i][j].chck_fill == 1)
		return (1);
	if (param -> map[i][j].type == 3)
	{
		param -> key_flag = 1;
		return (1);
	}
	if (param->map[i][j].type == 1)
		return (1);
	param -> map[i][j].chck_fill = 1;
	flood_fill(param, i + 1, j);
	flood_fill(param, i - 1, j);
	flood_fill(param, i, j + 1);
	flood_fill(param, i, j - 1);
	return (0);
}

int	check_flood_fill_return(void)
{
	ft_putstr("Error \nInvalid Map - You cannot win\n");
	return (0);
}

int	check_flood_fill(t_param *prm)
{
	int	i;
	int	j;
	int	sum_collect;

	sum_collect = 0;
	prm -> nb_item.nb_exit = 0;
	prm -> key_flag = 0;
	flood_fill(prm, prm-> play.tile -> pos.x, prm -> play.tile -> pos.y);
	i = 0;
	while (i <= prm -> mapsize.nb_line - 1)
	{
		j = 0;
		while (j <= prm -> mapsize.nb_column - 1)
		{
			if (prm -> map[i][j].type == 2 && prm -> map[i][j].chck_fill == 1)
				sum_collect++;
			if (prm -> map[i][j].type == 3 && prm -> map[i][j].chck_fill == 1)
				prm->nb_item.nb_exit++;
			j++;
		}
		i++;
	}
	if ((sum_collect == prm -> nb_item.nb_collect) && (prm -> key_flag == 1))
		return (1);
	return (check_flood_fill_return());
}

void	reset_map_wall(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (i < param->mapsize.nb_line)
	{
		j = 0;
		while (j < param -> mapsize.nb_line)
		{
			if (param -> map[i][j].type == -1)
				param -> map[i][j].type = 1;
			j++;
		}
		i++;
	}
}
