#include "../includes/philosophers.h"

void take_forks(t_phil *ph)
{
		pthread_mutex_lock(ph->l_fork);
		write_msg(get_time_in_ms() - ph->data->start_time, ph, FORK);
		pthread_mutex_lock(ph->r_fork);
		write_msg(get_time_in_ms() - ph->data->start_time, ph, FORK);
}

void	put_forks(t_phil *ph)
{
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
}

void	eat(t_phil *ph)
{
	unsigned long int	time;

	take_forks(ph);
	time = get_time_in_ms() - ph->data->start_time ;
	ph->ph_die = ph->data->die;
	if (write_msg(time, ph, EAT) == 1)
	{
		ph->ph_times_eat += 1;
		if (ph->ph_times_eat == ph->data->times_eat + 1)
			ph->flag_end_of_eating += 1;
		u_sleep(ph->data->t_eat);
		put_forks(ph);
	}
}

void	sleeping(t_phil *ph)
{
	unsigned long int   time;
	time = (get_time_in_ms() - ph->data->start_time);
	write_msg(time, ph, SLEEP);
	u_sleep(ph->data->t_sleep);
}

void	think(t_phil *ph)
{
	unsigned long int	time;

	time = (get_time_in_ms() - ph->data->start_time );
	write_msg(time, ph, THINK);
}
