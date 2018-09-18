/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:27:14 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/12 16:12:46 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "SDL.h"

int	handle_input(t_key *keys)
{
	SDL_Event	e;

	(void)keys;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return (1);
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			else if (e.key.keysym.sym == SDLK_w)
				keys->key_w = 1;
			else if (e.key.keysym.sym == SDLK_s)
				keys->key_s = 1;
			else if (e.key.keysym.sym == SDLK_a)
				keys->key_a = 1;
			else if (e.key.keysym.sym == SDLK_d)
				keys->key_d = 1;
			else if (e.key.keysym.sym == SDLK_UP)
				keys->key_up = 1;
			else if (e.key.keysym.sym == SDLK_DOWN)
				keys->key_down = 1;
			else if (e.key.keysym.sym == SDLK_LEFT)
				keys->key_left = 1;
			else if (e.key.keysym.sym == SDLK_RIGHT)
				keys->key_right = 1;
		}
		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_w)
				keys->key_w = 0;
			else if (e.key.keysym.sym == SDLK_s)
				keys->key_s = 0;
			else if (e.key.keysym.sym == SDLK_a)
				keys->key_a = 0;
			else if (e.key.keysym.sym == SDLK_d)
				keys->key_d = 0;
			else if (e.key.keysym.sym == SDLK_UP)
				keys->key_up = 0;
			else if (e.key.keysym.sym == SDLK_DOWN)
				keys->key_down = 0;
			else if (e.key.keysym.sym == SDLK_LEFT)
				keys->key_left = 0;
			else if (e.key.keysym.sym == SDLK_RIGHT)
				keys->key_right = 0;
		}
	}
	return (0);
}