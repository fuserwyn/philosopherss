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

void	one_philo(t_data *data, unsigned int i)
{
	if (data->ph_quantity == 1)
	{
		write_msg(get_time_in_ms() - data->start_time,
			&data->ph_struct[i], FORK);
		write_msg(data->t_die,
			&data->ph_struct[i], DIE);
		data->finish = 1;
	}
}

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
	pthread_mutex_init(&data->ph_struct->defend, NULL);
	pthread_mutex_lock(&data->ph_struct->defend);
	while (data->finish == 0)
	{
		i = 0;
		while (i < data->ph_quantity)
		{
			one_philo(data, i);
			data->ph_struct[i].ph_die--;
			pthread_mutex_unlock(&data->ph_struct[i].defend);
			usleep(1);
			pthread_mutex_lock(&data->ph_struct[i].defend);
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
