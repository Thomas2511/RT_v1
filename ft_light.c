/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:54:09 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 17:54:11 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_light		*ft_lightnew(t_point *point, enum e_light light, t_color *color)
{
	t_light	*new;

	if ((new = (t_light*)malloc(sizeof(t_light))) == NULL)
		return (NULL);
	new->point = point;
	new->color = color;
	new->type = light;
	new->next = NULL;
	return (new);
}

void		ft_lightclear(t_light **light)
{
	free((*light)->point);
	free(*light);
	*light = NULL;
}

void		ft_lightpushfront(t_light **list, t_point *point
								, enum e_light type, t_color *color)
{
	t_light	*new;

	new = ft_lightnew(point, type, color);
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}

int			ft_lightcolor(t_obj	*obj, t_light *light,
							t_vect *vect, t_point *point)
{
	double	cosa;
	t_vect	*normal;
	int		i;

	i = 0;
	while (i < OBJ_SIZE)
	{
		if (g_objtab[i].type == obj->type)
			normal = g_objtab[i].f_getnorm(obj->obj, point, vect);
		i++;
	}
	cosa = ft_getangle(vect, normal);
	if (cosa <= 0)
		return (0x000000);
	return (ft_getcolor(obj->color, light->color, cosa));
}
