/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:24:32 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/02 22:30:50 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stddef.h>

void	free_tab(t_tile **tab, int i)
{
	while (i)
	{
		i--;
		free(tab[i]);
	}
}

int	free_map(t_param *param)
{
	int	i;

	i = 0;
	if (param->map == NULL)
		return (0);
	while ((param->map[i]) != NULL)
	{
		if ((param->map[i]))
			free(param->map[i]);
		param->map[i] = NULL;
		i++;
	}
	free(param->map);
	param->map = NULL;
	return (0);
}

int	cleaning_and_closure(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	free_map(param);
	return (0);
}
