/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:59:26 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 17:59:27 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int				main(int argc, char **argv)
{
	int			fd;

	if (argc < 2)
		ft_putendl_fd("usage: ./RTv1 file1", 2);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(ft_strjoin("RTv1: ", argv[1]));
			return (1);
		}
		rtv1(fd);
	}
	return (0);
}
