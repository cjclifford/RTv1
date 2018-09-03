/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:16:09 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/03 12:34:50 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "scene.h"
# include "window.h"
# include "input.h"

t_scene		*init_scene(t_window *window, char *path);
t_window	*init_window(void);
t_key		*init_input(void);

#endif
