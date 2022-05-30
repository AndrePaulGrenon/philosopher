/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_habits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:25:24 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/28 13:28:57 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_is_eating(t_phil *me, t_data *data)
{
	me->fourchette = 0;
	me->thinking = false;
	me->eating = true;
	me->n_eat++;
	me->t_to_death = ft_clock(me) + data->t_to_die;
	me->eat_start = ft_clock(me);
	printf("%ldms %d is eating\n", ft_clock(me), me->index);
	return ;
}

void	ft_take_left(t_phil *me, t_data *data, int fork)
{
	pthread_mutex_lock(me->left);
	data->fork_use[fork] = true;
	printf("%ldms %d has taken a fork\n", ft_clock(me), me->index);
	me->fourchette++;
}

void	ft_take_right(t_phil *me, t_data *data, int fork)
{
	pthread_mutex_lock(me->right);
	data->fork_use[fork] = true;
	printf("%ldms %d has taken a fork\n", ft_clock(me), me->index);
	me->fourchette++;
}
