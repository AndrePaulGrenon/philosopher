/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_behave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:14:16 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/20 16:39:05 by agrenon          ###   ########.fr       */
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

void	ft_eat(t_phil *me, t_data *data, long int timer)
{
	if (me->thinking && me->eat_start == 0)
	{
		me->thinking = false;
		me->eating = true;
		pthread_mutex_lock(me->left);
		printf("%ldms %d has taken a fork\n", ft_clock(me), me->index);
		pthread_mutex_lock(me->right);
		printf("%ldms %d has taken a fork\n", ft_clock(me), me->index);
		me->n_eat++;
		me->t_to_death = ft_clock(me) + data->t_to_die;
		me->eat_start = ft_clock(me);
		printf("%ldms %d is eating\n", ft_clock(me), me->index);
	}
	else if (timer - me->eat_start >= data->t_to_eat)
	{
		pthread_mutex_unlock(me->right);
		pthread_mutex_unlock(me->left);
		me->sleeping = true;
		me->eating = false;
		me->eat_start = 0;
	}
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
		timer = ft_clock(me);
		if (me->sleeping)
			ft_sleep(me, timer, data_d);
		else if ((me->thinking || me->eating) && data_d->nb_phil > 1)
			ft_eat(me, data_d, timer);
		if (me->t_to_death - timer <= 0 || data_d->is_on == false)
			break ;
	}
	pthread_mutex_unlock(me->right);
	pthread_mutex_unlock(me->left);
	return (NULL);
}
