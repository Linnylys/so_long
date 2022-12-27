/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:35 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/04 20:12:20 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"

# define BSIZE 40
//# define WIN_MAX_LAR 52
//# define WIN_MAX_LON 96
# define IMG_PLAYER_LEFT1 "./test_image/player_left_1.xpm"
# define IMG_PLAYER_LEFT2  "./test_image/player_left_2.xpm"
# define IMG_PLAYER_LEFT3  "./test_image/player_left_3.xpm"

# define IMG_PLAYER_RIGHT1 "./test_image/player_right_1.xpm"
# define IMG_PLAYER_RIGHT2 "./test_image/player_right_2.xpm"
# define IMG_PLAYER_RIGHT3 "./test_image/player_right_3.xpm"

# define IMG_PLAYER_UP1 "./test_image/player_up_1.xpm"
# define IMG_PLAYER_UP2 "./test_image/player_up_2.xpm"
# define IMG_PLAYER_UP3 "./test_image/player_up_3.xpm"

# define IMG_PLAYER_DOWN1 "./test_image/player_down_1.xpm"
# define IMG_PLAYER_DOWN2 "./test_image/player_down_2.xpm"
# define IMG_PLAYER_DOWN3 "./test_image/player_down_3.xpm"

# define IMG_WALL "./test_image/Brick_01-40x40.xpm"
# define IMG_COLLECT "./test_image/cat_tile.xpm"
# define IMG_EMPTY "./test_image/tile.xpm"
# define IMG_EXIT "./test_image/key_tile.xpm"

typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
}	t_program;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_tile
{
	int				type;
	int				og_type;
	int				chck_fill;
	t_vector		pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_Mapsize
{
	int	nb_line;
	int	nb_column;
}	t_Mapsize;

typedef struct s_player
{
	t_tile	*tile;
	t_tile	*prev_tile;
	int		nb_move;
	int		count_collect;
	int		exit_flag;
	void	*current_img;
	int		framecount;
	int		last_key_move;
}	t_player;

typedef struct s_nb_items
{
	int	nb_collect;
	int	nb_exit;
	int	nb_player;
	int	not_recognized;
}	t_nb_items;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_player	play;
	t_tile		key;
	int			key_flag;
	t_tile		**map;
	t_tile		**item;
	t_nb_items	nb_item;
	t_Mapsize	mapsize;
	int			check_border;
	int			line_len;
	int			line_lenflag;
	int			screen_sizexbysprite;
	int			screen_sizeybysprite;
}	t_param;

int		check_line_error_management(int i);
int		line_analyse(t_param *param, char *str, int flag);
int		get_nb_item(t_param *param, char *str);
int		check_nb_item_and_endline(t_param *param, int i, int flag);
int		ft_strlen_modif(char *str);
t_image	ft_new_sprite(void *mlx, char *path);
int		keyboard_event(int keycode, t_param *param);
int		close_cross(t_param *vars);
int		expose_test(t_param *vars);
int		image_drawing(t_param *param);
int		map_second_reading(t_param *param, char *file);
int		map_first_reading(t_param *param, char *file);
t_tile	**map_gen(int nb_line, int nb_column);
t_tile	**map_alloc(int nb_column, int nb_line);
void	free_tab(t_tile **tab, int i);
int		image_re_drawing(t_param *param);
int		nbr_cal_word(char const *s, char c);
int		*get_nb_letter_word(char const *s, char c, int nb);
void	free_tab_letter(char **res, int len);
char	**affect_mem_sentence(char const *s, char c, int nb);
char	**ft_split(char const *s, char c);
int		gen_window(t_param *param);
int		check_second_read(int i, t_param *param);
int		game_init(t_param *param);
int		hook_update(t_param *param);
int		move2exit(t_param *param);
int		move_left(t_param *param);
int		move_right(t_param *param);
int		move_up(t_param *param);
int		move_down(t_param *param);
void	reset_map_wall(t_param *param);
int		check_valid_map(int i);
void	affich_mov(t_param *param);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		check_border(t_param *param, int line_int, int i, int j);
t_tile	simple_affect(t_tile map_res, int line_int, int i, int j);
char	*ft_itoa_limited(int n);
int		nb_dec_cal(int n);
char	*ft_itoa(int n);
int		affect_map(t_param *param, char *line, int i, int j);
int		check_file_opening(int fd);
int		type_convert(char c);
void	left_frame(t_param *param);
void	down_frame(t_param *param);
void	up_frame(t_param *param);
void	right_frame(t_param *param);
int		free_map(t_param *param);
int		cleaning_and_closure(t_param *param);
int		return_and_clean(t_param *param);
t_image	drawing_sprite(t_param param, int i, int j);
t_image	re_drawing_sprite(t_param *param, int i, int j);
int		flood_fill(t_param *param, int i, int j);
int		check_flood_fill(t_param *param);
int		check_arg(int argc, char **argv);
int		file_opening(char *input);
int		argument_problem(int i);
int		check_first_read(int i);
void	img2wind(t_param *param, void *ptr, int i, int j);
int		check_border_map(int i);

#endif
