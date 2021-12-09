#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <pthread.h>
# include "philosophers_bonus.h"
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
	unsigned int	t_sleep;
	unsigned int	t_eat;
	unsigned long	start_time;
	int				times_eat;
	int				must_eat_qty;
	int				live_or_death;
	int				finish;
	int 			id;
	int 			*pid;
	int 			flag_end_of_eating;
    pthread_t		*ph;
	sem_t			*sem_forks;
	sem_t			*death;
	sem_t			*meals;

}				t_data;

void			ft_free(t_data *data);
void			cast_printf(t_data *data, char *str, int index);
void			*philo_actions(t_data *data);
unsigned long	get_time_in_ms(void);
void			*check_life(void *m);
int				write_msg_bonus(unsigned long int time, t_data *data, char *msg);
void			init_philo(t_data *data);
void			*check_life(void *m);
void			u_sleep(int current_time);
void	        input_args(t_data *data, int argc, char **argv);
void			init_time(t_data *data);
int				check_input(int argc, char **argv);
int				is_digit(char *str);
int				ft_len(const char *str);
int				isdigit(int c);
long long		atoii(const char *str);
int				free_ft(t_data *data);
void			take_forks(t_data *data);
void			eat(t_data *data);
void			sleeping(t_data *data);
void			think(t_data *data);
void			init_forks(t_data *data);
void			sem_closer(t_data *data);

#endif