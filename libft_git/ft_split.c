/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:44:48 by jmabel            #+#    #+#             */
/*   Updated: 2021/10/24 19:07:58 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_str_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	char	**ft_make_array(char **arr, char const *s, char c)
{
	const char	*start;
	size_t		i;
	size_t		letter;

	i = 0;
	while (*s)
	{
		letter = 0;
		while (*s == c && *s)
			s++;
		start = (char *)s;
		while (*s != c && *s)
		{
			letter++;
			s++;
		}
		if (*(s - 1) != c)
			arr[i++] = ft_substr(start, 0, letter);
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(*arr) * (ft_str_count(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	arr = ft_make_array(arr, s, c);
	return (arr);
}
