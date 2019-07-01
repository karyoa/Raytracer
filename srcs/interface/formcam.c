/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formcam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:45:53 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:45:54 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			camposform(t_itf *interface)
{
	t_cam		cam;

	cam.origin = cam_pos(interface);
	fillcampos(&cam, interface);
	switchmenu(interface, "SceneRotCam");
}

void			camrotform(t_itf *interface)
{
	t_cam		cam;

	cam.rotate_start = cam_rot(interface);
	fillcamrot(&cam, interface);
	switchmenu(interface, "SceneFCam");
}

void			camfinform(t_itf *interface)
{
	t_cam		cam;

	cam_fin(&cam, interface);
	fillcamfin(&cam, interface);
	switchmenu(interface, "objectToAdd");
}

void			addcam(t_itf *interface)
{
	t_cam		cam;
	t_float4	tmp;
	t_float3	tmpp;

	switchmenu(interface, "ScenePosCam");
	tmp.w = 0;
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	tmpp.x = 0;
	tmpp.y = 0;
	tmpp.z = 0;
	cam.origin = tmpp;
	cam.rotate_start = tmp;
	cam.fov = 0;
	cam.alpha = 0;
}
