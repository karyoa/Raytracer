/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addobject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:14:27 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/19 02:16:57 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	addcylinder(t_itf *interface)
{
	t_object	cylinder;
	t_float3	tmp;

	switchmenu(interface, "ScenePos");
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	cylinder.type = CYLINDER;
	cylinder.pos = tmp;
	cylinder.color = tmp;
	cylinder.color_t = tmp;
	cylinder.limit = 0;
	cylinder.ray = 0;
	cylinder.limit_min = tmp;
	cylinder.limit_max = tmp;
	cylinder.alpha = 0;
	filltype(&cylinder, interface);
}

void	addsphere(t_itf *interface)
{
	t_object	sphere;
	t_float3	tmp;

	switchmenu(interface, "ScenePos");
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	sphere.type = SPHERE;
	sphere.pos = tmp;
	sphere.color = tmp;
	sphere.color_t = tmp;
	sphere.limit = 0;
	sphere.ray = 0;
	sphere.limit_min = tmp;
	sphere.limit_max = tmp;
	sphere.alpha = 0;
	filltype(&sphere, interface);
}

void	addcone(t_itf *interface)
{
	t_object	cone;
	t_float3	tmp;

	switchmenu(interface, "ScenePos");
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	cone.type = CONE;
	cone.pos = tmp;
	cone.color = tmp;
	cone.color_t = tmp;
	cone.limit = 0;
	cone.ray = 0;
	cone.limit_min = tmp;
	cone.limit_max = tmp;
	cone.alpha = 0;
	filltype(&cone, interface);
}

void	addplan(t_itf *interface)
{
	t_object	plan;
	t_float3	tmp;

	switchmenu(interface, "ScenePos");
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	plan.type = PLANE;
	plan.pos = tmp;
	plan.color = tmp;
	plan.color_t = tmp;
	plan.limit = 0;
	plan.ray = 0;
	plan.limit_min = tmp;
	plan.limit_max = tmp;
	plan.alpha = 0;
	filltype(&plan, interface);
}

void	adddisk(t_itf *interface)
{
	t_object	disk;
	t_float3	tmp;

	switchmenu(interface, "ScenePos");
	tmp.x = 0;
	tmp.y = 0;
	tmp.z = 0;
	disk.type = DISK;
	disk.pos = tmp;
	disk.color = tmp;
	disk.color_t = tmp;
	disk.limit = 0;
	disk.ray = 0;
	disk.limit_min = tmp;
	disk.limit_max = tmp;
	disk.alpha = 0;
	filltype(&disk, interface);
}
