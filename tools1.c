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
	while (str[i] != '\n'&& str[i] != 0 )
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

int	check_line(t_param *param, char *str)
{
	int	i;

	i = 0;
	if (param->line_len_flag  == 1)
	{
		param->line_len_flag = 0;
		param->line_len = ft_strlen_modif(str);
		if (param->line_len >= WIN_MAX_LON - 1)
			return(check_line_error_management(0));
	}
	else
	{
		if (param->line_len != ft_strlen_modif(str) || param->line_len_flag == 2)
		{
			if (ft_strlen_modif(str) == 0)
				param->line_len_flag = 2;
			else
				return(check_line_error_management(1));
		}
	}
	return (1);
}

int line_analyse(t_param *param, char *str, int flag)
{
	get_nb_item(param, str);
	if (flag == 1)
		return (check_line(param, str));
	else
		return(0);	
}

int	check_nb_item_and_endline(t_param *param, int i)
{	
	if (param->nb_item.nb_exit != 1)
	{
		ft_putstr("Error \nInvalid Map - No Exit\n");
		return (0);
	}
	if (param->nb_item.nb_player != 1)
	{
		ft_putstr("Error \nInvalid Map - No Player\n");
		return (0);
	}
	if (param->nb_item.nb_collect == 0)
	{
		ft_putstr("Error \nInvalid Map - No Collectible\n");
		return (0);
	}
	if (i >= WIN_MAX_LAR)
	{
		ft_putstr("Error \nInvalid Map - Too Long\n");
		return (0);
	}
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

/*int	game_init(t_param *param)
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
}*/
