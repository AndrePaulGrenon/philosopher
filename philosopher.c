#include "philosopher.h"

void	ft_eat(void)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		sleep(1);
		printf("I eat!\n");
		i++;
	}
}

void	*ft_drink(void *arg)
{
	int	i;
	int *a;

	a = malloc(sizeof(int));
	*a = *(int *) arg;
	i = 0;
	while (i < 10)
	{
		sleep(2);
		printf("I drink %d \n", *a + i);
		i++;
	}
	*a = *a + i;
	return (a);
}

int	main(void)
{
	int ap;
	int *a;
	pthread_t newthread;

	ap = 5;
	pthread_create(&newthread, NULL, ft_drink, &ap);
	ft_eat();
	pthread_join(newthread, (void *) &a);
	printf("PRINT a: %d\n", *a);
	free(a);
	return (0);
}
