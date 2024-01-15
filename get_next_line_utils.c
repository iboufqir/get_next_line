/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:06:13 by iboufqir          #+#    #+#             */
/*   Updated: 2024/01/10 10:38:32 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!p)
		return (NULL);
	while (str && str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
		return (ft_strdup(buff));
	str = (char *)malloc((ft_strlen(left_str) + ft_strlen(buff)) + 1);
	if (str == NULL)
		return (free(left_str), left_str = NULL, NULL);
	i = 0;
	j = 0;
	while (left_str[i] != '\0')
	{
		str[i] = left_str[i];
		i++;
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}
