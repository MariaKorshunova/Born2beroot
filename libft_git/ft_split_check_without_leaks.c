/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:24:55 by refrain           #+#    #+#             */
/*   Updated: 2021/10/26 16:50:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *str, char del)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != del)
		{
			while (str[i] != del && str[i])
				i++;
			word_count++;
		}
		else
			i++;
	}
	return (word_count);
}

static void	ft_free(char **str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
		free(str[i++]);
	free(str);
}

static char	**ft_str(char **str, char const *s, char del)
{
	size_t		j;
	size_t		len;
	const char	*start;
	static int a = 3;

	j = 0;
	while (*s)
	{
		len = 0;
		while (*s == del && *s)
			s++;
		start = (char *)s;
		while (*s && *s != del)
		{
			s++;
			len++;
		}
		if (*(s - 1) != del)
		/*{
			str[j++] = ft_substr(start, 0, len);
			if (str == NULL)
				ft_free(str, j);
		}*/
		{
			if (a > 0)
				str[j++] = ft_substr(start, 0, len);
			else
			{
				str[j++] = NULL;
				ft_free(str, j);
			}
			a--;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_word_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	return (ft_str(str, s, c));
}
