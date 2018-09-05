/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:08:02 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/05 11:07:30 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "fcntl.h"

static void	read_camera(int fd, t_scene *scene)
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
	}
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		camera.dir.x = ft_atoi(list[0]);
		camera.dir.y = ft_atoi(list[1]);
		camera.dir.z = ft_atoi(list[2]);
	}
	scene->camera = camera;
}

static void	read_sphere(int fd, t_scene *scene)
{
	char		*line;
	char		**list;
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		sphere->pos.x = ft_atoi(list[0]);
		sphere->pos.y = ft_atoi(list[1]);
		sphere->pos.z = ft_atoi(list[2]);
	}
	if (get_next_line(fd, &line) > 0)
		sphere->radius = ft_atoi(line);
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		sphere->colour.r = ft_atoi(list[0]);
		sphere->colour.g = ft_atoi(list[1]);
		sphere->colour.b = ft_atoi(list[2]);
		sphere->colour.a = ft_atoi(list[3]);
	}
	if (!scene->spheres.length)
		vec_init(&scene->spheres, sizeof(t_sphere), 1);
	vec_append(&scene->spheres, sphere);
}

static void	read_light(int fd, t_scene *scene)
{
	char		*line;
	char		**list;
	t_light		*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, ' ');
		light->pos.x = ft_atoi(list[0]);
		light->pos.y = ft_atoi(list[1]);
		light->pos.z = ft_atoi(list[2]);
	}
	if (!scene->lights.length)
		vec_init(&scene->lights, sizeof(t_light), 1);
	vec_append(&scene->lights, light);
}

void		read_scene(char *path, t_scene *scene)
{
	int		fd;
	char	*line;

	// TODO:
	// return error if file doesnt exist
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "CAMERA"))
			read_camera(fd, scene);
		else if (ft_strstr(line, "SPHERE"))
			read_sphere(fd, scene);
		else if (ft_strstr(line, "LIGHT"))
			read_light(fd, scene);
	}
}