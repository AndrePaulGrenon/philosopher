/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:00 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/17 19:13:00 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ft_point_fork(t_data *data)
{
	int	i;

	i = 0;
	while (data->agora[i])
	{
		if (!i)
			data->agora[i]->left = data->fork_set[data->nb_phil - 1];
		else
			data->agora[i]->left = data->fork_set[i - 1];
		data->agora[i]->right = data->fork_set[i];
		i++;
	}
	return ;
}

void	ft_set_agora(t_data *data, char **argv)
{
	int				i;
	struct timeval	time;

	gettimeofday(&time, NULL);
	i = 0;
	data->nb_to_fill = 0;
	data->is_on = true;
	data->nb_phil = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	data->fork_set = malloc(sizeof(pthread_mutex_t *) * data->nb_phil + 1);
	data->fork_set[data->nb_phil] = NULL;
	data->agora = malloc(sizeof(t_data *) * data->nb_phil + 1);
	data->agora[data->nb_phil] = NULL;
	data->t_start = time.tv_sec * 1000 + (long int) time.tv_usec / 1000;
	return ;
}

void	ft_place_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_phil)
	{
		data->fork_set[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->fork_set[i], NULL);
		data->agora[i] = malloc(sizeof(t_phil));
		data->agora[i]->data = (void *) data;
		data->agora[i]->index = i + 1;
		data->agora[i]->thinking = true;
		data->agora[i]->sleeping = false;
		data->agora[i]->eating = false;
		data->agora[i]->slp_start = 0;
		data->agora[i]->eat_start = 0;
		i++;
	}
	ft_point_fork(data);
	return ;
}

t_data	*ft_init_data(char **argv)
{
	t_data	*data;
	int		i;

	i = 1;
	data = malloc(sizeof(t_data));
	ft_set_agora(data, argv);
	ft_place_philosophers(data);
	if (argv[5])
		data->nb_to_fill = ft_atoi(argv[5]);
	while (i < 5)
	{
		if (ft_atoi(argv[i]) < 0 || data->nb_to_fill < 0)
		{
			ft_free_data(data);
			data = NULL;
			break ;
		}
		i++;
	}
	return (data);
}
