/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:16:09 by ccliffor          #+#    #+#             */
/*   Updated: 2018/09/12 16:08:55 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "model.h"
# include "controller.h"

t_scene		*init_scene(t_window *window, char *path);
t_window	*init_window(void);
t_key		*init_input(void);

#endif
