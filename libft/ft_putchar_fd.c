/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:29:25 by tdieumeg          #+#    #+#             */
/*   Updated: 2013/12/29 15:24:30 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
