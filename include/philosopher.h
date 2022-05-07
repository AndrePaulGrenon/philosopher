#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_data
{
	int		nb_phil;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		nb_to_fill;
}			t_data;

typedef struct	s_phil
{
	int		index;
	void	*data;
}				t_phil;

int		ft_atoi(char *str);
t_data	*ft_init_data(char **argv);

#endif
