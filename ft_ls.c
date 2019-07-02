/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/02 12:06:33 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

unsigned char		get_flags(int ac, char **av)
{
	int				i;
	char			**str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = &av[i];
		if (**str == '-')
		{
			(*str)++;
			while (**str == 'l' || **str == 'a' || **str == 'R' ||
			**str == 'r' || **str == 't')
			{
				if (**str == 'l')
					flags |= 1;
				if (**str == 'a')
					flags |= 2;
				if (**str == 'R')
					flags |= 4;
				if (**str == 'r')
					flags |= 8;
				if (**str == 't')
					flags |= 16;
				(*str)++;
			}
		}
		i++;
	}
	return (flags);
}

int main(int ac, char **av)
{
	return (0);
}
