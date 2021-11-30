/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:04:40 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/18 20:02:02 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] != (char)c)
		return (NULL);
	else
		return ((char *)s + i);
}

char	*ft_strjoin_gnl(char *str, char *buf)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	str_len;
	size_t	buf_len;

	str_len = ft_strlen(str);
	buf_len = ft_strlen(buf);
	i = 0;
	dest = (char *)malloc((str_len + buf_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < str_len)
	{
		dest[i] = str[i];
		i++;
	}
	j = i;
	i = 0;
	while (i < buf_len)
		dest[j++] = buf[i++];
	dest[j] = '\0';
	free(str);
	free(buf);
	return (dest);
}
