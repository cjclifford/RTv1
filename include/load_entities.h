/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_entities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:11:22 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/05 15:22:38 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_ENTITIES_H
# define LOAD_ENTITIES_H

# include "scene.h"

void	read_camera(int fd, t_scene *scene);
void	read_sphere(int fd, t_scene *scene);
void	read_light(int fd, t_scene *scene);
void	read_plane(int fd, t_scene *scene);

#endif
