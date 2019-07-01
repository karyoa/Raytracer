/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:47:21 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:47:23 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_float3		light_pos(t_itf *interface)
{
	t_tf3		tf;
	t_float3	pos;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "ScenePosLight", "scenelightposx");
	tf.tfy = getmenutextfield(interface, "ScenePosLight", "scenelightposy");
	tf.tfz = getmenutextfield(interface, "ScenePosLight", "scenelightpoz");
	if (tf.tfx)
		pos.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		pos.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		pos.z = ft_atod(tf.tfz->val);
	return (pos);
}

t_float3		light_col(t_itf *interface)
{
	t_tf3		tf;
	t_float3	color;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "SceneColLight", "scenelightcolx");
	tf.tfy = getmenutextfield(interface, "SceneColLight", "scenelightcoly");
	tf.tfz = getmenutextfield(interface, "SceneColLight", "scenelightcolz");
	if (tf.tfx)
		color.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		color.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		color.z = ft_atod(tf.tfz->val);
	return (color);
}

char			*light_name(t_itf *interface)
{
	char		*name;
	t_tf3		tf;

	name = NULL;
	tf.tfx = getmenutextfield(interface, "ScenePosLight", "scenelightname");
	if (tf.tfx)
	{
		name = (tf.tfx->val);
		if (ft_strcmp(tf.tfx->val, "") == 0)
			name = "Light";
	}
	return (name);
}

void			light_fin(t_light *light, t_itf *interface)
{
	t_tf3		tf;

	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "SceneFLight", "scenelightray");
	tf.tfy = getmenutextfield(interface, "SceneFLight", "scenelightalpha");
	tf.tfz = getmenutextfield(interface, "SceneFLight", "scenelightintens");
	if (tf.tfx)
		light->ray = ft_atod(tf.tfx->val);
	if (tf.tfy)
		light->alpha = ft_atod(tf.tfy->val);
	if (tf.tfz)
		light->intensity = ft_atod(tf.tfz->val);
}

void			filllightpos(t_light *light, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\n\tLight Name\t\t\t\t\t\t\t\t\t", fd);
	ft_putendl_fd(light->name, fd);
	ft_putstr_fd("\n\tLIGHT POS X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->pos.x, fd);
	ft_putstr_fd("\n\tLIGHT POS Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->pos.y, fd);
	ft_putstr_fd("\n\tLIGHT POS Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->pos.z, fd);
	ft_putendl_fd("", fd);
}
