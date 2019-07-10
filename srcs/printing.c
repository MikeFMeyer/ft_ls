/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/10 13:30:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_blocks(t_dir *list)
{
	int i;

	i = 0;
	ft_putstr("total ");
	while (list)
	{
		i += list->block;
		list = list->next;
	}
	ft_putnbr(i);
	ft_putchar('\n');
}

void	format_line(t_dir *list)
{
	ft_putstr((S_ISDIR(list->mode)) ? "d" : "-");
	ft_putstr((list->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((list->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((list->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((list->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((list->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((list->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((list->mode & S_IROTH) ? "r" : "-");
	ft_putstr((list->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((list->mode & S_IXOTH) ? "x  " : "-  ");
	ft_putnbr(list->nlink);
	ft_putchar('\t');
	ft_putstr(list->uid);
	ft_putstr("  ");
	ft_putstr(list->gid);
	ft_putstr("  ");
	ft_putnbr(list->size);
	ft_putstr("\t");
	ft_putnbr(list->time);
	ft_putstr(" ");
	ft_putendl(list->name);
}

void	print_list(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
			format_line(ptr);
		else
		{
			if (ft_strncmp(ptr->name, ".", 1) != 0)
				format_line(ptr);
		}
		ptr = ptr->next;
	}
}

void	print_normal(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(ptr->name);
			ft_putstr("\t\t");
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				ft_putstr(ptr->name);
				ft_putstr("\t\t");
			}
			ptr = ptr->next;
		}
	}
}

void	print_recursion(char *path)
{
	if ((ft_strcmp(path, "./") != 0) || (ft_strcmp(path, ".") != 0))
	{
		ft_putstr("\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

void	print_output(t_dir *list, unsigned char flags, char *path)
{
	if (flags & 1)
	{
		if (flags & 4)
			print_recursion(path);
		print_blocks(list);
		print_list(list, flags);
	}
	else
	{
		if (flags & 4)
			print_recursion(path);
		print_normal(list, flags);
	}
}
