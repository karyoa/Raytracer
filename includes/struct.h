/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:34:43 by mbeckert          #+#    #+#             */
/*   Updated: 2018/07/24 21:35:14 by mbeckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** struct floats
*/

# include <stdlib.h>
# include <rt.h>

typedef struct	s_float3
{
	float x;
	float y;
	float z;
}				t_float3;

typedef struct	s_float4
{
	float w;
	float x;
	float y;
	float z;
}				t_float4;

/*
** struct collisions
*/

/*
** struct lumieres
*/

typedef struct	s_light
{
	char		*name;
	t_float3	pos;
	t_float3	dir;
	t_float3	color;
	float		intensity;
	t_float3	luminance;
	float		ray;
	float		alpha;
}				t_light;

/*
** struct objets
*/

typedef struct	s_rotate
{
	t_float3	rot;
	float		mat[3][3];
	float		mat_i[3][3];
}				t_rotate;

typedef struct	s_object
{
	char		*name;
	int			type;
	int			limit;
	float		ray;
	float		alpha;
	t_float3	color;
	t_float3	color_t;
	t_float3	pos;
	t_float3	limit_min;
	t_float3	limit_max;
	t_rotate	rotate;
	float		diffuse_ambt;
	float		diffuse_refl;
	float		diffuse_refr;
	float		specular_refl;
	float		shininess;
	float		specular_refr;
	SDL_Texture	*col_tex;
	SDL_Texture	*pertu_tex;
	char		*col_path;
	char		*pertu_path;
}				t_object;

/*
** struct init
*/

typedef struct	s_cam
{
	t_float4	rotate_start;
	t_float4	rotate;
	t_float3	translate;
	t_float3	axis_x;
	t_float3	axis_y;
	t_float3	axis_z;
	t_float3	origin;
	float		alpha;
	float		fov;
	int			pitch;
	int			moved;
}				t_cam;

#endif
