/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:16:40 by serge             #+#    #+#             */
/*   Updated: 2021/11/22 16:33:03 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new_string;

	i = 0;
	new_string = NULL;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	while (i < len)
	{
		new_string[i] = ((char *)s)[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strjoin(char *input_str, char *input_buf)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_input_str;
	size_t	len_input_buf;

	i = 0;
	j = 0;
	len_input_str = ft_strlen(input_str);
	len_input_buf = ft_strlen(input_buf);
	if (!input_buf)
		return (NULL);
	str = malloc(len_input_str + len_input_buf + 1);
	if (str == NULL)
		return (NULL);
	while (i < len_input_str)
	{
		str[i] = input_str[i];
		i++;
	}
	while (j < len_input_buf)
		str[i++] = input_buf[j++];
	str[i] = '\0';
	free(input_str);
	return (str);
}

char	*ft_record_str_help(char **buf, int **i, char **substr, char **str)
{
	size_t		len;

	len = 0;
	while ((*buf)[*(*i)] != '\0' && (*buf)[*(*i)] != '\n')
	{
		len++;
		(*(*i))++;
	}
	if ((*buf)[*(*i)] == '\n')
	{
		len++;
		(*(*i))++;
	}
	if (len == 0)
		return (NULL);
	*substr = ft_substr(*buf, (*(*i)) - len, len);
	if (!(*substr))
		return (NULL);
	*str = ft_strjoin(*str, *substr);
	if (!(*str))
	{
		free(*substr);
		return (NULL);
	}
	return ((char *)(*i));
}

char	*ft_record_str(int fd, char *str, char *buf, int *i)
{
	int		ret;
	char	*substr;

	ret = 1;
	if (*i == -1 || (*i == BUFFER_SIZE))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (NULL);
		buf[ret] = '\0';
		*i = 0;
	}
	while (ret)
	{
		if (!ft_record_str_help(&buf, &i, &substr, &str))
			return (NULL);
		free(substr);
		if (buf[(*i) - 1] == '\n')
			return (str);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		ft_record_str_write(&buf, &i, &ret);
	}
	return (str);
}
