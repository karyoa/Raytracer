/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:15:29 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/20 23:15:38 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			addobject(t_itf *interface)
{
	switchmenu(interface, "objectToAdd");
}

void			backtoaddobject(t_itf *interface)
{
	t_object	object;

	obj_proportion(&object, interface);
	fillprop(&object, interface);
	switchmenu(interface, "objectToAdd");
}

void			createscenemenu(t_itf *interface)
{
	t_button	*add;
	t_button	*setcam;
	t_button	*ret;

	background(interface, "Scene");
	add = crmenubutton(interface, "Scene", "add");
	setbuttonposition(add, 25, 70);
	setcam = crmenubutton(interface, "Scene", "setcam");
	setbuttonposition(setcam, 25, 140);
	ret = crmenubutton(interface, "Scene", "ret");
	setbuttonposition(ret, 25, 210);
	setbuttontext(setcam, "Set Cam", interface);
	setbuttontext(ret, "Return", interface);
	setbuttontext(add, "Ajouter object", interface);
	setbuttonfunction(add, addobject);
	setbuttonfunction(setcam, addcam);
	setbuttondefaultmenu(ret, "start");
}

void			createstartmenu(t_itf *interface)
{
	t_label		*question;
	t_button	*create;
	t_button	*load;

	background(interface, "start");
	question = createmenulabel(interface, "start", "question");
	setlabelposition(question, 25, 50);
	setlabeltext(question, "Charger une scene existante ?", interface);
	load = crmenubutton(interface, "start", "load");
	setbuttonposition(load, 40, 100);
	setbuttontext(load, "Oui", interface);
	create = crmenubutton(interface, "start", "create");
	setbuttonposition(create, 40, 150);
	setbuttontext(create, "Non", interface);
	setbuttondefaultmenu(create, "scenename");
	setbuttonfunction(load, ok_load);
}
