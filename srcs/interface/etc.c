/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:41:19 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 20:41:20 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				listfile(void)
{
	DIR				*rep;
	struct dirent	*ent;

	rep = opendir("scene");
	if (rep != NULL)
	{
		ent = readdir(rep);
		ft_putendl("\nListe des fichiers présent dans le dossier scene :\n");
		ent = readdir(rep);
		while ((ent = readdir(rep)) != NULL)
			ft_putendl(ent->d_name);
		ft_putendl("\nFin de la liste\n");
		closedir(rep);
	}
}

void				fillprop(t_object *object, t_itf *interface)
{
	int				fd;

	fd = interface->fd;
	ft_putstr_fd("\trayon\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->ray, fd);
	ft_putstr_fd("\n\talpha\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->alpha, fd);
	ft_putstr_fd("\n\tLimit\t\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit, fd);
	ft_putstr_fd("\n\tLIM_MIN_X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit_min.x, fd);
	ft_putstr_fd("\n\tLIM_MIN_Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit_min.y, fd);
	ft_putstr_fd("\n\tLIM_MIN_Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit_min.z, fd);
	ft_putstr_fd("\n\tLIM_MAX_X\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit_max.x, fd);
	ft_putstr_fd("\n\tLIM_MAX_Y\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit_max.y, fd);
	ft_putstr_fd("\n\tLIM_MAX_Z\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)object->limit_max.z, fd);
	ft_putendl_fd("", fd);
}

void				obj_reflectionn(t_object *object, t_itf *interface)
{
	t_tf3			tfa;

	tfa.tfx = NULL;
	tfa.tfy = NULL;
	tfa.tfz = NULL;
	tfa.tfx = getmenutextfield(interface, "sceneRefl", "scenedifref");
	tfa.tfy = getmenutextfield(interface, "sceneRefl", "scenedifamb");
	tfa.tfz = getmenutextfield(interface, "sceneRefl", "sceneshin");
	if (tfa.tfx)
		object->diffuse_refr = ft_atod(tfa.tfx->val);
	if (tfa.tfy)
		object->diffuse_ambt = ft_atod(tfa.tfy->val);
	if (tfa.tfz)
		object->shininess = ft_atod(tfa.tfz->val);
}

void				createcoltformm(t_itf *interface)
{
	t_lab3			laba;
	t_tf3			tfa;
	t_button		*ok;

	laba.x = createmenulabel(interface, "SceneColt", "labax");
	setlabeltext(laba.x, "Object's name", interface);
	setlabelposition(laba.x, 450, 250);
	tfa.tfx = createmenutextfield(interface, "SceneColt", "sceneobjname");
	settextfieldposition(tfa.tfx, 450, 290, 100);
	ok = crmenubutton(interface, "SceneColt", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 570, 290);
	setbuttonfunction(ok, reflform);
}

void				createreflectformm(t_itf *interface)
{
	t_lab3			lab;
	t_tf3			tf;
	t_button		*ok;

	lab.x = createmenulabel(interface, "sceneRefl", "labx");
	setlabeltext(lab.x, "Set diffuse_refl", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "sceneRefl", "scenediff");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "sceneRefl", "laby");
	setlabeltext(lab.y, "Set specular_refl", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "sceneRefl", "scenespec");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "sceneRefl", "labz");
	setlabeltext(lab.z, "Set specular_refr", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "sceneRefl", "scenespecxp");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "sceneRefl", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 570, 290);
	setbuttonfunction(ok, propform);
}
