/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boutton.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:43:48 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 00:54:12 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			checkcmhoveredbutton(t_itf *interface, SDL_Event event)
{
	int			i;

	i = 0;
	while (i < interface->currentmenu->nbbutton)
	{
		if ((event.motion.x >= interface->currentmenu->but[i]->p.x &&
	event.motion.x <= interface->currentmenu->but[i]->p.x +
	interface->currentmenu->but[i]->p.w && event.motion.y >=
	interface->currentmenu->but[i]->p.y && event.motion.y <=
	interface->currentmenu->but[i]->p.y + interface->currentmenu->but[i]->p.h
	&& !interface->currentmenu->but[i]->isactive) || ((event.motion.x <
	interface->currentmenu->but[i]->p.x || event.motion.x >
	interface->currentmenu->but[i]->p.x + interface->currentmenu->but[i]->p.w
	|| event.motion.y < interface->currentmenu->but[i]->p.y || event.motion.y
		> interface->currentmenu->but[i]->p.y +
		interface->currentmenu->but[i]->p.h) &&
	interface->currentmenu->but[i]->isactive))
		{
			interface->currentmenu->but[i]->isactive =
				interface->currentmenu->but[i]->isactive ? 0 : 1;
			displaybuttoncmi(interface, i);
		}
		i++;
	}
}

void			execcmclickedbutton(t_itf *interface, SDL_Event event)
{
	int			i;

	checkcmhoveredbutton(interface, event);
	i = 0;
	while (i < interface->currentmenu->nbbutton && i != -1)
	{
		if (event.motion.x >= interface->currentmenu->but[i]->p.x
				&& event.motion.x <= interface->currentmenu->but[i]->p.x +
				interface->currentmenu->but[i]->p.w
				&& event.motion.y >= interface->currentmenu->but[i]->p.y
				&& event.motion.y <= interface->currentmenu->but[i]->p.y +
				interface->currentmenu->but[i]->p.h)
		{
			if (interface->currentmenu->but[i]->f)
				interface->currentmenu->but[i]->f(interface);
			else if (interface->currentmenu->but[i]->dftmenu)
				switchmenu(interface, interface->currentmenu->but[i]->dftmenu);
			i = -2;
		}
		i++;
	}
}
