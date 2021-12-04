#include "../includes/philosophers.h"

int	write_msg(unsigned long int time, t_phil *ph, char *msg)
{
	pthread_mutex_lock(&ph->data->print);
	printf("%6ld %2d %s", time, ph->id, msg);
	if (ph->data->finish != 1)
		pthread_mutex_unlock(&ph->data->print);
	return (1);
}

void	u_sleep(int current_time)
{
	unsigned long int	go_sleep;

	go_sleep = get_time_in_ms();
	while (get_time_in_ms() < go_sleep + current_time)
		usleep(50);
}

unsigned long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long long	atoii(const char *str)
{
	long long	res;
	int			i;
	int			sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}