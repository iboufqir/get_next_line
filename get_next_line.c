/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:05:12 by iboufqir          #+#    #+#             */
/*   Updated: 2024/01/10 14:52:00 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *string)
{
	char	*buff;
	int		rbs;

	rbs = 1;
	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(string), string = NULL, NULL);
	while (rbs)
	{
		rbs = read(fd, buff, BUFFER_SIZE);
		buff[rbs] = '\0';
		string = ft_strjoin(string, buff);
		if (!string || ft_strchr(string, '\n') != -1)
			break ;
	}
	free(buff);
	buff = NULL;
	if (!string)
		return (free(string), string = NULL, NULL);
	return (string);
}

static char	*ft_newline(char *str)
{
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = str[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	*ft_rest(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i + j])
		j++;
	ptr = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (free(str), str = NULL, NULL);
	j = 0;
	while (str[i])
		ptr[j++] = str[i++];
	ptr[j] = '\0';
	free(str);
	str = NULL;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*string;
	char			*line;

	if (read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX)
		return (free(string), string = NULL, NULL);
	string = ft_read(fd, string);
	if (!string || !string[0])
		return (free(string), string = NULL, NULL);
	line = ft_newline(string);
	if (!line)
		return (free(string), string = NULL, NULL);
	string = ft_rest(string);
	return (line);
}
