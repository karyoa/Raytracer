/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formlightt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:46:26 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:47:04 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			lightfinform(t_itf *interface)
{
	t_light		light;

	light_fin(&light, interface);
	filllightfin(&light, interface);
	switchmenu(interface, "objectToAdd");
}

void			createlightfform(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;
	t_button	*ok;

	background(interface, "SceneFLight");
	lab.x = createmenulabel(interface, "SceneFLight", "labx");
	setlabeltext(lab.x, "Light rayon", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneFLight", "scenelightray");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneFLight", "laby");
	setlabeltext(lab.y, "Light Alpha", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneFLight", "scenelightalpha");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "SceneFLight", "labz");
	setlabeltext(lab.z, "Light intensity", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneFLight", "scenelightintens");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "SceneFLight", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 570, 290);
	setbuttonfunction(ok, lightfinform);
}

void			filllightfin(t_light *light, t_itf *interface)
{
	int			fd;

	fd = interface->fd;
	ft_putstr_fd("\tLIGHT INTENSITY\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->intensity, fd);
	ft_putstr_fd("\n\tLIGHT RAY\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->ray, fd);
	ft_putstr_fd("\n\tLIGHT ALPHA\t\t\t\t\t\t\t\t\t", fd);
	ft_putnbr_fd((int)light->alpha, fd);
	ft_putendl_fd("", fd);
}
