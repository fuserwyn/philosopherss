#include "../includes/philosophers_bonus.h"

void	take_forks(t_data *data )
{
	sem_wait(data->sem_forks);
	write_msg_bonus(get_time_in_ms() - data->start_time, data, FORK);
	write_msg_bonus(get_time_in_ms() - data->start_time, data, FORK);
}

void	eat(t_data *data)
{
	write_msg_bonus(get_time_in_ms() - data->start_time, data, EAT);
	u_sleep(data->t_eat);
	data->must_eat_qty += 1;
	if (data->must_eat_qty == data->times_eat + 1)
		data->flag_end_of_eating = 1;
	data->live_or_death = get_time_in_ms() - data->start_time + data->die;
	sem_post(data->sem_forks);
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