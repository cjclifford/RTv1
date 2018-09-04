/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:45:59 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/04 15:52:35 by ccliffor         ###   ########.fr       */
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

# define FOV 90.0

typedef struct	s_scene
{
	t_vec			spheres;
	t_vec			lights;
	t_camera		camera;
	SDL_Renderer	*renderer;
}				t_scene;

void			render_scene(t_scene *scene, t_window *window);
void			update_scene(t_scene *scene, t_key *keys);
void			read_scene(char *path, t_scene *scene);

#endif
