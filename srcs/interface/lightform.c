/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:51:55 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:52:09 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			lightlumform(t_itf *interface)
{
	t_light		light;

	light.luminance = light_lum(interface);
	filllightlum(&light, interface);
	switchmenu(interface, "SceneFLight");
}

void			lightdirform(t_itf *interface)
{
	t_light		light;

	light.dir = light_dir(interface);
	filllightdir(&light, interface);
	switchmenu(interface, "SceneLumLight");
}

void			lightcolform(t_itf *interface)
{
	t_light		light;

	light.color = light_col(interface);
	filllightcol(&light, interface);
	switchmenu(interface, "SceneDirLight");
}

void			lightposform(t_itf *interface)
{
	t_light		light;

	light.pos = light_pos(interface);
	light.name = light_name(interface);
	filllightpos(&light, interface);
	switchmenu(interface, "SceneColLight");
}

void			addlight(t_itf *interface)
{
	t_light		light;
	t_float3	tmp;

	switchmenu(interface, "ScenePosLight");
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	light.pos = tmp;
	light.color = tmp;
	light.dir = tmp;
	light.luminance = tmp;
	light.intensity = 0;
	light.ray = 0;
	light.alpha = 0;
}
