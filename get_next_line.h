/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:54:59 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/03 18:31:12 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
# include<stddef.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 70
# endif

size_t	ft_strlen(const char *s);
char	**ft_split_md(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		is_endline(char *str);
char	*split_end_file(char *str, int len);
char	*buf_check(int fd, char **str_store, int *flag);
char	*end_line_found(char *buf, char **str_store_ptr);
char	*get_next_line(int fd);
int		free_exit(char *s1, char *s2, int i);

#endif
