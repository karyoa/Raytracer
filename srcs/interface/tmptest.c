/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmptest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:41:43 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 20:41:44 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				reflform(t_itf *interface)
{
	t_object		object;

	object.color_t = obj_colort(interface);
	object.name = obj_name(interface);
	fillcolt(&object, interface);
	switchmenu(interface, "sceneRefl");
}

void				colform(t_itf *interface)
{
	t_object		object;

	object.pos = obj_pos(interface);
	object.rotate.rot = obj_rot(interface);
	fillpos(&object, interface);
	switchmenu(interface, "SceneCol");
}

void				coltform(t_itf *interface)
{
	t_object		object;

	object.color = obj_color(interface);
	fillcol(&object, interface);
	switchmenu(interface, "SceneColt");
}

void				createmenuform(t_itf *interface)
{
	createstartmenu(interface);
	createscenemenu(interface);
	createobjecttoaddmenu(interface);
	createnamesceneform(interface);
	createposform(interface);
	createcolform(interface);
	createcoltform(interface);
	createreflectform(interface);
	createpropform(interface);
	createlightposform(interface);
	createlightcolform(interface);
	createlightdirform(interface);
	createlightlumform(interface);
	createlightfform(interface);
	createcamposform(interface);
	createcamrotform(interface);
	createcamfinform(interface);
}

void				maintest(void)
{
	t_env			*env;
	SDL_Event		event;

	env = createenv(640, 360, "SDL Interface");
	env->main_surface = SDL_LoadBMP("GGS_logo.bmp");
	env->interface->img = env->main_surface;
	createmenuform(env->interface);
	switchmenu(env->interface, "start");
	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
		{
			deleteinterface(env->interface);
			SDL_FreeSurface(env->main_surface);
			SDL_DestroyWindow(env->win);
			ft_memdel((void**)(&env));
			TTF_Quit();
			SDL_Quit();
			exit(0);
		}
		handleinterfaceevent(env->interface, event);
		updatewindow(env);
	}
}
