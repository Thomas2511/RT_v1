/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:00:17 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 18:00:19 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_buffer(char **buf, char **line)
{
	char	*save_line;

	save_line = *line;
	if (ft_strchr(*buf, '\n'))
	{
		*line = ft_strjoin(*line
				, ft_strsub(*buf, 0, ft_strchr(*buf, '\n') - *buf));
		*buf = ft_strchr(*buf, '\n') + 1;
		return (1);
	}
	*line = ft_strjoin(*line, *buf);
	free(save_line);
	return (0);
}

int			ft_get_next_line(int const fd, char **line)
{
	static int			old_fd = 0;
	static char			*buf = NULL;
	int					len;

	*line = ft_strdup("");
	if (buf && old_fd == fd)
		if (split_buffer(&buf, line))
			return (1);
	old_fd = fd;
	buf = ft_strnew(BUFF_SIZE);
	while ((len = read(fd, buf, BUFF_SIZE)) != -1)
	{
		buf[len] = '\0';
		if (len == 0)
			return (0);
		if (split_buffer(&buf, line))
			return (1);
		if (len < BUFF_SIZE)
			return (1);
	}
	return (-1);
}
