#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct	s_phil
{
	int				index;
	int				fourchette;
	int				t_to_death;
	void			*data;
	bool			thinking;
	bool			sleeping;
	bool			eating;
	pthread_t		body;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_phil;

typedef struct	s_data
{
	int					nb_phil;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_to_fill;
	long int			t_start;
	pthread_mutex_t		**fork_set;
	t_phil				**agora;
}			t_data;

int		ft_atoi(char *str);
t_data	*ft_init_data(char **argv);
void	ft_free_data(t_data *data);
void	ft_introduce_debate(t_data *data);
void	ft_eat(t_phil *me, t_data *data);
void	*ft_behave(void *data);

#endif
