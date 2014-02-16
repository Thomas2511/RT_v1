/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 10:16:51 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 17:52:48 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_cylinder		*ft_cylindernew(t_point *center, t_vect *axis, double radius)
{
	t_cylinder	*new;

	if ((new = (t_cylinder*)malloc(sizeof(t_cylinder))) == NULL)
		return (NULL);
	new->center = center;
	new->axis = axis;
	new->radius = radius;
	return (new);
}

void			ft_clearcylinder(void **ptr_cylinder)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)*ptr_cylinder;
	free(cylinder->center);
	free(cylinder->axis);
	free(cylinder);
	*ptr_cylinder = NULL;
}

double			ft_intercylinder(void *ptr_cylinder,
								t_point *origin, t_vect *dir)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)ptr_cylinder;
	a = pow(dir->x, 2) + pow(dir->z, 2);
	b = 2 * ((dir->x * (origin->x - cylinder->center->x))
		+ (dir->z * (origin->z - cylinder->center->z)));
	c = pow(origin->x - cylinder->center->x, 2)
		+ pow(origin->z - cylinder->center->z, 2)
		- pow(cylinder->radius, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (-1);
	return (ft_getmin((-b + sqrt(det)) / (2 * a),
				(-b - sqrt(det)) / (2 * a)));
}

t_vect			*ft_normecylinder(void *ptr_cylinder, t_point *origin,
								t_vect *dir)
{
	t_vect		*vect;
	t_cylinder	*cylinder;

	(void)dir;
	cylinder = (t_cylinder*)ptr_cylinder;
	if ((vect = ft_vectornew(origin->x - cylinder->center->x,
		0, origin->z - cylinder->center->z)) == NULL)
		return (NULL);
	return (vect);
}
