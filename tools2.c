/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:12:12 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/02 21:41:53 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	move2exit(t_param *param)
{
	if (param->play.count_collect == param->nb_item.nb_collect)
	{
		param->play.exit_flag = 1;
		return (0);
	}
	else
		return (1);
}

void	left_frame(t_param *param)
{
	param->play.tile->type = 0;
	param->play.tile = param->play.tile->left;
	param->play.tile->type = 4;
	if (param->play.last_key_move != 97)
	{
		param->play.framecount = 0;
		param->play.last_key_move = 97;
	}
	if (param->play.framecount % 3 == 0)
		param->play.current_img = IMG_PLAYER_LEFT1;
	if (param->play.framecount % 3 == 1)
		param->play.current_img = IMG_PLAYER_LEFT2;
	if (param->play.framecount % 3 == 2)
		param->play.current_img = IMG_PLAYER_LEFT3;
	param->play.framecount++;
}

void	right_frame(t_param *param)
{
	param->play.tile->type = 0;
	param->play.tile = param->play.tile->right;
	param->play.tile->type = 4;
	if (param->play.last_key_move != 100)
	{
		param->play.framecount = 0;
		param->play.last_key_move = 100;
	}
	if (param->play.framecount % 3 == 0)
		param->play.current_img = IMG_PLAYER_RIGHT1;
	if (param->play.framecount % 3 == 1)
		param->play.current_img = IMG_PLAYER_RIGHT2;
	if (param->play.framecount % 3 == 2)
		param->play.current_img = IMG_PLAYER_RIGHT3;
	param->play.framecount++;
}

void	up_frame(t_param *param)
{
	param->play.tile->type = 0;
	param->play.tile = param->play.tile->up;
	param->play.tile->type = 4;
	if (param->play.last_key_move != 119)
	{
		param->play.framecount = 0;
		param->play.last_key_move = 119;
	}
	if (param->play.framecount % 3 == 0)
		param->play.current_img = IMG_PLAYER_UP1;
	if (param->play.framecount % 3 == 1)
		param->play.current_img = IMG_PLAYER_UP2;
	if (param->play.framecount % 3 == 2)
		param->play.current_img = IMG_PLAYER_UP3;
	param->play.framecount++;
}

void	down_frame(t_param *param)
{
	param->play.tile->type = 0;
	param->play.tile = param->play.tile->down;
	param->play.tile->type = 4;
	if (param->play.last_key_move != 115)
	{
		param->play.framecount = 0;
		param->play.last_key_move = 115;
	}
	if (param->play.framecount % 3 == 0)
		param->play.current_img = IMG_PLAYER_DOWN1;
	if (param->play.framecount % 3 == 1)
		param->play.current_img = IMG_PLAYER_DOWN2;
	if (param->play.framecount % 3 == 2)
		param->play.current_img = IMG_PLAYER_DOWN3;
	param->play.framecount++;
}
