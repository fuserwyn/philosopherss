/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:48:16 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/11/27 19:35:38 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include "philosophers.h"
# include <sys/time.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define SUCCESS 0
# define FAIL 1
# define ERROR -1
# define FORK   "\033[33m has taken a fork\033[0m\n"
# define EAT    "\033[32m is eating\033[0m\n"
# define SLEEP  "\033[35m is sleeping\033[0m\n"
# define THINK  "\033[36m is thinking\033[0m\n"
# define DIE    "\033[31m died\033[0m\n"

struct s_data;

typedef struct s_phil
{
	pthread_mutex_t		*l_fork;
	pthread_mutex_t   	*r_fork;
	int 				flag_end_of_eating;
    int                 id;
    int                 nnum_philo;
	pthread_mutex_t 	print;
    unsigned int	    ph_die;
    unsigned int	    ph_sleep;
    unsigned int	    ph_eat;
    unsigned long       ph_last_eat_time;
    unsigned long	    ph_start_time;
    int					ph_times_eat;
    struct s_data       *data;
	pthread_t			ph;
    unsigned long int   ph_end_eat;
}				t_phil;

typedef struct s_data
{
	unsigned int	ph_quantity;
	unsigned int	die;
	unsigned int	t_sleep;
	unsigned int	t_eat;
	unsigned long	start_time;
	int				times_eat;
	int				must_eat_qty;
	int				live_or_death;
	int				finish;
    pthread_mutex_t	print;
    pthread_t		*ph;
    pthread_mutex_t	*forks;
    t_phil			*ph_struct;
}				t_data;

int	            is_digit(char *str);
int	            ft_len(const char *str);
void	        input_args(t_data *data, int argc, char **argv);
void            init_philo(t_data *data);
void            init_philo_struct(t_data *data);
void            init_forks(t_data *data);
void            *philo_actions(void *arg);
int				thinking(t_phil *philosopher);
int				write_msg(unsigned long int time, \
				t_phil *phil, char *msg);
void			init_time(t_data *data);
unsigned long	get_time_in_ms(void);
void			u_sleep(int current_time);
void			take_forks(t_phil *ph);
int				min_fork(t_phil *ph);
int				max_fork(t_phil *ph);
void			eat(t_phil *ph);
void			sleeping(t_phil *ph);
void			think(t_phil *ph);
void 			*life(t_data *data);
void			time_to_wash_forks(t_data *data);
void			table_cleaner(t_data *data);
int				have_you_eaten_philo(t_data *data);
void 			*ft_end(t_data *data);
void 			put_forks(t_phil*data);
int				isdigit(int c);
long long		atoii(const char *str);

#endif