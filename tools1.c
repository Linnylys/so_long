/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:24:01 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/01 22:54:43 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include<stddef.h>

size_t	ft_strlen_modif(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	get_nb_item(t_param *param, char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == 'C')
			param -> nb_item.nb_collect++;
		if (str[i] == 'E' )
			param -> nb_item.nb_exit++;
		if (str[i] == 'P')
			param -> nb_item.nb_player++;
		i++;
	}
	return (1);
}

int	check_nb_item(t_param *param)
{
	if (param->nb_item.nb_exit != 1)
		return (0);
	if (param->nb_item.nb_player != 1)
		return (0);
	if (param->nb_item.nb_collect == 0)
		return (0);
	return (1);
}

int	type_convert(char c)
{
	int	res;

	if (c == '1')
		res = 1;
	if (c == '0')
		res = 0;
	if (c == 'C')
		res = 2;
	if (c == 'E')
		res = 3;
	if (c == 'P')
		res = 4;
	return (res);
}

int	game_init(t_param *param)
{
	param->mlx = mlx_init();
	param->play.framecount = 0;
	param->play.exit_flag = 0;
	param->play.current_img = IMG_PLAYER_DOWN1;
	param->play.last_key_move = 115;
	param->play.nb_move = 1;
	param->play.count_collect = 0;
	param->check_border = 1;
	param->nb_item.nb_collect = 0;
	param->nb_item.nb_exit = 0;
	param->nb_item.nb_player = 0;
	param->map = NULL;
	return (1);
}
