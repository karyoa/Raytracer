/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:52:40 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/20 22:55:28 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			createpropformmm(t_itf *interface)
{
	t_lab3		labl;
	t_tf3		scene;

	labl.x = createmenulabel(interface, "sceneProp", "laba");
	setlabeltext(labl.x, "Limit", interface);
	setlabelposition(labl.x, 50, 50);
	scene.tfx = createmenutextfield(interface, "sceneProp", "scenelim");
	settextfieldposition(scene.tfx, 50, 90, 100);
	labl.y = createmenulabel(interface, "sceneProp", "labd");
	setlabeltext(labl.y, "Rayon", interface);
	setlabelposition(labl.y, 50, 150);
	scene.tfy = createmenutextfield(interface, "sceneProp", "sceneray");
	settextfieldposition(scene.tfy, 50, 190, 100);
	labl.z = createmenulabel(interface, "sceneProp", "labe");
	setlabeltext(labl.z, "Alpha", interface);
	setlabelposition(labl.z, 50, 250);
	scene.tfz = createmenutextfield(interface, "sceneProp", "scenealpha");
	settextfieldposition(scene.tfz, 50, 290, 100);
}

void			createpropformm(t_itf *interface)
{
	t_lab3		lab;
	t_tf3		scenelimin;

	lab.x = createmenulabel(interface, "sceneProp", "labbx");
	setlabeltext(lab.x, "Limit min x", interface);
	setlabelposition(lab.x, 250, 50);
	scenelimin.tfx = createmenutextfield(interface, "sceneProp", "sceneliminx");
	settextfieldposition(scenelimin.tfx, 250, 90, 100);
	lab.y = createmenulabel(interface, "sceneProp", "labby");
	setlabeltext(lab.y, "Limit min y", interface);
	setlabelposition(lab.y, 250, 150);
	scenelimin.tfy = createmenutextfield(interface, "sceneProp", "sceneliminy");
	settextfieldposition(scenelimin.tfy, 250, 190, 100);
	lab.z = createmenulabel(interface, "sceneProp", "labbz");
	setlabeltext(lab.z, "Limit min z", interface);
	setlabelposition(lab.z, 250, 250);
	scenelimin.tfz = createmenutextfield(interface, "sceneProp", "sceneliminz");
	settextfieldposition(scenelimin.tfz, 250, 290, 100);
	createpropformmm(interface);
}

void			createpropform(t_itf *interface)
{
	t_lab3		labc;
	t_tf3		scenelimax;
	t_button	*ok;

	background(interface, "sceneProp");
	labc.x = createmenulabel(interface, "sceneProp", "labcx");
	setlabeltext(labc.x, "Limit max x", interface);
	setlabelposition(labc.x, 450, 50);
	scenelimax.tfx = createmenutextfield(interface, "sceneProp", "scenelimaxx");
	settextfieldposition(scenelimax.tfx, 450, 90, 100);
	labc.y = createmenulabel(interface, "sceneProp", "labcy");
	setlabeltext(labc.y, "Limit max y", interface);
	setlabelposition(labc.y, 450, 150);
	scenelimax.tfy = createmenutextfield(interface, "sceneProp", "scenelimaxy");
	settextfieldposition(scenelimax.tfy, 450, 190, 100);
	labc.z = createmenulabel(interface, "sceneProp", "labcz");
	setlabeltext(labc.z, "Limit max z", interface);
	setlabelposition(labc.z, 450, 250);
	scenelimax.tfz = createmenutextfield(interface, "sceneProp", "scenelimaxz");
	settextfieldposition(scenelimax.tfz, 450, 290, 100);
	ok = crmenubutton(interface, "sceneProp", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 570, 290);
	setbuttonfunction(ok, backtoaddobject);
	createpropformm(interface);
}
