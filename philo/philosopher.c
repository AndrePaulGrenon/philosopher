#include "philosopher.h"

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
	printf("Time : %ld\n", data->t_start);
	printf("Philo: %d t_die: %d t_eat %d t_sleep %d\n",  data->nb_phil, data->t_to_die, data->t_to_eat, data->t_to_sleep);
	ft_introduce_debate(data);

	pthread_join(data->agora[1]->body, NULL);	
	ft_free_data(data);
	return (0);
}
