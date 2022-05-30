/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrival.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:57:40 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/25 14:30:05 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_introduce_debate(t_data *data)
{
	int			i;
	pthread_t	*p_thread;

	i = 0;
	while (data->agora[i])
	{
		p_thread = &data->agora[i]->body;
		pthread_create(p_thread, NULL, ft_behave, (void *) data->agora[i]);
		i++;
	}
	return ;
}
