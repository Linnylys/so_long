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
#include<stddef.h>

int	argument_problem(int i)
{
	if (i == 0)
		return (0);
	return (1);
}

int	check_first_read(int i)
{
	if (i == 0)
		return (0);
	return (1);
}

int	check_second_read(int i, t_param *param)
{
	if (i == 0)
	{
		free_map(param);
		return (0);
	}
	return (1);
}

int	check_valid_map(int i)
{
	if (i == 0)
		return (0);
	return (1);
}

int	check_border_map(int i)
{
	if (i == 0)
	{
		ft_putstr("Error \nInvalid Map - Not surrounded exclusively by wall\n");
		return (0);
	}
	return (1);
}
