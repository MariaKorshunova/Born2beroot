/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:12:57 by serge             #+#    #+#             */
/*   Updated: 2021/11/22 17:02:31 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	ft_free(t_list **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_record_str_write(char **buf, int **i, int *ret)
{
	(*buf)[*ret] = '\0';
	*(*i) = 0;
}

char	*get_next_line(int fd)
{
	char			*str;
	static t_list	list[OPEN_MAX];

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (ft_strlen((list[fd]).buf) == 0)
		(list[fd]).i = -1;
	str = ft_record_str(fd, str, ((list[fd]).buf), &((list[fd]).i));
	if (!str || ft_strlen(str) == 0)
	{
	//	ft_free(&list[fd]);
		return (NULL);
	}
	return (str);
}

/*int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	i;

	i = 0;
	fd1 = open("text1", O_RDONLY);
	fd2 = open("text2", O_RDONLY);
	fd3 = open("text3", O_RDONLY);
	while (i < 1)
	{
		printf("Linefromfd1%s", get_next_line(fd1));
		printf("Linefromfd2%s", get_next_line(fd2));
		printf("Linefromfd3%s", get_next_line(fd3));
		printf("Linefromfd1%s", get_next_line(fd1));
		printf("Linefromfd2%s", get_next_line(fd2));
		printf("Linefromfd3%s", get_next_line(fd3));
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
