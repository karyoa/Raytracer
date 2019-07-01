/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:28:46 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 21:28:48 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>

typedef struct		s_button
{
	char			isactive;
	char			*val;
	SDL_Rect		p;
	SDL_Surface		*text;
	void			(*f)();
	char			*key;
	char			*dftmenu;
	void			*functionarg;
}					t_button;

typedef struct		s_tf
{
	char			isactive;
	char			*val;
	SDL_Rect		p;
	SDL_Surface		*text;
	char			*key;
}					t_tf;

typedef struct		s_label
{
	char			*val;
	SDL_Rect		p;
	SDL_Surface		*text;
	char			*key;
}					t_label;

typedef struct		s_menu
{
	t_button		**but;
	t_tf			**tf;
	t_label			**label;
	int				nbbutton;
	int				nbtextfield;
	int				nblabel;
	SDL_Rect		bg;
	char			*key;
}					t_menu;

typedef struct		s_interface
{
	SDL_Surface		*img;
	SDL_Surface		*result;
	SDL_Surface		*rel_but;
	SDL_Surface		*hov_but;
	SDL_Surface		*frame;
	SDL_Surface		*textfield;
	TTF_Font		*font;
	t_menu			**menu;
	int				nbmenu;
	t_menu			*currentmenu;
	unsigned int	t;
	int				fd;
}					t_itf;

typedef struct		s_env
{
	t_itf			*interface;
	SDL_Window		*win;
	SDL_Surface		*main_surface;
}					t_env;

t_itf				*createinterface(int w, int h);

void				deleteinterface(t_itf *interface);

void				addbutton(t_itf *interface, char *menu, t_button *but);

t_button			*createbutton(char *key);

t_button			*crmenubutton(t_itf *interface, char *mkey, char *bkey);

void				setbuttonposition(t_button *but, int x, int y);

void				deletebutton(t_button *but);

void				addmenu(t_itf *interface, t_menu *menu);

t_menu				*createmenu(char *key);

void				deletemenu(t_menu *menu);

t_menu				*getmenu(t_itf *interface, char *key);

void				updateinterface(t_itf *interface);

void				setnextbutton(t_button *r, t_button *l,
		t_button *u, t_button *d);

void				setbuttonfunction(t_button *but, void (*f)());

t_env				*createenv(int w, int h, char *title);

void				updatewindow(t_env *env);

void				checkcmhoveredbutton(t_itf *interface, SDL_Event event);

void				displaybuttoncmi(t_itf *interface, int i);

void				execcmclickedbutton(t_itf *interface, SDL_Event event);

void				setbuttontext(t_button *but, char *text, t_itf *interface);

void				appendcmitextfield(int i, char *text, t_itf *interface);

void				appendcmactivetextfield(char *text, t_itf *interface);

void				switchmenu(t_itf *interface, char *menu);

void				addtextfield(t_itf *interface, char *menukey, t_tf *tf);

t_tf				*createtextfield(char *key);

t_tf				*createmenutextfield(t_itf *interface,
		char *mkey, char *tkey);

void				settextfieldposition(t_tf *tfd, int x, int y, int w);

t_label				*createlabel(char *key);

void				setlabeltext(t_label *lab, char *text, t_itf *interface);

t_label				*createmenulabel(t_itf *interface, char *mkey, char *lkey);

void				setlabelposition(t_label *lab, int x, int y);

void				displaylabelcmi(t_itf *interface, int i);

void				addlabel(t_itf *interface, char *key, t_label *label);

void				checkcmclickedtextfield(t_itf *interface, SDL_Event event);

void				displaytextfieldcmi(t_itf *interface, int i);

void				settextfieldtext(t_tf *tfd, char *text, t_itf *interface);

void				pullcmactivetextfield(t_itf *interface);

void				handleinterfaceevent(t_itf *interface, SDL_Event event);

void				setbuttondefaultmenu(t_button *but, char *key);

t_button			*getmenubutton(t_itf *interface, char *mkey, char *bkey);

t_tf				*getmenutextfield(t_itf *interface, char *mkey,
		char *tkey);

void				setitf(t_itf *interface);

#endif
