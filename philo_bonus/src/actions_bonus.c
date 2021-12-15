/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:52:47 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/12/10 19:52:49 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	take_forks(t_data *data )
{
	if (data->finish == 1)
		return ;
	sem_wait(data->sem_forks);
	if (write_msg_bonus(get_time_in_ms() - data->start_time, data, FORK) == 0)
	{
		sem_post(data->sem_forks);
		sem_post(data->sem_forks);
		return ;
	}
}

void	eat(t_data *data)
{
	sem_wait(data->meals);
	if (write_msg_bonus(get_time_in_ms() - data->start_time, data, EAT) == 0)
	{
		sem_post(data->sem_forks);
		sem_post(data->sem_forks);
		sem_post(data->meals);
		return ;
	}
	data->t_last_eat = get_time_in_ms();
	sem_post(data->meals);
	u_sleep(data->t_eat);
	data->must_eat_qty += 1;
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	if (data->must_eat_qty == data->times_eat + 1)
		data->flag_end_of_eating = 1;
	data->life_or_death = get_time_in_ms() - data->start_time + data->t_die;

}

void	sleeping(t_data *data)
{
	write_msg_bonus(get_time_in_ms() - data->start_time, data, SLEEP);
	u_sleep(data->t_sleep);
}

void	think(t_data *data)
{
	write_msg_bonus(get_time_in_ms() - data->start_time, data, THINK);
}
