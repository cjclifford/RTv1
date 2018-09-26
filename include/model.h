/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:45:59 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/25 12:28:54 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "controller.h"

# include "../libft/includes/libft.h"
# include "../libft/includes/vec.h"
# include "../lib3d/includes/vec3.h"
# include "../lib3d/includes/mat.h"
# include "SDL.h"

# define FOV 30.0

typedef struct	s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	inverse_width;
	double	inverse_height;
	double	aspect_ratio;
	double	angle;
}				t_camera;

typedef struct	s_ray
{
	t_vec3	pos;
	t_vec3	dir;
	double	intersect;
}				t_ray;

typedef enum	e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	LIGHT
}				t_type;

typedef union	u_object t_object;

typedef struct	s_generic
{
	t_type		type;
	t_vec3		pos;
	t_vec3		normal;
	SDL_Colour	colour;
	int		(*intersect)(t_ray *, t_object *);
}				t_generic;

typedef struct	s_sphere
{
	t_generic	generic;
	double		radius;
	double		radius2;
}				t_sphere;

typedef struct	s_plane
{
	t_generic	generic;
}				t_plane;

typedef struct	s_cylinder
{
	t_generic	generic;
	t_vec3		dir;
	double		radius;
	double		radius2;
}				t_cylinder;

// TODO:
// cones

typedef struct	s_light
{
	t_generic	generic;
}				t_light;

typedef union	u_object
{
	t_generic	generic;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	t_light		light;
}				t_object;

typedef struct	s_scene
{
	t_vec			objects;
	t_camera		camera;
	SDL_Renderer	*renderer;
}				t_scene;

typedef struct	s_window
{
	SDL_Window	*window;
	int			width;
	int			height;
	int			x;
	int			y;
	int			flags;
}				t_window;

void			set_ray(int x, int y, t_camera *camera, t_ray *ray);

int				sph_intersect(t_ray *ray, t_object *object);
int				pln_intersect(t_ray *ray, t_object *object);
int				cyl_intersect(t_ray *ray, t_object *object);
//int				con_intersect(t_ray *ray, t_object *object);

void			render_scene(t_scene *scene, t_window *window);
void			update_scene(t_scene *scene, t_key *keys);

void	read_camera(int fd, t_scene *scene);
void	read_sphere(int fd, t_scene *scene);
void	read_light(int fd, t_scene *scene);
void	read_plane(int fd, t_scene *scene);
void	read_cylinder(int fd, t_scene *scene);

t_vec3	rotate_x(t_vec3 vec, double theta);
t_vec3	rotate_y(t_vec3 vec, double theta);
t_vec3	rotate_z(t_vec3 vec, double theta);

#endif
