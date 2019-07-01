/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:28:29 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 21:28:31 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>

# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2/SDL_thread.h>
# include <libft.h>
# include <math.h>
# include <dirent.h>
# include <struct.h>
# include <interface.h>
# include <interttface.h>
# include <png.h>

enum			e_objects
{
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	DISK
};

void				ok_load(void);

void				put_obj_type(int fd, t_object *obj);

void				put_t_float3(char *key, t_float3 val, int fd);

void				put_t_float4(char *key, t_float4 val, int fd);

void				put_int(char *key, int val, int fd);

void				put_float(char *key, float val, int fd);

void				createlightposform(t_itf *interface);

void				createlightposformm(t_itf *interface);

void				createlightcolform(t_itf *interface);

void				createlightdirform(t_itf *interface);

void				createlightlumform(t_itf *interface);

void				createlightfform(t_itf *interface);

t_float3			light_pos(t_itf *interface);

char				*light_name(t_itf *interface);

t_float3			light_col(t_itf *interface);

t_float3			light_dir(t_itf *interface);

t_float3			light_lum(t_itf *interface);

void				light_fin(t_light *light, t_itf *interface);

void				lightposform(t_itf *interface);

void				lightcolform(t_itf *interface);

void				lightdirform(t_itf *interface);

void				lightlumform(t_itf *interface);

void				lightfinform(t_itf *interface);

void				filllightpos(t_light *light, t_itf *interface);

void				filllightcol(t_light *light, t_itf *interface);

void				filllightdir(t_light *light, t_itf *interface);

void				filllightlum(t_light *light, t_itf *interface);

void				filllightfin(t_light *light, t_itf *interface);

void				addlight(t_itf *interface);

void				createcamposform(t_itf *interface);

void				createcamrotform(t_itf *interface);

void				createcamfinform(t_itf *interface);

t_float3			cam_pos(t_itf *interface);

t_float4			cam_rot(t_itf *interface);

void				cam_fin(t_cam *cam, t_itf *interface);

void				camposform(t_itf *interface);

void				camrotform(t_itf *interface);

void				camfinform(t_itf *interface);

void				fillcampos(t_cam *cam, t_itf *interface);

void				fillcamrot(t_cam *cam, t_itf *interface);

void				fillcamfin(t_cam *cam, t_itf *interface);

void				addcam(t_itf *interface);

t_float3			obj_rot(t_itf *interface);

#endif
