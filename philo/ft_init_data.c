#include <philosopher.h>

void	ft_set_agora(t_data *data, char **argv)
{
	data->nb_to_fill = 0;
	data->nb_phil =  ft_atoi(argv[1]);
	data->t_to_die =  ft_atoi(argv[2]);
	data->t_to_eat =  ft_atoi(argv[3]);
	data->t_to_sleep =  ft_atoi(argv[4]);
	return ;
}

void	ft_place_philosophers(t_data *data)
{
	int	i;

	i = 0;
	data->agora = malloc(sizeof(t_data *) * data->nb_phil + 1);
	data->agora[data->nb_phil] = NULL;
	while (i < data->nb_phil)
	{
		data->agora[i] = malloc(sizeof(t_phil));
		data->agora[i]->data = (void *) data;
		data->agora[i]->index = i + 1;
		data->agora[i]->thinking = false;
		data->agora[i]->sleeping = false;
		data->agora[i]->eating = false;
		printf("Philosopher: %d\n" , data->agora[i]->index);
		i++;
	}
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
		data->nb_to_fill =  ft_atoi(argv[5]); 
	while (i < 5)
	{
		if (ft_atoi(argv[i]) < 0 || data->nb_to_fill < 0)
		{
			free(data);
			data = NULL;
			break ;
		}
		i++;
	}
	return (data);
}
