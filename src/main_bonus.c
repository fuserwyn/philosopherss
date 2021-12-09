#include "../philosophers_bonus.h"

void	ft_free(t_data *data)
{
	free(data);
}

int	free_ft(t_data *data)
{
	free(data);
	return (-1);
}

void	cast_printf(t_data *data, char *str, int index)
{
	long long int	time;

	if (data->must_eat_qty == data->times_eat)
		exit (1);
	sem_wait(data->death);
	time = get_time_in_ms_bonus(data);
	printf("%lli %i %s", time, index + 1, str);
	sem_post(data->deth);
}

void	life_bonus(t_data *data)
{
	int			index;
	pthread_t	live;

	if (pthread_create(&live, NULL, &check_life, data) != 0)
		exit(1);
	index = data->id;
	while (data->take_of != -1)
	{
		sem_wait(data->forks);
		cast_printf(data, "has taken a fork\n", index);
		cast_printf(data, "has taken a fork\n", index);
		cast_printf(data, "is eating\n", index);
		u_sleep(data->t_eat);
		data->must_eat_qty += 1;
		data->time_to_die_cont = get_time_in_ms_bonus(data) + data->death;
		sem_post(data->sem_forks);
		cast_printf(data, "is sleeping\n", index);
		u_sleep(data->t_sleep);
		cast_printf(data, "is thinking\n", index);
		data->status = 1;
	}
}

unsigned long	get_time_in_ms_bonus(t_data *data)
{
	struct timeval	time;

	time = data->start_time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*check_life(void *m)
{
	int				number_philo;
	t_data			*data;
	long long int	time;

	data = (t_data *)m;
	number_philo = data->ph_quantity;
	while (data->finish == 0)
	{
		time = get_time_in_ms_bonus(data);
		if (data->time_to_die_cont - time <= 0)
		{
			sem_wait(data->death);
			data->finish = 1;
			printf("%lli %i died\n", time, data->id + 1);
			exit(0);
		}
	}
	return (0);
}

int	write_msg_bonus(unsigned long int time, t_phil *ph, char *msg, t_data *data)
{
	if (data->times_eat == data->must_eat_qty)
		exit(1);
	sem_wait(data->death);
	printf("%6ld %2d %s", time, ph->id, msg);
	sem_post(data->death);
	return (1);
}

int	go_to_thead(t_data *data)
{
	int			i;
	int			var;

	data->pid = malloc(sizeof(int) * data->ph_quantity);
	if (data->pid == NULL)
		return (-1);
	i = 0;
	while (i < data->ph_quantity)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			data->id = i;
			life(data);
		}
		i++;
	}
	waitpid(-1, &var, 0);
	i = 0;
	if (var == 0)
	{
		while (i < data->ph_quantity)
			kill(data->pid[i++], SIGTERM);
	}
	return (free_ft(data));
}

void	*check_life(void *m)
{
	int				number_philo;
	t_data			*data;
	long long int	time;

	data = (t_data *)m;
	number_philo = data->num_phi;
	while (data->take_of != -1)
	{
		time = get_time_in_ms_bonus(data);
		if (data->time_to_die_cont - time <= 0)
		{
			sem_wait(data->death;
			data->take_of = -1;
			printf("%lli %i died\n", time, data->id + 1);
			exit(0);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		return (printf("wrong input\n"));
	input_args(&data, argc, argv);
	init_time(data);
	sem_unlink("forks");
	sem_unlink("deth");
	data.sem_forks = sem_open("forks", O_CREAT, S_IRWXU, (data->ph_quantity / 2));
	data.death = sem_open("deth", O_CREAT, S_IRWXU, 1);
	go_to_thead(data);
	sem_close(data.sem_forkss);
	sem_close(data.sem_forks);
	sem_close(data.death);
	sem_unlink("forks");
	sem_unlink("deth");
	return (0);
}

void	*check_life(void *m)
{
	int				number_philo;
	t_data			*data;
	long long int	time;

	data = (t_data *)m;
	number_philo = data->ph_quantity;
	while (data->take_of != -1)
	{
		time = ft_time_1(data);
		if (data->time_to_die_cont - time <= 0)
		{
			sem_wait(data->death);
			data->take_of = -1;
			printf("%lli %i died\n", time, data->id + 1);
			exit(0);
		}
	}
	return (0);
}
