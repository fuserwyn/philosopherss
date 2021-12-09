#include "philosophers_bonus.h"

#ifndef PHIL_BONUS_H
# define PHIL_BONUS_H
# include <pthread.h>
# include "philosophers.h"
# include <sys/time.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>
# define SUCCESS 0
# define FAIL 1
# define ERROR -1
# define FORK   "\033[33m has taken a fork\033[0m\n"
# define EAT    "\033[32m is eating\033[0m\n"
# define SLEEP  "\033[35m is sleeping\033[0m\n"
# define THINK  "\033[36m is thinking\033[0m\n"
# define DIE    "\033[31m died\033[0m\n"
# define ONE	"\033[33m has taken a fork\033[0m\n"

typedef struct s_data
{
	unsigned int	ph_quantity;
	unsigned int	die;
	long long int	time_to_die_cont;
	unsigned int	t_sleep;
	unsigned int	t_eat;
	unsigned long	start_time;
	int				times_eat;
	int				must_eat_qty;
	int				live_or_death;
	int				finish;
	int 			id;
    pthread_t		*ph;
	sem_t			*sem_forks;
	sem_t			*death;
	sem_t			*meals;
    t_phil			*ph_struct;
}				t_data