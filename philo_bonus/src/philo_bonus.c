/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:52:26 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/12/10 19:52:27 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		return (write(1, "wrong input\n", 13));
	input_args(&data, argc, argv);
	init_time(&data);
	init_forks(&data);
	init_philo(&data);
	sem_closer(&data);
	read(0, NULL, 1);
	return (0);
}
