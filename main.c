/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:10:02 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/10 19:49:35 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h> 
#include <stdio.h>

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	return (img);
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
	int	sizex;
	int	sizey;

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
	param->line_len_flag = 1;
	mlx_get_screen_size(param->mlx, &sizex, &sizey);
	param->screen_sizexbysprite = sizex / BSIZE;
	param->screen_sizeybysprite = sizey / BSIZE;
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	prm;

	if (argument_problem(check_arg(argc, argv)) == 0)
		return (0);
	if (file_opening(argv[1]) == 0)
		return (0);
	game_init(&prm);
	if (check_first_read(map_first_reading(&prm, argv[1])) == 0)
		return (return_and_clean(&prm));
	if (check_second_read(map_second_reading(&prm, argv[1]), &prm) == 0)
		return (return_and_clean(&prm));
	if (check_valid_map(prm.check_border) == 0)
		return (return_and_clean(&prm));
	if (check_valid_map(check_flood_fill(&prm)) == 0)
		return (return_and_clean(&prm));
	prm.win = gen_window(prm);
	image_drawing(&prm);
	mlx_hook(prm.win, 2, 1L << 0, keyboard_event, &prm);
	mlx_hook(prm.win, 17, 1L << 0, close_cross, &prm);
	mlx_loop_hook(prm.mlx, hook_update, &prm);
	mlx_loop(prm.mlx);
	free (prm.mlx);
	return (0);
}
