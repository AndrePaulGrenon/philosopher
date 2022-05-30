/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_behave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:14:16 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/28 13:26:03 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long int	ft_clock(t_phil *me)
{
	struct timeval	time;
	long int		ms;
	long int		t_time;
	t_data			*data;

	data = (t_data *) me->data;
	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + (long int) time.tv_usec / 1000;
	t_time = ms - data->t_start;
	return (t_time);
}

bool	ft_is_lock(int fork, t_data *data)
{
	if (data->fork_use[fork])
		return (true);
	return (false);
}

void	ft_done_eating(t_phil *me, t_data *data, int left, int right)
{
	pthread_mutex_unlock(me->right);
	pthread_mutex_unlock(me->left);
	data->fork_use[right] = false;
	data->fork_use[left] = false;
	me->sleeping = true;
	me->eating = false;
	me->eat_start = 0;
	return ;
}

void	ft_eat(t_phil *me, t_data *data, long int timer)
{
	int	left;
	int	right;

	right = me->index - 1;
	if (me->index == 1)
		left = data->nb_phil - 1;
	else
		left = me->index - 2;
	if (!ft_is_lock(right, data))
		ft_take_right(me, data, right);
	if (!ft_is_lock(left, data) && right != left)
		ft_take_left(me, data, left);
	if (me->fourchette > 1)
		ft_is_eating(me, data);
	else if (timer - me->eat_start >= data->t_to_eat && me->thinking == false)
		ft_done_eating(me, data, left, right);
	return ;
}

void	*ft_behave(void *data)
{
	t_phil		*me;
	t_data		*data_d;
	long int	timer;

	me = (t_phil *) data;
	data_d = (t_data *) me->data;
	timer = ft_clock(me);
	me->t_to_death = timer + data_d->t_to_die;
	if (me->index % 2)
		usleep(1000);
	while (1)
	{
		usleep(100);
		timer = ft_clock(me);
		if (me->sleeping)
			ft_sleep(me, timer, data_d);
		else if ((me->thinking || me->eating))
			ft_eat(me, data_d, timer);
		if (me->t_to_death - timer <= 0 || data_d->is_on == false)
			break ;
	}
	pthread_mutex_unlock(me->right);
	pthread_mutex_unlock(me->left);
	return (NULL);
}
