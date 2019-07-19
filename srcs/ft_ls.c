/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/19 09:20:24 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

void	recursion(t_dir *list, unsigned char flags, char *path)
{
	t_dir	*ptr;
	char	*s1;
	char	*s2;

	ptr = list;
	if (flags & 4)
		while (ptr != NULL)
		{
			if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
			&& (ft_strcmp(ptr->name, "..") != 0))
			{
				if (!(flags & 2) && (ptr->name[0] == '.'))
				{
					ptr = ptr->next;
					continue ;
				}
				s1 = ft_strjoin("/", ptr->name);
				s2 = ft_strjoin(path, s1);
				free(s1);
				ft_ls(s2, flags);
				free(s2);
			}
			ptr = ptr->next;
		}
}

void	ft_ls(char *path, unsigned char flags)
{
	struct dirent	*de;
	t_dir			*initial;
	DIR				*dr;
	t_blocks		blocks;

	blocks.flags = flags;
	blocks.total = 0;
	initial = NULL;
	de = NULL;
	dr = opendir(path);
	if (check_errors(path, dr) == 1)
		return ;
	while ((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de, path, &blocks);
		else
			list_add(&initial, de, path, &blocks);
	}
	closedir(dr);
	merge_sort(&initial, flags);
	print_output(initial, flags, path, &blocks);
	recursion(initial, flags, path);
	delete_list(&initial);
}

int		main(int ac, char **av)
{
	unsigned char	flags;
	int				check;
	char			*args[ac];

	check = 0;
	if ((flags = get_flags(ac, av)) == '\0')
		return (0);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		add_args(args, ac, av);
		check = execute_args(args, flags, ac);
		if (check == 0)
			ft_ls(".", flags);
	}
	return (0);
}
