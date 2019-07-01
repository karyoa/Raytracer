/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textfield.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 01:26:52 by mbeckert          #+#    #+#             */
/*   Updated: 2018/04/21 01:42:56 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			displaytextfieldcmi(t_itf *interface, int i)
{
	SDL_Rect	r;
	SDL_Rect	t;

	SDL_BlitSurface(interface->img, &(interface->currentmenu->tf[i]->p),
			interface->result, &(interface->currentmenu->tf[i]->p));
	SDL_BlitSurface(interface->textfield,
			&(interface->currentmenu->tf[i]->p), interface->result,
			&(interface->currentmenu->tf[i]->p));
	r.x = interface->currentmenu->tf[i]->p.x + 8;
	r.y = interface->currentmenu->tf[i]->p.y + 8;
	SDL_GetClipRect(interface->currentmenu->tf[i]->text, &t);
	if (t.w > interface->currentmenu->tf[i]->p.w - 16)
		t.x = t.w - interface->currentmenu->tf[i]->p.w + 16;
	t.w = interface->currentmenu->tf[i]->p.w - 16;
	SDL_BlitSurface(interface->currentmenu->tf[i]->text, &t,
			interface->result, &r);
}

void			checkcmclickedtextfield(t_itf *interface, SDL_Event event)
{
	int			i;

	i = 0;
	while (i < interface->currentmenu->nbtextfield)
	{
		if ((event.motion.x >= interface->currentmenu->tf[i]->p.x &&
	event.motion.x <= interface->currentmenu->tf[i]->p.x +
	interface->currentmenu->tf[i]->p.w && event.motion.y >=
	interface->currentmenu->tf[i]->p.y && event.motion.y <=
	interface->currentmenu->tf[i]->p.y + interface->currentmenu->tf[i]->p.h
	&& !interface->currentmenu->tf[i]->isactive) || ((event.motion.x <
		interface->currentmenu->tf[i]->p.x || event.motion.x >
		interface->currentmenu->tf[i]->p.x + interface->currentmenu->tf[i]->p.w
		|| event.motion.y < interface->currentmenu->tf[i]->p.y || event.motion.y
		> interface->currentmenu->tf[i]->p.y +
		interface->currentmenu->tf[i]->p.h) &&
	interface->currentmenu->tf[i]->isactive))
		{
			interface->currentmenu->tf[i]->isactive =
				interface->currentmenu->tf[i]->isactive ? 0 : 1;
		}
		i++;
	}
}

void			appendcmitextfield(int i, char *text, t_itf *interface)
{
	SDL_Rect	r;
	SDL_Color	col;
	t_tf		*tf;
	char		*tmp;

	tf = interface->currentmenu->tf[i];
	col.r = 255;
	col.g = 255;
	col.b = 255;
	tmp = ft_strjoin(tf->val, text);
	ft_strdel(&(tf->val));
	tf->val = tmp;
	tf->text = TTF_RenderText_Solid(interface->font, tf->val, col);
	SDL_GetClipRect(tf->text, &r);
	displaytextfieldcmi(interface, i);
	SDL_FreeSurface(tf->text);
}

void			pullcmactivetextfield(t_itf *interface)
{
	int			i;

	i = 0;
	while (i < interface->currentmenu->nbtextfield)
	{
		if (interface->currentmenu->tf[i]->isactive)
		{
			if (ft_strlen(interface->currentmenu->tf[i]->val) > 0)
			{
				interface->currentmenu->tf[i]->val[ft_strlen(
						interface->currentmenu->tf[i]->val) - 1] = '\0';
				appendcmitextfield(i, "", interface);
			}
		}
		i++;
	}
}

void			settextfieldtext(t_tf *t, char *text, t_itf *interface)
{
	SDL_Rect	r;
	SDL_Color	col;

	col.r = 255;
	col.g = 255;
	col.b = 255;
	t->val = ft_strdup(text);
	t->text = TTF_RenderText_Solid(interface->font, t->val, col);
	SDL_GetClipRect(t->text, &r);
}
