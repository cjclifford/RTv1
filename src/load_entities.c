/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:12:42 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/10 15:31:15 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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

	sphere.type = SPHERE;
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		sphere.pos.x = ft_atoi(list[0]);
		sphere.pos.y = ft_atoi(list[1]);
		sphere.pos.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	if (get_next_line(fd, &line) > 0)
		sphere.radius = ft_atoi(line);
	free(line);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		sphere.colour.r = ft_atoi(list[0]);
		sphere.colour.g = ft_atoi(list[1]);
		sphere.colour.b = ft_atoi(list[2]);
		sphere.colour.a = ft_atoi(list[3]);
		free(list);
	}
	free(line);
	vec_append(&scene->objects, &sphere);
}

void	read_light(int fd, t_scene *scene)
{
	char		*line;
	char		**list;
	t_light		light;

	light.type = LIGHT;
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		light.pos.x = ft_atoi(list[0]);
		light.pos.y = ft_atoi(list[1]);
		light.pos.z = ft_atoi(list[2]);
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

	plane.type = PLANE;
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		plane.pos.x = ft_atoi(list[0]);
		plane.pos.y = ft_atoi(list[1]);
		plane.pos.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		plane.normal.x = ft_atoi(list[0]);
		plane.normal.y = ft_atoi(list[1]);
		plane.normal.z = ft_atoi(list[2]);
		free(list);
	}
	free(line);
	vec3_normalize(&plane.normal);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		plane.colour.r = ft_atoi(list[0]);
		plane.colour.g = ft_atoi(list[1]);
		plane.colour.b = ft_atoi(list[2]);
		plane.colour.a = ft_atoi(list[3]);
		free(list);
	}
	free(line);
	vec_append(&scene->objects, &plane);
}
