/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inition.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:43:43 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/12/04 20:58:50 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	input_args(t_data *data, int argc, char **argv)
{
	data->ph_quantity = (unsigned int) atoii(argv[1]);
	data->t_die = (unsigned int) atoii(argv[2]);
	data->t_eat = (unsigned int) atoii(argv[3]);
	data->t_sleep = (unsigned int) atoii(argv[4]);
	if (argc == 6)
		data->times_eat = atoii(argv[5]);
	else
		data->times_eat = -1;
	if (data->ph_quantity == 0)
	{
		write(2, "Error: Incorrect symbol\n", 24);
		data->finish = 1;
	}
}

void	init_philo(t_data *data)
{
	size_t		i;

	i = -1;
	while (++i < data->ph_quantity)
		pthread_create(&data->ph_struct[i].ph, NULL, philo_actions,
			&data->ph_struct[i]);
}

int	init_philo_struct(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->ph_struct = (t_phil *)malloc(sizeof(t_phil) * data->ph_quantity);
	if (!data->ph_struct)
		return (-1);
	while (i < data->ph_quantity)
	{
		data->ph_struct[i].num_philo = i + 1;
		data->ph_struct[i].l_fork = &data->forks[i];
		data->ph_struct[i].r_fork = &data->forks[(i + 1) % data->ph_quantity];
		data->ph_struct[i].print = data->print;
		data->ph_struct[i].id = i + 1;
		data->ph_struct[i].data = data;
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->ph_quantity);
	if (!data->forks)
		return (-1);
	while (i < data->ph_quantity)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (0);
}

void	init_time(t_data *data)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	data->start_time = (current_time.tv_sec) * 1000 \
	+ (current_time.tv_usec) / 1000;
}
