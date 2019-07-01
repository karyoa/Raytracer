/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getobject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 02:22:09 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/01 04:34:14 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_float3		obj_pos(t_itf *interface)
{
	t_tf3		tf;
	t_float3	pos;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "ScenePos", "sceneposx");
	tf.tfy = getmenutextfield(interface, "ScenePos", "sceneposy");
	tf.tfz = getmenutextfield(interface, "ScenePos", "scenepoz");
	if (tf.tfx)
		pos.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		pos.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		pos.z = ft_atod(tf.tfz->val);
	return (pos);
}

t_float3		obj_rot(t_itf *interface)
{
	t_tf3		tf;
	t_float3	rot;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "ScenePos", "scenerotx");
	tf.tfy = getmenutextfield(interface, "ScenePos", "sceneroty");
	tf.tfz = getmenutextfield(interface, "ScenePos", "scenerotz");
	if (tf.tfx)
		rot.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		rot.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		rot.z = ft_atod(tf.tfz->val);
	return (rot);
}

t_float3		obj_color(t_itf *interface)
{
	t_tf3		tf;
	t_float3	color;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "SceneCol", "scenecolx");
	tf.tfy = getmenutextfield(interface, "SceneCol", "scenecoly");
	tf.tfz = getmenutextfield(interface, "SceneCol", "scenecolz");
	if (tf.tfx)
		color.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		color.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		color.z = ft_atod(tf.tfz->val);
	return (color);
}

t_float3		obj_colort(t_itf *interface)
{
	t_tf3		tf;
	t_float3	color;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "SceneColt", "scenecoltx");
	tf.tfy = getmenutextfield(interface, "SceneColt", "scenecolty");
	tf.tfz = getmenutextfield(interface, "SceneColt", "scenecoltz");
	if (tf.tfx)
		color.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		color.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		color.z = ft_atod(tf.tfz->val);
	return (color);
}

void			obj_reflection(t_object *object, t_itf *interface)
{
	t_tf3		tf;

	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "sceneRefl", "scenediff");
	tf.tfy = getmenutextfield(interface, "sceneRefl", "scenespec");
	tf.tfz = getmenutextfield(interface, "sceneRefl", "scenespecxp");
	if (tf.tfx)
		object->diffuse_refl = ft_atod(tf.tfx->val);
	if (tf.tfy)
		object->specular_refl = ft_atod(tf.tfy->val);
	if (tf.tfz)
		object->specular_refr = ft_atod(tf.tfz->val);
	obj_reflectionn(object, interface);
}
