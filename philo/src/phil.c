/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:34:34 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/12/04 20:42:42 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' && ft_len(str) > 1)
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (i < argc)
	{
		if (ft_len(argv[i]) > 10 || !is_digit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	detach_philo(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->ph_quantity)
		pthread_detach(data->ph_struct[i++].ph);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		return (printf("wrong input\n"));
	input_args(&data, argc, argv);
	init_forks(&data);
	init_philo_struct(&data);
	init_time(&data);
	life(&data);
	detach_philo(&data);
	if (data.forks)
		free(data.forks);
	return (0);
}
