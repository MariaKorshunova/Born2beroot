/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:13:34 by serge             #+#    #+#             */
/*   Updated: 2021/11/22 16:32:45 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include <fcntl.h>

typedef struct s_list
{
	char	buf[BUFFER_SIZE + 1];
	int		i;
}					t_list;

size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

void	ft_record_str_write(char **buf, int **i, int *ret);
char	*ft_record_str(int fd, char *str, char *buf, int *i);
char	*ft_record_str_help(char **buf, int **i, char **substr, char **str);
char	*get_next_line(int fd);
void	ft_free(t_list **str);

#endif
