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

void    ft_eat(t_phil *me, t_data *data)
{

	pthread_mutex_lock(me->left);
	pthread_mutex_lock(me->right);
	printf("%ldms Philosopher %d is eating\n", ft_clock(me), me->index);
	usleep(data->t_to_eat * 1000);
	pthread_mutex_unlock(me->right);
	pthread_mutex_unlock(me->left);
	printf("%ldms Philosopher %d is sleeping\n", ft_clock(me), me->index);
	usleep(data->t_to_sleep * 1000);
	printf("%ldms Philosopher %d is thinking\n", ft_clock(me), me->index);
	return ;
}

void	*ft_behave(void *data)
{
	t_phil	*me;
	t_data	*data_d;
	long int timer;

	me = (t_phil *) data;
	data_d = (t_data *) me->data;
	timer  = ft_clock(me);
	while (1)
	{
		if (me->index % 2)
			usleep(1000);	
		//if (!(timer % 100) && timer != ft_clock(me))
		//	printf("%ldms Philosopher: %d\n", timer, me->index);
		ft_eat(me, data_d);	
		if (me->t_to_death < 0)
			break ;
		timer = ft_clock(me);
	}
	return (data);
}
