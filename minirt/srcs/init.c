/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:07 by smorel            #+#    #+#             */
/*   Updated: 2021/02/01 15:56:11 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	init_coord(t_coord *c)
{
	c->x = -1;
	c->y = -1;
	c->z = -1;
}

int			init_minrt(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (error_minirt(98));
	if (!(mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "miniRT")))
		return (error_minirt(99));
	return (-1);
}

void		set_value_4_pars(t_mlx *mlx)
{
	t_scene	*scene;

	mlx->h = -1;
	mlx->w = -1;
	scene = (t_scene *)malloc(sizeof(t_scene));
	mlx->sc = scene;
	mlx->sc->l.r = -1;
	init_coord(&mlx->sc->l.rgb);
	mlx->save = 0;
	mlx->sc->shape = NULL;
	mlx->sc->c = NULL;
}

t_shape		*init_shape(void)
{
	t_shape	*sh;

	sh = (t_shape *)malloc(sizeof(t_shape));
	init_coord(&sh->origin);
	init_coord(&sh->rgb);
	init_coord(&sh->vector);
	init_coord(&sh->pt);
	sh->rayon = -1;
	sh->hight = -1;
	return (sh);
}

t_cam		*init_cam(void)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	init_coord(&cam->origin);
	init_coord(&cam->vector);
	cam->fov = 0;
	return (cam);
}
