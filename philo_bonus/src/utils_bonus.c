/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:52:17 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/12/10 19:52:37 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

unsigned long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	u_sleep(int current_time)
{
	unsigned long int	go_sleep;

	go_sleep = get_time_in_ms();
	while (get_time_in_ms() < go_sleep + current_time)
		usleep(50);
}

void	sem_closer(t_data *data)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_forks);
	sem_close(data->death);
	sem_unlink("forks");
	sem_unlink("death");
}

int	write_msg_bonus(unsigned long int time, t_data *data, char *msg)
{
	sem_wait(data->death);
	printf("%6ld %2d %s", time, data->id, msg);
	if (msg == DIE)
		exit (0);
	sem_post(data->death);
	return (1);
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
