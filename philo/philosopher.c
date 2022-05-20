/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:21 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/17 19:10:47 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_moderateur(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		usleep(1000);
		if (i >= data->nb_phil)
			i = 0;
		if (data->agora[i]->t_to_death - ft_clock(data->agora[i]) <= 0)
			break ;
		i++;
	}
	data->is_on = false;
	usleep(1000);
	printf("%ldms Philosopher %d is dead\n", ft_clock(data->agora[i]), i + 1);
	i = 0;
	while (data->agora[i])
	{
		pthread_join(data->agora[i]->body, NULL);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc < 5 || argc > 6)
		return (0);
	data = ft_init_data(argv);
	if (!data)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_introduce_debate(data);
	ft_moderateur(data);
	ft_free_data(data);
	return (0);
}
