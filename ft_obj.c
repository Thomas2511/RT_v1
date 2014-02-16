/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:54:23 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 17:54:27 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_objfun	g_objtab[OBJ_SIZE] =
{
	{"sphere", O_SPHERE, ft_normesphere, ft_intersphere,
		ft_clearsphere, ft_fillsphere},
	{"plane", O_PLANE, ft_normeplane, ft_interplane,
		ft_clearplane, ft_fillplane},
	{"cylinder", O_CYLINDER, ft_normecylinder, ft_intercylinder,
		ft_clearcylinder, ft_fillcylinder},
	{"cone", O_CONE, ft_normecone, ft_intercone, ft_clearcone, ft_fillcone}
};

t_obj			*ft_objnew(void *obj, enum e_obj type, t_color *color)
{
	t_obj		*new;

	if ((new = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new->obj = obj;
	new->type = type;
	new->next = NULL;
	new->color = color;
	return (new);
}

void			ft_objpushfront(t_obj **list, void *obj,
							enum e_obj type, t_color *color)
{
	t_obj		*cur;
	t_obj		*new;

	new = ft_objnew(obj, type, color);
	cur = *list;
	if (!cur)
		*list = new;
	else
	{
		*list = new;
		new->next = cur;
	}
}

void			ft_inverseplane(t_obj *list, t_camera *camera)
{
	t_plane		*plane;

	while (list)
	{
		if (list->type == O_PLANE)
		{
			plane = (t_plane*)list->obj;
			if (ft_getangle(plane->vect, camera->dir) >= 0)
			{
				plane->vect->x = plane->vect->x * -1;
				plane->vect->y = plane->vect->y * -1;
				plane->vect->z = plane->vect->z * -1;
				plane->d = -plane->d;
			}
		}
		list = list->next;
	}
}
