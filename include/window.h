/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:01:24 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 18:58:08 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "../SDL2/include/SDL2/SDL.h"

typedef struct	s_window
{
	SDL_Window	*window;
	int			width;
	int			height;
	int			x;
	int			y;
}				t_window;

#endif
