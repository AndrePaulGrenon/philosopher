/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:16:16 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/17 19:29:22 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long int	ft_sleep(t_phil *me, long int timer, t_data *data)
{
	if (me->slp_start == 0 && me->sleeping)
	{
		me->slp_start = timer;
		printf("%ldms %d is sleeping\n", timer, me->index);
	}
	else if (timer - me->slp_start >= data->t_to_sleep)
	{
		me->sleeping = false;
		me->thinking = true;
		me->slp_start = 0;
		printf("%ldms %d is thinking\n", timer, me->index);
	}
	return (0);
}
