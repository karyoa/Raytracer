/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 05:08:27 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/01 04:34:46 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			createposformm(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;

	lab.x = createmenulabel(interface, "ScenePos", "labx");
	setlabeltext(lab.x, "Rotation en x", interface);
	setlabelposition(lab.x, 450, 50);
	tf.tfx = createmenutextfield(interface, "ScenePos", "scenerotx");
	settextfieldposition(tf.tfx, 450, 90, 100);
	lab.y = createmenulabel(interface, "ScenePos", "laby");
	setlabeltext(lab.y, "Rotation en y", interface);
	setlabelposition(lab.y, 450, 150);
	tf.tfy = createmenutextfield(interface, "ScenePos", "sceneroty");
	settextfieldposition(tf.tfy, 450, 190, 100);
	lab.z = createmenulabel(interface, "ScenePos", "labz");
	setlabeltext(lab.z, "Rotation en z", interface);
	setlabelposition(lab.z, 450, 250);
	tf.tfz = createmenutextfield(interface, "ScenePos", "scenerotz");
	settextfieldposition(tf.tfz, 450, 290, 100);
}

void			createposform(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;
	t_button	*ok;

	background(interface, "ScenePos");
	lab.x = createmenulabel(interface, "ScenePos", "labx");
	setlabeltext(lab.x, "Position en x", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "ScenePos", "sceneposx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "ScenePos", "laby");
	setlabeltext(lab.y, "Position en y", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "ScenePos", "sceneposy");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "ScenePos", "labz");
	setlabeltext(lab.z, "Position en z", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "ScenePos", "scenepoz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "ScenePos", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 570, 290);
	setbuttonfunction(ok, colform);
	createposformm(interface);
}

void			createcolform(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;
	t_button	*ok;

	background(interface, "SceneCol");
	lab.x = createmenulabel(interface, "SceneCol", "labx");
	setlabeltext(lab.x, "Color rouge", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneCol", "scenecolx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneCol", "laby");
	setlabeltext(lab.y, "Color verte", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneCol", "scenecoly");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "SceneCol", "labz");
	setlabeltext(lab.z, "Color bleue", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneCol", "scenecolz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	ok = crmenubutton(interface, "SceneCol", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 290);
	setbuttonfunction(ok, coltform);
}

void			createcoltform(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		tf;

	background(interface, "SceneColt");
	lab.x = createmenulabel(interface, "SceneColt", "labx");
	setlabeltext(lab.x, "Color_t rouge", interface);
	setlabelposition(lab.x, 50, 50);
	tf.tfx = createmenutextfield(interface, "SceneColt", "scenecoltx");
	settextfieldposition(tf.tfx, 50, 90, 100);
	lab.y = createmenulabel(interface, "SceneColt", "laby");
	setlabeltext(lab.y, "Color_t verte", interface);
	setlabelposition(lab.y, 50, 150);
	tf.tfy = createmenutextfield(interface, "SceneColt", "scenecolty");
	settextfieldposition(tf.tfy, 50, 190, 100);
	lab.z = createmenulabel(interface, "SceneColt", "labz");
	setlabeltext(lab.z, "Color_t bleue", interface);
	setlabelposition(lab.z, 50, 250);
	tf.tfz = createmenutextfield(interface, "SceneColt", "scenecoltz");
	settextfieldposition(tf.tfz, 50, 290, 100);
	createcoltformm(interface);
}

void			createreflectform(t_itf *interface)
{
	t_lab3		laba;
	t_tf3		tfa;

	background(interface, "sceneRefl");
	laba.x = createmenulabel(interface, "sceneRefl", "labax");
	setlabeltext(laba.x, "Set diffuse_refr", interface);
	setlabelposition(laba.x, 450, 50);
	tfa.tfx = createmenutextfield(interface, "sceneRefl", "scenedifref");
	settextfieldposition(tfa.tfx, 450, 90, 100);
	laba.y = createmenulabel(interface, "sceneRefl", "labay");
	setlabeltext(laba.y, "Set diffuse_ambt", interface);
	setlabelposition(laba.y, 450, 150);
	tfa.tfy = createmenutextfield(interface, "sceneRefl", "scenedifamb");
	settextfieldposition(tfa.tfy, 450, 190, 100);
	laba.z = createmenulabel(interface, "sceneRefl", "labaz");
	setlabeltext(laba.z, "Set shininess", interface);
	setlabelposition(laba.z, 450, 250);
	tfa.tfz = createmenutextfield(interface, "sceneRefl", "sceneshin");
	settextfieldposition(tfa.tfz, 450, 290, 100);
	createreflectformm(interface);
}
