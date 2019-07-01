/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:42:12 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 10:17:36 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			createcamposform(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;
	t_button	*ok;

	background(interface, "ScenePosCam");
	lab.x = createmenulabel(interface, "ScenePosCam", "labx");
	setlabeltext(lab.x, "Position X", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "ScenePosCam", "scenecamposx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "ScenePosCam", "laby");
	setlabeltext(lab.y, "Position Y", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "ScenePosCam", "scenecamposy");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "ScenePosCam", "labz");
	setlabeltext(lab.z, "Position Z", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "ScenePosCam", "scenecamposz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "ScenePosCam", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 290);
	setbuttonfunction(ok, camposform);
}

void			createcamrotformm(t_itf *interface)
{
	t_button	*ok;

	ok = crmenubutton(interface, "SceneRotCam", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 300);
	setbuttonfunction(ok, camrotform);
}

void			createcamrotform(t_itf *interface)
{
	t_lab4		lab;
	t_tf4		tf;

	background(interface, "SceneRotCam");
	lab.w = createmenulabel(interface, "SceneRotCam", "labw");
	setlabeltext(lab.w, "Rotation W", interface);
	setlabelposition(lab.w, 50, 50);
	tf.tfw = createmenutextfield(interface, "SceneRotCam", "scenecamrotw");
	settextfieldposition(tf.tfw, 50, 90, 100);
	lab.x = createmenulabel(interface, "SceneRotCam", "labx");
	setlabeltext(lab.x, "Rotation X", interface);
	setlabelposition(lab.x, 50, 110);
	tf.tfx = createmenutextfield(interface, "SceneRotCam", "scenecamrotx");
	settextfieldposition(tf.tfx, 50, 160, 100);
	lab.y = createmenulabel(interface, "SceneRotCam", "laby");
	setlabeltext(lab.y, "Rotation Y", interface);
	setlabelposition(lab.y, 50, 180);
	tf.tfy = createmenutextfield(interface, "SceneRotCam", "scenecamroty");
	settextfieldposition(tf.tfy, 50, 230, 100);
	lab.z = createmenulabel(interface, "SceneRotCam", "labz");
	setlabeltext(lab.z, "Rotation Z", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneRotCam", "scenecamrotz");
	settextfieldposition(tf.tfz, 50, 300, 100);
	createcamrotformm(interface);
}

void			createcamfinform(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;
	t_button	*ok;

	background(interface, "SceneFCam");
	lab.x = createmenulabel(interface, "SceneFCam", "labx");
	setlabeltext(lab.x, "Alpha", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneFCam", "scenecamalpha");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneFCam", "laby");
	setlabeltext(lab.y, "FOV", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneFCam", "scenecamfov");
	settextfieldposition(tf.tfy, 50, 190, 100);
	ok = crmenubutton(interface, "SceneFCam", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 190);
	setbuttonfunction(ok, camfinform);
}
