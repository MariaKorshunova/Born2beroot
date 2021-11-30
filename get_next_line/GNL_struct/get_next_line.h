/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:03:28 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/18 19:45:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);
char	*ft_current_str(int fd, char *current_str);
char	*ft_new_current_str(char *current_str);
char	*ft_next_line(char *current_str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *str, char *buf);

#endif