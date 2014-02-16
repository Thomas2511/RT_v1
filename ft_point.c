/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:55:31 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/02/16 18:02:37 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** This function creates a new point
*/
t_point				*ft_pointnew(double x, double y, double z)
{
	t_point			*point;

	point = (t_point*)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

/*
** This function places a pixel into an image.
*/
int					pixel_to_img(t_mlx_img *img, int x, int y, int color)
{
	long			index;
	int				i;
	long			max;

	i = 0;
	index = x * (img->bpp / 8) + y * (img->size);
	max = img->width * (img->bpp / 8) + img->height * (img->size);
	while ((i < img->bpp / 8) && index < max && index > 0)
	{
		img->data[index + i] = ((char*)&color)[i];
		i++;
	}
	return (0);
}

/*
** Gets the pixel color of an image at a position
*/
size_t				get_pixel_at(t_mlx_img *img, int x, int y)
{
	long			index;
	int				i;
	long			max;
	int				color;

	i = 0;
	index = x * (img->bpp / 8) + y * (img->size);
	max = img->width * (img->bpp / 8) + img->height * (img->size);
	color = 0;
	while ((i < img->bpp / 8) && index < max && index > 0)
	{
		((char*)&color)[i] = img->data[index + i];
		i++;
	}
	return (color);
}

t_point			*ft_getvpupleft(t_camera *camera)
{
	t_point		*new;

	if ((new = ft_pointnew(0, 0, 0)) == NULL)
		return (NULL);
	new->x = camera->origin->x + ((camera->dir->x * VP_DIST)
			+ (camera->up->x * (VP_HEIGHT / 2.0)))
			- (camera->right->x * (VP_WIDTH / 2.0));
	new->y = camera->origin->y + ((camera->dir->y * VP_DIST)
			+ (camera->up->y * (VP_HEIGHT / 2.0)))
			- (camera->right->y * (VP_WIDTH / 2.0));
	new->z = camera->origin->z + ((camera->dir->z * VP_DIST)
			+ (camera->up->z * (VP_HEIGHT / 2.0)))
			- (camera->right->z * (VP_WIDTH / 2.0));
	return (new);
}
