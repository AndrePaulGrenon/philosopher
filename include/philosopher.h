/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:09:33 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/25 17:35:24 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_phil
{
	int				index;
	int				n_eat;
	int				fourchette;
	long int		t_to_death;
	long int		slp_start;
	long int		eat_start;
	void			*data;
	bool			thinking;
	bool			sleeping;
	bool			eating;
	pthread_t		body;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_phil;

typedef struct s_data
{
	bool				is_on;
	int					nb_phil;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_to_fill;
	long int			t_start;
	pthread_mutex_t		**fork_set;
	bool				*fork_use;
	t_phil				**agora;
}			t_data;

int			ft_atoi(char *str);
t_data		*ft_init_data(char **argv);
void		ft_free_data(t_data *data);
void		ft_introduce_debate(t_data *data);
void		*ft_behave(void *data);
void		ft_eat(t_phil *me, t_data *data, long int timer);
long int	ft_sleep(t_phil *me, long int timer, t_data *data);
long int	ft_clock(t_phil *me);
void		ft_is_eating(t_phil *me, t_data *data);
void		ft_take_left(t_phil *me, t_data *data, int fork);
void		ft_take_right(t_phil *me, t_data *data, int fork);

#endif
