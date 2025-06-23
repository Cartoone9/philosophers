/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:24:52 by *******           #+#    #+#             */
/*   Updated: 2025/05/20 00:43:16 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# define BOLD  "\033[1m"
# define RESET "\033[0m"
# define RED "\033[1;38;2;233;0;36m"
# define ORANGE "\033[1;38;2;255;129;0m"
# define YELLOW "\033[1;38;2;255;200;50m"
# define GREEN "\033[1;38;2;75;205;82m"
# define TEAL "\033[1;38;2;0;180;210m"
# define BLUE "\033[1;38;2;0;117;226m"
# define PURPLE "\033[1;38;2;108;86;249m"
# define MAGENTA "\033[1;38;2;181;51;251m"
# define VIOLET "\033[1;38;2;204;102;255m"
# define GREY  "\033[1;38;2;128;128;128m"

# define ERROR -1
# define OK 0

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_spoon
{
	t_mtx		lock;
}				t_spoon;

typedef struct s_philo
{
	pthread_t	thread_id;
	int			philo_id;
	int			n_meal;
	t_mtx		n_meal_lock;
	long long	t_last_meal;
	t_mtx		last_meal_lock;
	bool		finished;
	t_mtx		finished_lock;
	t_spoon		*left_spoon;
	t_spoon		*right_spoon;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	t_mtx		print_lock;
	long long	n_philo;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	long long	max_meal;
	long long	start_time;
	bool		threads_rdy;
	t_mtx		start_lock;
	bool		end;
	t_mtx		end_lock;
	t_philo		*philo_list;
	t_spoon		*spoon_list;
}				t_table;

// ----------------------- MAIN -----------------------

int			ft_start_diner(t_table *table);
int			ft_table_end_check(t_table *table);

/* THREADS */
int			ft_create_threads(t_table *table);
int			ft_wait_all_threads(t_table *table);
int			ft_eat(t_philo *philo);
int			ft_try_acquire_left_spoon(t_philo *philo, bool even);
int			ft_try_acquire_right_spoon(t_philo *philo, bool even);
int			ft_actions_while_holding_spoons(t_philo *philo);
int			ft_think(t_philo *philo);
int			ft_sleep(t_philo *philo);
bool		ft_philo_end_check(t_philo *philo);

/* MONITOR */
int			ft_create_monitor(t_table *table);
int			ft_monitor_max_meal(t_table *table);
int			ft_set_simulation_end(t_table *table);

// ----------------------- MAIN -----------------------
//
//
//
// ----------------------- LIBFT -----------------------

int			ft_strlen(const char *str);
int			ft_strrlen(const char **strr);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_four(const char *s1, const char *s2,
				const char *s3, const char *s4);
char		*ft_strjoin_print(const char *s1, const char *s2,
				const char *s3);
char		*ft_strjoin_time(const char *time);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_itoa(long long n);

// ----------------------- LIBFT -----------------------
//
//
//
// ----------------------- PARSING -----------------------

int			ft_check_n_fill_table(char **av, t_table *table);
int			ft_fill_n_philo(char *source, t_table *table);
int			ft_fill_t_die(char *source, t_table *table);
int			ft_fill_t_eat(char *source, t_table *table);
int			ft_fill_t_sleep(char *source, t_table *table);
int			ft_fill_max_meal(char *source, t_table *table);
int			ft_fill_philo_n_fork(t_table *table);
int			ft_make_spoon(t_table *table);
int			ft_make_philo(t_table *table);

// ----------------------- PARSING -----------------------
//
//
//
// ----------------------- UTILS -----------------------

/* ID */
bool		ft_has_only_pdigit(char *str);
bool		ft_is_empty_str(char *str);
bool		ft_is_space(int c);
bool		ft_is_digit(int c);
bool		ft_is_alpha(int c);
bool		ft_is_alphanum(int c);

/* ATOLL */
int			ft_atoll_safe(char *str, long long *ret);
int			ft_atoll_safe_handle_sign(char *str, long long *neg,
				long long *last_digit, size_t *i);
int			ft_atoll_safe_parse_digits(char *str, unsigned long long *temp,
				long long last_digit, size_t *i);

/* TIME */
long long	ft_gettime_ms(void);
long long	ft_gettime_us(void);
int			ft_usleep_improved(long long wait_time, t_table *table);
int			ft_busy_wait(long long wait_time, long long t_start_us,
				t_table *table);

/* UI */
void		ft_print_banner(void);

/* PRINTER */
int			ft_print_status(t_philo *philo, char *msg);

/* TESTER */
int			ft_tester_table(t_table *table);

// ----------------------- UTILS -----------------------
//
//
//
// ----------------------- ERRORS -----------------------

void		ft_error(char *error_msg);
void		ft_error_min(char *error_msg);
void		ft_error_arg(void);
void		ft_error_source(char *source, char *error_msg);
int			ft_error_mtx_init(int err_code);
int			ft_error_mtx_destroy(int err_code);
int			ft_error_mtx_lock(int err_code);
int			ft_error_mtx_unlock(int err_code);
int			ft_error_thread_crt(int err_code);
int			ft_error_thread_dtch(int err_code);
int			ft_error_thread_join(int err_code);

// ----------------------- ERRORS -----------------------
//
//
//
// ----------------------- FREE -----------------------

void		ft_free_str(char **str);
void		ft_free_strr(char ***strr);

// ----------------------- FREE -----------------------
//
//
//
// ----------------------- EXIT -----------------------

void		ft_clean_table(t_table *table);

/* UTILS */
int			ft_exit_busy_wait(t_table *table);
void		ft_exit_destroy_table_mtx_print(t_table *table);
void		ft_exit_destroy_table_mtx_start(t_table *table);
void		ft_exit_destroy_table_mtx_end(t_table *table);
void		ft_exit_destroy_philo_mtx(t_table *table, size_t i);

// ----------------------- EXIT -----------------------

#endif
