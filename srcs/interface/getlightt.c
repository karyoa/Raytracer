/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlightt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:51:44 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:51:46 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_float3		light_dir(t_itf *interface)
{
	t_tf3		tf;
	t_float3	dir;

	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "SceneDirLight", "scenelightdirx");
	tf.tfy = getmenutextfield(interface, "SceneDirLight", "scenelightdiry");
	tf.tfz = getmenutextfield(interface, "SceneDirLight", "scenelightdirz");
	if (tf.tfx)
		dir.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		dir.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		dir.z = ft_atod(tf.tfz->val);
	return (dir);
}

t_float3		light_lum(t_itf *interface)
{
	t_tf3		tf;
	t_float3	lum;

	lum.x = 0;
	lum.y = 0;
	lum.z = 0;
	tf.tfx = NULL;
	tf.tfy = NULL;
	tf.tfz = NULL;
	tf.tfx = getmenutextfield(interface, "SceneLumLight", "scenelightlumx");
	tf.tfy = getmenutextfield(interface, "SceneLumLight", "scenelightlumy");
	tf.tfz = getmenutextfield(interface, "SceneLumLight", "scenelightlumz");
	if (tf.tfx)
		lum.x = ft_atod(tf.tfx->val);
	if (tf.tfy)
		lum.y = ft_atod(tf.tfy->val);
	if (tf.tfz)
		lum.z = ft_atod(tf.tfz->val);
	return (lum);
}

void			filllightcol(t_light *light, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tLIGHT RED\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->color.x, fd);
	ft_putstr_fd("\n\tLIGHT GREEN\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->color.y, fd);
	ft_putstr_fd("\n\tLIGHT BLUE\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->color.z, fd);
	ft_putendl_fd("", fd);
}

void			filllightdir(t_light *light, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tLIGHT DIR X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->dir.x, fd);
	ft_putstr_fd("\n\tLIGHT DIR Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->dir.y, fd);
	ft_putstr_fd("\n\tLIGHT DIR Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->dir.z, fd);
	ft_putendl_fd("", fd);
}

void			filllightlum(t_light *light, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tLIGHT LUM X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->luminance.x, fd);
	ft_putstr_fd("\n\tLIGHT LUM Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->luminance.y, fd);
	ft_putstr_fd("\n\tLIGHT LUM Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->luminance.z, fd);
	ft_putendl_fd("", fd);
}
