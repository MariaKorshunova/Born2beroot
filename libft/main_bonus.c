/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:30:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/03 18:31:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// main for bonus functions

static void	print_list(t_list *list)
{
	while (list)
	{
		ft_putendl_fd(list->content, 1);
		list = list->next;
	}
}

static void	ft_toupper_and_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	ft_putendl_fd(str, 1);
}

static void	*ft_toupper_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	main(void)
{
	t_list	*list_middle;
	t_list	*list_begin;
	t_list	*list_end;
	t_list	*empty_list;
	t_list	*list_upper;
	char	*data_middle;
	char	*data_begin;
	char	*data_end;

	empty_list = NULL;
	data_middle = ft_strdup("hello-world");
	data_begin = ft_strdup("The beginning of list");
	data_end = ft_strdup("The end of list");
	list_middle = ft_lstnew(data_middle);
	list_begin = ft_lstnew(data_begin);
	list_end = ft_lstnew(data_end);
	ft_lstadd_front(&list_middle, list_begin);
	ft_lstadd_back(&list_begin, list_end);
	ft_putstr_fd("----------------Print list after adding to front and back-------------\n", 1);
	print_list(list_begin);
	ft_putstr_fd("-------------------The number of elements in a list-------------------\n", 1);
	ft_putnbr_fd(ft_lstsize(list_begin), 1);
	ft_putstr_fd("\n----------------------The last element of the list------------------\n", 1);
	ft_putendl_fd((ft_lstlast(list_begin))->content, 1);
	ft_putstr_fd("\n----------------------ft_lstiter with ft_toupper_------------------\n", 1);
	ft_lstiter(list_begin, (void *)ft_toupper_and_print_str);
	ft_putstr_fd("\n---------------------------------ft_lstmap--------------------------\n", 1);
	list_upper = ft_lstmap(list_begin, (void *)ft_toupper_str, free);
	print_list(list_upper);
	ft_putstr_fd("---ft_lstlast with null(expected nothing to print without mistakes)---\n", 1);
	ft_lstlast(empty_list);
	ft_putstr_fd("---Clear list and print (expected nothing to print without mistakes)--\n", 1);
	ft_lstclear(&list_begin, free);
	// ft_lstclear(&list_upper, free);
	return (0);
}
