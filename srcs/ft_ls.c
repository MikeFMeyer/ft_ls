/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/04 09:03:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

void	ft_ls(char *path, unsigned char flags)
{
	struct dirent *de;

	DIR *dr = opendir(path);
	if (check_errors(path) == 1)
		return;
    while ((de = readdir(dr)))
		if (!flags)
		{
			if (de->d_name[0] != '.')
			{
				ft_putstr(de->d_name);
				ft_putchar('\t');
			}
		}
    	else
		{
    		ft_putstr(de->d_name);
    		ft_putchar('\t');
    	}
	closedir(dr);
	dr = opendir(path);
	while ((de = readdir(dr)))
		if ((flags & 4) && (de->d_type == 4) && (ft_strcmp(de->d_name, ".") != 0) && (ft_strcmp(de->d_name, "..") != 0))
		{
			ft_putstr("\n\n");
			ft_putstr(path);
			ft_putchar('/');
			ft_putstr(de->d_name);
			ft_putstr(":\n");
			ft_ls(ft_strjoin(path, ft_strjoin("/", de->d_name)), flags);
		}
	closedir(dr);	
}

int main (int ac, char **av)
{
	unsigned char flags;
	int i;

	i = 1;
	flags = get_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
		while (i < ac)
		{
			if (av[i][0] != '-')
				ft_ls(av[i],flags);
			i++;
		}
	ft_putchar('\n');
	return (0);
}
