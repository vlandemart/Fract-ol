/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvgx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:58:31 by njacobso          #+#    #+#             */
/*   Updated: 2019/05/06 20:16:11 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVGX_H
# define LIBVGX_H
# define SCREEN_W 1000
# define SCREEN_H 1000
# define DEBUG_LEVEL 0

# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_vector3;

typedef struct	s_mat4x4
{
	float m[4][4];
}				t_mat4x4;

typedef struct	s_triangle
{
	t_vector3 p[3];
}				t_triangle;

/*
** vectors
*/

t_vector3		vector3_new(float x, float y, float z);
t_vector3		vector3_from_list(t_list *lst);
t_vector3		vector3_add_f(t_vector3 v1, float num);
void			vector3_add_v3_p(t_vector3 *v1, t_vector3 v2);
t_vector3		vector3_add_v3(t_vector3 v1, t_vector3 num);
t_vector3		vector3_subtract_v3(t_vector3 v1, t_vector3 v2);
t_vector3		vector3_multiply_f(t_vector3 v1, float num);
t_vector3		vector3_multiply_v3(t_vector3 v1, t_vector3 v2);
t_vector3		vector3_divide_f(t_vector3 v1, float num);
float			vector3_dot_product(t_vector3 v1, t_vector3 v2);
float			vector3_length(t_vector3 v1);
t_vector3		vector3_normalize(t_vector3 v1);
t_vector3		vector3_cross_product(t_vector3 v1, t_vector3 v2);

/*
** matrix
*/

t_vector3		matrix_multiply_vector(t_mat4x4 m, t_vector3 v);
t_mat4x4		matrix_identity();
t_mat4x4		matrix_rot_x(float angle_rad);
t_mat4x4		matrix_rot_y(float angle_rad);
t_mat4x4		matrix_rot_z(float angle_rad);
t_mat4x4		matrix_make_translation(float x, float y, float z);
t_mat4x4		matrix_projection(float fov, float aspect, float near,
									float far);
t_mat4x4		matrix_multiplication(t_mat4x4 mat1, t_mat4x4 mat2);

/*
** debug
*/

void			debug_v3(t_vector3 v3, int debug_lvl);
void			debug_matrix(t_mat4x4 m, int debug_lvl);
void			debug_triangle(t_triangle tri, int debug_lvl);
void			debug_array(int **arr, int h, int w, int debug_lvl);
void			debug_array_element(int **arr, int i, int j, int debug_lvl);
void			debug_str(char *str, int debug_lvl);
void			debug_nbr(int nbr, int debug_lvl);

/*
** math stuff
*/

uint32_t		hex2int(char *hex);
float			percent(float start, float end, float current);
#endif
