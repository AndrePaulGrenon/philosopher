#include <philosopher.h>

t_data	*ft_init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->nb_phil =  ft_atoi(argv[1]);
	data->t_to_die =  ft_atoi(argv[2]);
	data->t_to_eat =  ft_atoi(argv[3]);
	data->t_to_sleep =  ft_atoi(argv[4]);
	if (argv[5])
		data->nb_to_fill =  ft_atoi(argv[5]);
	return (data);
}
