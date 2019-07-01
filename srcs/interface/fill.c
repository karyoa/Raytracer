/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 01:49:28 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 01:54:00 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_tf		*createmenutextfield(t_itf *interface, char *mkey, char *tkey)
{
	t_tf	*tfd;

	tfd = NULL;
	tfd = createtextfield(tkey);
	if (tfd)
		addtextfield(interface, mkey, tfd);
	return (tfd);
}

t_tf		*getmenutextfield(t_itf *interface, char *mkey, char *tkey)
{
	t_menu	*menu;
	int		i;

	menu = NULL;
	menu = getmenu(interface, mkey);
	if (!menu)
		return (NULL);
	i = 0;
	while (i < menu->nbtextfield)
	{
		if (!ft_strcmp(menu->tf[i]->key, tkey))
			return (menu->tf[i]);
		i++;
	}
	return (NULL);
}

void		setitf(t_itf *interface)
{
	interface->nbmenu = 0;
	interface->currentmenu = NULL;
	interface->font = TTF_OpenFont("RobotoCondensed-Regular.ttf", 16);
	interface->t = 0;
}

t_itf		*createinterface(int w, int h)
{
	t_itf	*interface;

	if (!(interface = (t_itf*)ft_memalloc(sizeof(t_itf))))
		return (NULL);
	interface->result = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	interface->rel_but = SDL_CreateRGBSurface(0, w, h, 32, 0xff000000,
			0x00ff0000, 0x0000ff00, 0x000000ff);
	interface->hov_but = SDL_CreateRGBSurface(0, w, h, 32, 0xff000000,
			0x00ff0000, 0x0000ff00, 0x000000ff);
	interface->frame = SDL_CreateRGBSurface(0, w, h, 32, 0xff000000,
			0x00ff0000, 0x0000ff00, 0x000000ff);
	interface->textfield = SDL_CreateRGBSurface(0, w, h, 32, 0xff000000,
			0x00ff0000, 0x0000ff00, 0x000000ff);
	SDL_FillRect(interface->rel_but, NULL,
			SDL_MapRGBA(interface->rel_but->format, 50, 50, 50, 127));
	SDL_FillRect(interface->hov_but, NULL,
			SDL_MapRGBA(interface->hov_but->format, 100, 100, 200, 200));
	SDL_FillRect(interface->frame, NULL,
			SDL_MapRGBA(interface->frame->format, 15, 15, 15, 127));
	SDL_FillRect(interface->textfield, NULL,
			SDL_MapRGBA(interface->frame->format, 225, 225, 225, 127));
	setitf(interface);
	return (interface);
}
