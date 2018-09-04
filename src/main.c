/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:51:52 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/04 13:35:49 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "init.h"
#include "input.h"

#include "SDL.h"

int	main(int ac, char **av)
{
	t_scene		*scene;
	t_window	*window;
	t_key		*keys;
	int			quit;

	if (ac > 1)
	{
		window = init_window();
		scene = init_scene(window, av[1]);
		keys = init_input();
		quit = 0;
		while (!quit)
		{
			quit = handle_input(keys);
			update_scene(scene, keys);
			render_scene(scene, window);
		}
		SDL_DestroyWindow(window->window);
		SDL_Quit();
	}
	return (0);
}