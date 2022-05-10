#include "philosopher.h"

void	ft_introduce_debate(t_data *data)
{
	int		i;

	i = 0;
	while (data->agora[i])
	{
		pthread_create(&data->agora[i]->body, NULL, ft_behave, (void *) data->agora[i]);
		i++;
	}
	return ;
}
