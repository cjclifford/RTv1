/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:32:02 by ccliffor          #+#    #+#             */
/*   Updated: 2018/08/29 18:08:25 by ccliffor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct	s_key
{
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
}				t_key;

void	handle_input(t_key *keys);

#endif
