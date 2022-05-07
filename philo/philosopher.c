#include "philosopher.h"

void	*ft_drink(void *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		//sleep(2);
		//printf("I drink %d \n", i);
		i++;
	}
	return (data);
}

int	main(int argc, char **argv)
{
	pthread_t	newthread;
	t_data		*data;

	(void) argc;
	data = ft_init_data(argv);
	printf("Philo: %d t_die: %d t_eat %d t_sleep %d\n",  data->nb_phil, data->t_to_die, data->t_to_eat, data->t_to_sleep);
	pthread_create(&newthread, NULL, ft_drink, (void *) data);
	pthread_join(newthread, NULL);	
	return (0);
}