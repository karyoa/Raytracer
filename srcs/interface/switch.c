/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:38:53 by mbeckert          #+#    #+#             */
/*   Updated: 2018/05/01 04:32:11 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			createscene(t_itf *interface)
{
	t_tf		*tf;
	int			fd;

	fd = 0;
	tf = NULL;
	tf = getmenutextfield(interface, "scenename", "scenename");
	if ((fd = openat(open("scene/", O_CREAT), tf->val, O_CREAT | O_RDWR)) == -1)
	{
		mkdir("scene", S_IRWXU | S_IRWXG | S_IRWXO);
		fd = openat(open("scene/", O_CREAT), tf->val, O_CREAT | O_RDWR);
	}
	interface->fd = fd;
	switchmenu(interface, "Scene");
}

void			propform(t_itf *interface)
{
	t_object	object;

	obj_reflection(&object, interface);
	fillrefl(&object, interface);
	switchmenu(interface, "sceneProp");
}

void			createnamesceneform(t_itf *interface)
{
	t_label		*lab;
	t_tf		*scenename;
	t_button	*ok;

	background(interface, "scenename");
	lab = createmenulabel(interface, "scenename", "lab");
	setlabeltext(lab, "Choose a name for your scene !", interface);
	setlabelposition(lab, 50, 50);
	scenename = createmenutextfield(interface, "scenename", "scenename");
	settextfieldposition(scenename, 50, 100, 100);
	ok = crmenubutton(interface, "scenename", "ok");
	setbuttontext(ok, "OK", interface);
	setbuttonposition(ok, 170, 100);
	setbuttonfunction(ok, createscene);
}

void			createobjecttoaddmenuu(t_itf *interface)
{
	t_button	*plan;
	t_button	*disk;
	t_button	*lightadd;
	t_button	*ret;

	plan = crmenubutton(interface, "objectToAdd", "plan");
	disk = crmenubutton(interface, "objectToAdd", "disk");
	lightadd = crmenubutton(interface, "objectToAdd", "lightadd");
	ret = crmenubutton(interface, "objectToAdd", "ret");
	setbuttonposition(plan, 25, 170);
	setbuttonposition(disk, 25, 220);
	setbuttonposition(lightadd, 25, 270);
	setbuttonposition(ret, 25, 320);
	setbuttontext(plan, "Plan", interface);
	setbuttontext(disk, "Disk", interface);
	setbuttontext(lightadd, "Add Light", interface);
	setbuttontext(ret, "Return", interface);
	setbuttondefaultmenu(ret, "Scene");
	setbuttonfunction(disk, adddisk);
	setbuttonfunction(lightadd, addlight);
	setbuttonfunction(plan, addplan);
}

void			createobjecttoaddmenu(t_itf *interface)
{
	t_button	*cylinder;
	t_button	*sphere;
	t_button	*cone;

	background(interface, "objectToAdd");
	cylinder = crmenubutton(interface, "objectToAdd", "cylinder");
	sphere = crmenubutton(interface, "objectToAdd", "sphere");
	cone = crmenubutton(interface, "objectToAdd", "cone");
	setbuttonposition(cylinder, 25, 20);
	setbuttonposition(sphere, 25, 70);
	setbuttonposition(cone, 25, 120);
	setbuttontext(cylinder, "Cylindre", interface);
	setbuttontext(sphere, "Sphere", interface);
	setbuttontext(cone, "Cone", interface);
	setbuttonfunction(cylinder, addcylinder);
	setbuttonfunction(sphere, addsphere);
	setbuttonfunction(cone, addcone);
	createobjecttoaddmenuu(interface);
}
