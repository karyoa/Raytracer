/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interttface.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:35:32 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 21:35:45 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERTTFACE_H
# define INTERTTFACE_H

# include "libft.h"
# include "interface.h"
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_lab3
{
	t_label		*x;
	t_label		*y;
	t_label		*z;
}				t_lab3;

typedef struct	s_tf3
{
	t_tf		*tfx;
	t_tf		*tfy;
	t_tf		*tfz;
}				t_tf3;

typedef struct	s_lab4
{
	t_label		*w;
	t_label		*x;
	t_label		*y;
	t_label		*z;
}				t_lab4;

typedef struct	s_tf4
{
	t_tf		*tfw;
	t_tf		*tfx;
	t_tf		*tfy;
	t_tf		*tfz;
}				t_tf4;

void			filltype(t_object *object, t_itf *interface);

void			fillpos(t_object *object, t_itf *interface);

void			fillcol(t_object *object, t_itf *interface);

void			fillcolt(t_object *object, t_itf *interface);

void			fillrefl(t_object *object, t_itf *interface);

void			fillprop(t_object *object, t_itf *interface);

t_float3		obj_pos(t_itf *interface);

t_float3		obj_color(t_itf *interface);

t_float3		obj_colort(t_itf *interface);

void			obj_reflection(t_object *object, t_itf *interface);

void			obj_proportion(t_object *object, t_itf *interface);

void			obj_proportionn(t_object *object, t_itf *interface);

void			obj_proportionnn(t_object *object, t_itf *interface);

void			addcylinder(t_itf *interface);

void			addsphere(t_itf *interface);

void			addcone(t_itf *interface);

void			addplan(t_itf *interface);

void			adddisk(t_itf *interface);

void			createreflectform(t_itf *interface);

void			createcolform(t_itf *interface);

void			createcoltform(t_itf *interface);

void			createposform(t_itf *interface);

void			background(t_itf *interface, char *scene);

void			createscene(t_itf *interface);

void			addobject(t_itf *interface);

void			backtoaddobject(t_itf *interface);

void			createstartmenu(t_itf *interface);

void			createscenemenu(t_itf *interface);

void			createnamesceneform(t_itf *interface);

void			createpropform(t_itf *interface);

void			propform(t_itf *interface);

void			reflform(t_itf *interface);

void			colform(t_itf *interface);

void			coltform(t_itf *interface);

void			createobjecttoaddmenu(t_itf *interface);

void			createobjecttoaddmenuu(t_itf *interface);

void			createpropformmm(t_itf *interface);

void			createpropformm(t_itf *interface);

void			createpropform(t_itf *interface);

void			createmenuform(t_itf *interface);

void			maintest(void);

void			listfile(void);

char			*obj_name(t_itf *interface);

void			obj_reflectionn(t_object *object, t_itf *interface);

void			createcoltformm(t_itf *interface);

void			createreflectformm(t_itf *interface);

#endif
