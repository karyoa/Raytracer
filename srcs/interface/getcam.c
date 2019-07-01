/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:51:29 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:51:34 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_float3		cam_pos(t_itf *interface)
{
	t_tf3		tf;
	t_float3	pos;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "ScenePosCam", "scenecamposx");
	tf.tfy = getmenutextfield(interface, "ScenePosCam", "scenecamposy");
	tf.tfz = getmenutextfield(interface, "ScenePosCam", "scenecamposz");
	if (tf.tfx)
		pos.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		pos.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		pos.z = ft_atod(tf.tfz->val);
	return (pos);
}

t_float4		cam_rot(t_itf *interface)
{
	t_tf4		tf;
	t_float4	rot;

	rot.w = 0;
	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	tf.tfw = NULL;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfw = getmenutextfield(interface, "SceneRotCam", "scenecamrotw");
	tf.tfx = getmenutextfield(interface, "SceneRotCam", "scenecamrotx");
	tf.tfy = getmenutextfield(interface, "SceneRotCam", "scenecamroty");
	tf.tfz = getmenutextfield(interface, "SceneRotCam", "scenecamrotz");
	if (tf.tfw)
		rot.w = ft_atod(tf.tfw->val);
	if (tf.tfx)
		rot.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		rot.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		rot.z = ft_atod(tf.tfz->val);
	return (rot);
}

void			cam_fin(t_cam *cam, t_itf *interface)
{
	t_tf3		tf;

	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfx = getmenutextfield(interface, "SceneFCam", "scenecamalpha");
	tf.tfy = getmenutextfield(interface, "SceneFCam", "scenecamfov");
	if (tf.tfx)
		cam->alpha = ft_atod(tf.tfx->val);
	if (tf.tfy)
		cam->fov = ft_atod(tf.tfy->val);
}

char			*obj_name(t_itf *interface)
{
	char		*name;
	t_tf3		tf;

	name = NULL;
	tf.tfx = getmenutextfield(interface, "SceneColt", "sceneobjname");
	if (tf.tfx)
	{
		name = (tf.tfx->val);
		if (ft_strcmp(tf.tfx->val, "") == 0)
			name = "Object";
	}
	return (name);
}

void			background(t_itf *interface, char *scene)
{
	t_menu		*start;

	start = getmenu(interface, scene);
	start->bg.x = 25;
	start->bg.y = 25;
	start->bg.w = 590;
	start->bg.h = 310;
}
