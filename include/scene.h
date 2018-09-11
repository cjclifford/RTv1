/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:45:59 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/10 15:34:17 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include "light.h"
# include "camera.h"
# include "window.h"
# include "input.h"

# include "../libft/includes/libft.h"
# include "../libft/includes/vec.h"

# define FOV 30.0

typedef enum	e_type
{
	SPHERE = 0,
	PLANE = 1,
	CYLINDER = 2,
	CONE = 3,
	LIGHT = 4
}				t_type;

typedef union	u_object
{
	t_sphere	sphere;
	t_plane		plane;
	t_light		light;
}				t_object;

typedef struct	s_scene
{
	t_vec			objects;
	t_camera		camera;
	SDL_Renderer	*renderer;
}				t_scene;

void			render_scene(t_scene *scene, t_window *window);
void			update_scene(t_scene *scene, t_key *keys);

#endif
