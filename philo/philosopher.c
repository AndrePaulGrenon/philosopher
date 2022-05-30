/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:21 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/28 13:44:47 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_ok(t_data *data, char **argv)
{
	int		i;
	bool	everyone;

	i = 0;
	everyone = true;
	while (data->agora[i])
	{
		if (data->agora[i]->t_to_death - ft_clock(data->agora[i]) <= 0)
			return (i + 1);
		i++;
	}
	i = 0;
	while (data->agora[i])
	{
		if (data->agora[i]->n_eat < data->nb_to_fill)
			return (0);
		i++;
	}
	if (argv[5])
		return (-1);
	else
		return (0);
}

void	ft_moderateur(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (1)
	{
		usleep(100);
		i = ft_ok(data, argv);
		if (i)
			break ;
	}
	data->is_on = false;
	usleep(1000);
	if (i > 0)
		printf("%ldms Philosopher %d is dead\n",
			ft_clock(data->agora[i - 1]), i);
	if (i < 0)
		printf("All Philosophers are full\n");
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
		write(2, "Error\n", 6);
	if (argc < 5 || argc > 6)
		return (0);
	data = ft_init_data(argv);
	if (!data)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_introduce_debate(data);
	ft_moderateur(data, argv);
	ft_free_data(data);
	return (0);
}
