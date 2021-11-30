/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:39:46 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/20 16:50:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_current_str(int fd, char *current_str)
{
	char	*buf;
	int		ret;

	ret = 1;
	while (ret && !ft_strchr(current_str, '\n'))
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		current_str = ft_strjoin_gnl(current_str, buf);
	}
	return (current_str);
}

char	*ft_next_line(char *current_str)
{
	char	*next_line;
	int		i;

	i = 0;
	if (current_str[i] == '\0')
		return (NULL);
	while (current_str[i] != '\0' && current_str[i] != '\n')
		i++;
	if (current_str[i] == '\n')
		i++;
	next_line = malloc((i + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	next_line[i] = '\0';
	i--;
	while (i >= 0)
	{
		next_line[i] = current_str[i];
		i--;
	}
	return (next_line);
}

char	*ft_new_current_str(char *current_str)
{
	char	*str;
	int		i;
	int		j;

	if (!current_str)
		return (NULL);
	i = 0;
	j = 0;
	while (current_str[i] != '\0' && current_str[i] != '\n')
		i++;
	if (current_str[i] == '\n')
	{
		i++;
		str = malloc(((int)ft_strlen(current_str) + 1 - i) * sizeof(char));
		if (!str)
			return (NULL);
		while (current_str[i] != '\0')
			str[j++] = current_str[i++];
		str[j] = '\0';
		free (current_str);
		return (str);
	}
	free (current_str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*current_str[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	current_str[fd] = ft_current_str(fd, current_str[fd]);
	if (!current_str[fd])
		return (NULL);
	next_line = ft_next_line(current_str[fd]);
	current_str[fd] = ft_new_current_str(current_str[fd]);
	return (next_line);
}
