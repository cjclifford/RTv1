/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:12:42 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/12 18:17:52 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

#include "fcntl.h"

void	read_camera(int fd, t_scene *scene)
{
	char		*line;
	char		**list;
	t_camera	camera;

	// TODO:
	// Error handling
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		camera.pos.x = ft_atoi(list[0]);
		camera.pos.y = ft_atoi(list[1]);
		camera.pos.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		camera.dir.x = ft_atoi(list[0]);
		camera.dir.y = ft_atoi(list[1]);
		camera.dir.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	scene->camera = camera;
}

void	read_sphere(int fd, t_scene *scene)
{
	char		*line;
	char		**list;
	t_sphere	sphere;

	sphere.generic.type = SPHERE;
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		sphere.generic.pos.x = ft_atoi(list[0]);
		sphere.generic.pos.y = ft_atoi(list[1]);
		sphere.generic.pos.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	if (get_next_line(fd, &line) > 0)
		sphere.radius = ft_atoi(line);
	free(line);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		sphere.generic.colour.r = ft_atoi(list[0]);
		sphere.generic.colour.g = ft_atoi(list[1]);
		sphere.generic.colour.b = ft_atoi(list[2]);
		sphere.generic.colour.a = ft_atoi(list[3]);
		free(list);
	}
	free(line);
	sphere.generic.intersect = &sph_intersect;
	vec_append(&scene->objects, &sphere);
}

void	read_light(int fd, t_scene *scene)
{
	char		*line;
	char		**list;
	t_light		light;

	light.generic.type = LIGHT;
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		light.generic.pos.x = ft_atoi(list[0]);
		light.generic.pos.y = ft_atoi(list[1]);
		light.generic.pos.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	vec_append(&scene->objects, &light);
}

void	read_plane(int fd, t_scene *scene)
{
	char	*line;
	char	**list;
	t_plane	plane;

	plane.generic.type = PLANE;
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		plane.generic.pos.x = ft_atoi(list[0]);
		plane.generic.pos.y = ft_atoi(list[1]);
		plane.generic.pos.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		plane.generic.normal.x = ft_atoi(list[0]);
		plane.generic.normal.y = ft_atoi(list[1]);
		plane.generic.normal.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	vec3_normalize(&plane.generic.normal);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		plane.generic.colour.r = ft_atoi(list[0]);
		plane.generic.colour.g = ft_atoi(list[1]);
		plane.generic.colour.b = ft_atoi(list[2]);
		plane.generic.colour.a = ft_atoi(list[3]);
		free(list);
	}
	free(line);
	plane.generic.intersect = &pln_intersect;
	vec_append(&scene->objects, &plane);
}
