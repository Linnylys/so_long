/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:41:37 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/02 20:57:50 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	move_left(t_param *param)
{
	param->play.nb_move++;
	if (param->play.tile->left->type != 1)
	{
		param->play.prev_tile = param->play.tile;
		if (param->play.tile->left->type == 2)
			param->play.count_collect ++;
		if (param->play.tile->left->type == 3)
		{
			if (move2exit(param) == 1)
				return (0);
		}
		left_frame(param);
	}
	return (0);
}

int	move_right(t_param *param)
{
	param->play.nb_move++;
	if (param->play.tile->right->type != 1)
	{
		param->play.prev_tile = param->play.tile;
		if (param->play.tile->right->type == 2)
			param->play.count_collect ++;
		if (param->play.tile->right->type == 3)
		{
			if (move2exit(param) == 1)
				return (0);
		}
		right_frame(param);
	}
	return (0);
}

int	move_up(t_param *param)
{
	param->play.nb_move++;
	if (param->play.tile->up->type != 1)
	{
		param->play.prev_tile = param->play.tile;
		if (param->play.tile->up->type == 2)
			param->play.count_collect ++;
		if (param->play.tile->up->type == 3)
		{
			if (move2exit(param) == 1)
				return (0);
		}
		up_frame (param);
	}
	return (0);
}

int	move_down(t_param *param)
{
	param->play.nb_move++;
	if (param->play.tile->down->type != 1)
	{
		param->play.prev_tile = param->play.tile;
		if (param->play.tile->down->type == 2)
			param->play.count_collect ++;
		if (param->play.tile->down->type == 3)
		{
			if (move2exit(param) == 1)
				return (0);
		}
		down_frame(param);
	}
	return (0);
}
