/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:34:19 by lsipile           #+#    #+#             */
/*   Updated: 2022/11/13 06:50:20 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include<stddef.h>

int	argument_problem(int i)
{
	if (i == 0)
	{
		ft_putstr("Argument problem \n");
		return (0);
	}
	return (1);
}

int	check_first_read(int i)
{
	if (i == 0)
	{
		ft_putstr("Map problem with Exit, Collectible or Player \n");
		return (0);
	}
	return (1);
}

int	check_second_read(int i, t_param *param)
{
	if (i == 0)
	{
		ft_putstr("Map problem with Collectible \n");
		free_map(param);
		return (0);
	}
	return (1);
}

int	check_valid_map(int i)
{
	if (i == 0)
	{
		ft_putstr("Invalid Map\n");
		return (0);
	}
	return (1);
}

int	return_and_clean(t_param *param)
{
	param->play.current_img = NULL;
	param->item = NULL;
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	free_map(param);
	return (0);
}
