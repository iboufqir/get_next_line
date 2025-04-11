/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:47:40 by iboufqir          #+#    #+#             */
/*   Updated: 2024/01/10 13:44:12 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*string[OPEN_MAX];
	char		*line;

	if (read (fd, string, 0) == -1 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX)
	{
		if (fd > 0)
			return (free(string[fd]), string[fd] = NULL, NULL);
		return (NULL);
	}
	string[fd] = ft_read(fd, string[fd]);
	if (!string[fd] || !string[fd][0])
		return (free(string[fd]), string[fd] = NULL, NULL);
	line = ft_newline(string[fd]);
	if (!line)
		return (free(string[fd]), string[fd] = NULL, NULL);
	string[fd] = ft_rest(string[fd]);
	return (line);
}
