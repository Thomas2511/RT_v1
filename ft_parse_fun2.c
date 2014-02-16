/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fun2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:54:52 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 17:54:57 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"RTv1.h"

t_point			*ft_get_point(t_list **list)
{
	int			i;
	t_point		*point;

	i = 0;
	point = ft_pointnew(ft_atoi((*list)->content),
			ft_atoi((*list)->next->content),
			ft_atoi((*list)->next->next->content));
	while (i < 3)
	{
		*list = (*list)->next;
		i++;
	}
	return (point);
}

t_vect			*ft_get_vect(t_list **list)
{
	int			i;
	t_vect		*vect;

	i = 0;
	vect = ft_vectornew(ft_atoi((*list)->content),
						ft_atoi((*list)->next->content),
						ft_atoi((*list)->next->next->content));
	while (i < 3)
	{
		*list = (*list)->next;
		i++;
	}
	return (vect);
}

t_color			*ft_get_color(t_list **list)
{
	int			i;
	t_color		*color;

	i = 0;
	color = ft_colornew(ft_atoi((*list)->content),
						ft_atoi((*list)->next->content),
						ft_atoi((*list)->next->next->content));
	while (i < 3)
	{
		*list = (*list)->next;
		i++;
	}
	return (color);
}
