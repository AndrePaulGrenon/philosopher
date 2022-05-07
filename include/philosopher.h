#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
#include <stdbool.h>

typedef struct	s_phil
{
	int		index;
	int		fourchette;
	void	*data;
	bool	thinking;
	bool	sleeping;
	bool	eating;
}				t_phil;

typedef struct	s_data
{
	int		nb_phil;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		nb_to_fill;
	t_phil	**agora;
}			t_data;

int		ft_atoi(char *str);
t_data	*ft_init_data(char **argv);

#endif
