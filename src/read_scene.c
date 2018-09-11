/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:08:02 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/10 15:27:41 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "load_entities.h"

#include "fcntl.h"

void		read_scene(char *path, t_scene *scene)
{
	int		fd;
	char	*line;

	// TODO:
	// return error if file doesnt exist
	vec_init(&scene->objects, sizeof(t_object), 1);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "CAMERA"))
			read_camera(fd, scene);
		else if (ft_strstr(line, "SPHERE"))
			read_sphere(fd, scene);
		else if (ft_strstr(line, "LIGHT"))
			read_light(fd, scene);
		else if (ft_strstr(line, "PLANE"))
			read_plane(fd, scene);
	}
}