/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:38:07 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/03 17:39:41 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<unistd.h>
#include<stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_endline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	for_split_md_init(char *str, int *is, int *js)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n' && j == 0)
			j = i + 1;
		i++;
	}
	if (j == 0)
		j = i;
	*is = i;
	*js = j;
}

char	**ft_split_md(char *str)
{
	int		k;
	int		i;
	int		j;
	char	**res;

	for_split_md_init(str, &i, &j);
	res = malloc (2 * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[0] = malloc ((j + 1) * sizeof(char));
	res[1] = malloc ((i - j + 1) * sizeof(char));
	if (free_exit(res[0], res[1], 1) == 1)
		return (NULL);
	k = 0;
	res[0][j] = '\0';
	res[1][i - j] = '\0';
	while (str[k])
	{
		if (k < j)
			res[0][k] = str[k];
		else
			res[1][k - j] = str[k];
		k++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1)
		*s1 = 0;
	free(s1);
	return (str);
}
