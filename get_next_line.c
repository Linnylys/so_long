/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:05:02 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/03 17:32:23 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include<stdlib.h>

int	free_exit(char *s1, char *s2, int i)
{
	if (i == 0)
	{
		free(s1);
		free(s2);
	}
	else
	{
		if (s1 == NULL || s2 == NULL)
		{
			free(s1);
			free(s2);
			return (1);
		}
	}
	return (0);
}

char	*split_end_file(char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}	

char	*buf_check(int fd, char **str_store, int *flag)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*flag = read(fd, buf, BUFFER_SIZE);
	if (*flag == 0 && (*str_store == 0 || **str_store == 0))
	{
		free(buf);
		return (NULL);
	}
	if (*flag == -1)
	{
		free(buf);
		return (NULL);
	}
	if (*flag > 0 && *flag < BUFFER_SIZE)
		return (split_end_file(buf, *flag));
	buf[BUFFER_SIZE] = '\0';
	if (*flag == 0)
		*buf = 0;
	return (buf);
}

char	*end_line_found(char *buf, char **str_store_ptr)
{
	char	*res;
	char	*res_tmp;
	char	*res2_tmp;
	char	**split_res;

	res_tmp = ft_strjoin(*str_store_ptr, buf);
	split_res = ft_split_md(res_tmp);
	free(res_tmp);
	res2_tmp = split_res[1];
	*str_store_ptr = res2_tmp;
	res = split_res[0];
	free(split_res);
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*result;
	static char	*str_store = 0;
	static int	flag = 1;

	if (fd < 0)
		return (NULL);
	buf = buf_check(fd, &str_store, &flag);
	if (buf == NULL || (flag <= 0 && (str_store == 0 || *str_store == 0)))
	{
		free_exit(str_store, buf, 0);
		str_store = 0;
		return (NULL);
	}
	if (is_endline(buf) == 0 && flag > 0)
	{
		str_store = ft_strjoin(str_store, buf);
		free(buf);
		result = get_next_line(fd);
	}
	else
		result = end_line_found(buf, &str_store);
	return (result);
}
