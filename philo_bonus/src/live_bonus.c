#include "../includes/philosophers_bonus.h"

void	one_philo(t_data *data)
{
	if (data->ph_quantity == 1)
	{
		write_msg_bonus(get_time_in_ms() - data->start_time, \
                    data, FORK);
		write_msg_bonus(data->die, \
                    data, DIE);
		data->finish = 1;
	}
}

void	*philo_actions(t_data *data)
{
	pthread_t	live;

	if (pthread_create(&live, NULL, &check_life, data) != 0)
		exit(1);
	while (data->finish == 0)
	{
		take_forks(data);
		eat(data);
		sleeping(data);
		think(data);
	}
	return (NULL);
}

void	*check_life(void *life)
{
	t_data			*data;
	long long int	time;

	data = (t_data *)life;
	while (data->finish == 0)
	{
		one_philo(data);
		time = get_time_in_ms() - data->start_time;
		if (data->live_or_death - time <= 0)
		{
			sem_wait(data->death);
			data->finish = 1;
			printf("%lli %i died\n", time, data->id + 1);
			exit(0);
		}
		if (data->flag_end_of_eating == 1)
		{
			data->finish = 1;
			exit(0);
		}
	}
	return (NULL);
}