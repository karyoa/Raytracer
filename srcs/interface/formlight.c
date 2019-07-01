/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:47:49 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/03 06:51:06 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				createlightposformm(t_itf *interface)
{
	t_lab3			laba;
	t_tf3			tfa;
	t_button		*ok;

	laba.x = createmenulabel(interface, "ScenePosLight", "labax");
	setlabeltext(laba.x, "Light's name", interface);
	setlabelposition(laba.x, 450, 250);
	tfa.tfx = createmenutextfield(interface, "ScenePosLight", "scenelightname");
	settextfieldposition(tfa.tfx, 450, 290, 100);
	ok = crmenubutton(interface, "ScenePosLight", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 570, 290);
	setbuttonfunction(ok, lightposform);
}

void				createlightposform(t_itf *interface)
{
	t_lab3			lab;
	t_tf3			tf;

	background(interface, "ScenePosLight");
	lab.x = createmenulabel(interface, "ScenePosLight", "labx");
	setlabeltext(lab.x, "Position Lumiere en x", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "ScenePosLight", "scenelightposx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "ScenePosLight", "laby");
	setlabeltext(lab.y, "Position Lumiere en y", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "ScenePosLight", "scenelightposy");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "ScenePosLight", "labz");
	setlabeltext(lab.z, "Position Lumiere en z", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "ScenePosLight", "scenelightpoz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	createlightposformm(interface);
}

void				createlightcolform(t_itf *interface)
{
	t_lab3			lab;
	t_tf3			tf;
	t_button		*ok;

	background(interface, "SceneColLight");
	lab.x = createmenulabel(interface, "SceneColLight", "labx");
	setlabeltext(lab.x, "Color rouge", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneColLight", "scenelightcolx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneColLight", "laby");
	setlabeltext(lab.y, "Color verte", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneColLight", "scenelightcoly");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "SceneColLight", "labz");
	setlabeltext(lab.z, "Color bleue", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneColLight", "scenelightcolz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "SceneColLight", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 290);
	setbuttonfunction(ok, lightcolform);
}

void				createlightdirform(t_itf *interface)
{
	t_lab3			lab;
	t_tf3			tf;
	t_button		*ok;

	background(interface, "SceneDirLight");
	lab.x = createmenulabel(interface, "SceneDirLight", "labx");
	setlabeltext(lab.x, "Direction x", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneDirLight", "scenelightdirx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneDirLight", "laby");
	setlabeltext(lab.y, "Direction y", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneDirLight", "scenelightdiry");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "SceneDirLight", "labz");
	setlabeltext(lab.z, "Direction z", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneDirLight", "scenelightdirz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "SceneDirLight", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 290);
	setbuttonfunction(ok, lightdirform);
}

void				createlightlumform(t_itf *interface)
{
	t_lab3			lab;
	t_tf3			tf;
	t_button		*ok;

	background(interface, "SceneLumLight");
	lab.x = createmenulabel(interface, "SceneLumLight", "labx");
	setlabeltext(lab.x, "Luminance x", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneLumLight", "scenelightlumx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneLumLight", "laby");
	setlabeltext(lab.y, "Luminance y", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneLumLight", "scenelightlumy");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "SceneLumLight", "labz");
	setlabeltext(lab.z, "Luminance z", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneLumLight", "scenelightlumz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "SceneLumLight", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 290);
	setbuttonfunction(ok, lightlumform);
}
