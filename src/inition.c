#include "../includes/philosophers.h"

void	input_args(t_data *data, int argc, char **argv)
{
	data->ph_qty = (unsigned int) atoii(argv[1]);
	data->die = (unsigned int) atoii(argv[2]);
	data->t_eat = (unsigned int) atoii(argv[3]);
	data->t_sleep = (unsigned int) atoii(argv[4]);
	if (argc == 6)
		data->times_eat = atoii(argv[5]);
	else
		data->times_eat = -1;
}

void	init_philo(t_data *data)
{
	size_t		i;
//	uint64_t	time;
//	pthread_t 	thread;

	i = 0;
	while (i < data->ph_qty)
	{
		pthread_create(&data->ph_struct[i].ph, NULL, philo_actions,
					   &data->ph_struct[i]);
		i++;
	}
}


void	init_philo_struct(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->ph_struct = (t_phil *)malloc(sizeof(t_phil) * data->ph_qty);
	while (i < data->ph_qty)
	{
		data->ph_struct[i].nnum_philo = i + 1;
		data->ph_struct[i].l_fork = &data->forks[i];
		data->ph_struct[i].r_fork = &data->forks[(i + 1) % data->ph_qty];
        data->ph_struct[i].print = data->print;
		data->ph_struct[i].id = i + 1;
		data->ph_struct[i].data = data;
		data->live_or_death = 0;
		i++;
	}
}

void	init_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->ph_qty);
	if (!data->forks)
		return ;
	while (i < data->ph_qty)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_time(t_data *data)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	data->start_time = (current_time.tv_sec) * 1000 \
	+ (current_time.tv_usec) / 1000;
}
