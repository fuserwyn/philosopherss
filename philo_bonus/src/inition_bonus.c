#include "../includes/philosophers_bonus.h"

void	input_args(t_data *data, int argc, char **argv)
{
	data->ph_quantity = (unsigned int) atoii(argv[1]);
	data->die = (unsigned int) atoii(argv[2]);
	data->t_eat = (unsigned int) atoii(argv[3]);
	data->t_sleep = (unsigned int) atoii(argv[4]);
	data->finish = 0;
	data->flag_end_of_eating = 0;
	data->id = 0;
	data->start_time = 0;
	data->must_eat_qty = 0;
	data->live_or_death = data->die;
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

void	init_time(t_data *data)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	data->start_time = (current_time.tv_sec) * 1000 \
	+ (current_time.tv_usec) / 1000;
}


void init_forks(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("death");
	data->sem_forks = sem_open("forks", O_CREAT, S_IRWXU, (data->ph_quantity / 2));
	data->death = sem_open("death", O_CREAT, S_IRWXU, 1);
}

void	init_philo(t_data *data)
{
	unsigned int			i;
	int						var;

	data->pid = malloc(sizeof(int) * data->ph_quantity);
//	if (data->pid == NULL)
//		return (-1);
	i = 0;
	while (i < data->ph_quantity)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			data->id = i + 1;
			philo_actions(data);
		}
		i++;
	}
	waitpid(-1, &var, 0);
	i = 1;
	if (var == 0)
	{
		while (i < data->ph_quantity)
			kill(data->pid[i++], SIGTERM);
	}
//	return (free_ft(data));
}