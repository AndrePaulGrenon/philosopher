/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:11:08 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/28 13:42:23 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = nb * 10;
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->agora)
		{
			while (data->agora[i])
			{
				free(data->agora[i]);
				free(data->fork_set[i++]);
			}
			free(data->agora);
			free(data->fork_set);
			free(data->fork_use);
		}
		free(data);
	}
	data = NULL;
	return ;
}
