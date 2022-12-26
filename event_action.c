/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:32:50 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/02 22:40:59 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	affich_mov(t_param *param)
{
	char	*tmp;

	tmp = ft_itoa(param -> play.nb_move);
	ft_putstr("Number move :");
	ft_putstr(tmp);
	ft_putchar ('\n');
	free(tmp);
}

int	keyboard_event(int keycode, t_param *param)
{
	if (keycode == 97 || keycode == 119 || keycode == 115 || keycode == 100)
		affich_mov(param);
	if (keycode == 97)
		move_left(param);
	else if (keycode == 119)
		move_up(param);
	else if (keycode == 115)
		move_down(param);
	else if (keycode == 100)
		move_right(param);
	else if (keycode == 65307)
	{
		cleaning_and_closure(param);
		exit(0);
	}
	return (0);
}

int	close_cross(t_param *vars)
{
	cleaning_and_closure(vars);
	exit(0);
	return (0);
}
