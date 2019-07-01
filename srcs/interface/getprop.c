/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getprop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:53:41 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 02:09:20 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			obj_proportionn(t_object *object, t_itf *interface)
{
	t_tf		*tfcx;
	t_tf		*tfcy;
	t_tf		*tfcz;
	t_tf		*tfd;
	t_float3	tmpb;

	tfcx = NULL;
	tfcy = NULL;
	tfcz = NULL;
	tfd = NULL;
	tmpb.x = 0;
	tmpb.y = 0;
	tmpb.z = 0;
	tfcx = getmenutextfield(interface, "sceneProp", "scenelimaxx");
	tfcy = getmenutextfield(interface, "sceneProp", "scenelimaxy");
	tfcz = getmenutextfield(interface, "sceneProp", "scenelimaxz");
	tfd = getmenutextfield(interface, "sceneProp", "sceneray");
	tmpb.x = ft_atod(tfcx->val);
	if (tfcy)
		tmpb.y = ft_atod(tfcy->val);
	if (tfcz)
		tmpb.z = ft_atod(tfcz->val);
	if (tfd)
		object->ray = ft_atod(tfd->val);
	object->limit_max = tmpb;
}

void			obj_proportionnn(t_object *object, t_itf *interface)
{
	t_tf		*tfbx;
	t_tf		*tfby;
	t_tf		*tfbz;
	t_float3	tmpa;

	tmpa.x = 0;
	tmpa.y = 0;
	tmpa.z = 0;
	tfbx = NULL;
	tfby = NULL;
	tfbz = NULL;
	tfbx = getmenutextfield(interface, "sceneProp", "sceneliminx");
	tfby = getmenutextfield(interface, "sceneProp", "sceneliminy");
	tfbz = getmenutextfield(interface, "sceneProp", "sceneliminz");
	tmpa.x = ft_atod(tfbx->val);
	tmpa.y = ft_atod(tfby->val);
	tmpa.z = ft_atod(tfbz->val);
	object->limit_min = tmpa;
}

void			obj_proportion(t_object *object, t_itf *interface)
{
	t_tf		*tfa;
	t_tf		*tfe;

	tfa = NULL;
	tfe = NULL;
	tfa = getmenutextfield(interface, "sceneProp", "scenelim");
	tfe = getmenutextfield(interface, "sceneProp", "scenealpha");
	if (ft_atoi(tfa->val) == 1)
		object->limit = 1;
	else
		object->limit = 0;
	object->alpha = ft_atod(tfe->val);
	obj_proportionn(object, interface);
	obj_proportionnn(object, interface);
}
