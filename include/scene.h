/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:45:59 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/28 18:56:35 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include "light.h"
# include "camera.h"

# include "../libft/libft.h"

typedef struct	s_scene
{
	t_list	*objects;
	t_list	*lights;
	t_list	*cameras;
}				t_scene;

#endif
