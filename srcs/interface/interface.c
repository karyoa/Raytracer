/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:41:31 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 20:41:32 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			deleteinterface(t_itf *interface)
{
	SDL_FreeSurface(interface->result);
	SDL_FreeSurface(interface->rel_but);
	TTF_CloseFont(interface->font);
	SDL_FreeSurface(interface->hov_but);
	SDL_FreeSurface(interface->frame);
	while (interface->nbmenu > 0)
	{
		interface->nbmenu--;
		deletemenu(interface->menu[interface->nbmenu]);
	}
	ft_memdel((void**)(&(interface->menu)));
	ft_memdel((void**)(&interface));
}

t_env			*createenv(int w, int h, char *title)
{
	t_env		*env;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->interface = createinterface(w, h);
	env->win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
	return (env);
}

void			handleinterfaceevent(t_itf *interface, SDL_Event event)
{
	if (event.type == SDL_MOUSEMOTION)
		checkcmhoveredbutton(interface, event);
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		checkcmclickedtextfield(interface, event);
		execcmclickedbutton(interface, event);
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE)
		pullcmactivetextfield(interface);
	if (event.type == SDL_TEXTINPUT)
		appendcmactivetextfield(event.edit.text, interface);
}

void			updatewindow(t_env *env)
{
	SDL_BlitSurface(env->interface->result, NULL,
			SDL_GetWindowSurface(env->win), NULL);
	SDL_UpdateWindowSurface(env->win);
}
