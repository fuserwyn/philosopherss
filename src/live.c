/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:45:07 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/12/04 20:45:09 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_actions(void *arg)
{
	t_phil	*ph;

	ph = (t_phil *)arg;
	ph->ph_last_eat_time = ph->data->start_time;
	if (ph->id % 2 == 1)
		u_sleep(ph->data->t_eat);
	while (ph->data->finish == 0)
	{
		eat(ph);
		sleeping(ph);
		think(ph);
	}
	return (NULL);
}

void	*life(t_data *data)
{
	unsigned int	i;

	init_philo(data);
	while (data->finish == 0)
	{
		i = 0;
		while (i < data->ph_quantity)
		{
			data->ph_struct[i].ph_die--;
			if (data->ph_struct[i].ph_die == 0)
			{
				data->finish = 1;
				write_msg(get_time_in_ms() - data->start_time, \
					&data->ph_struct[i], DIE);
				return (NULL);
			}
			if (data->ph_struct[i].flag_end_of_eating == 1)
				data->finish = 1;
			i++;
		}
		u_sleep(1);
	}
	return (NULL);
}