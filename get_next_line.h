/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:06:17 by iboufqir          #+#    #+#             */
/*   Updated: 2024/01/10 11:12:58 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);

#endif