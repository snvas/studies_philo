/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:36:14 by snovaes           #+#    #+#             */
/*   Updated: 2022/04/28 19:10:35 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	pickup_fork(t_philo *philo);
static void	eat(t_philo *philo);
static void	sleeping(t_philo *philo);
static void	think(t_philo *philo);

void	*philo(void *argv)
{
	t_philo	*philo;

	philo = argv;
	//philo recebe argv
	if (philo->n % 2 == 0)
	//se módulo 2 de n philos for igual a zero
		usleep(philo->info->time_to_eat * 1000);
		//suspends execution of the calling thread for (at least) usec microseconds
	while (!has_finished(philo->info))
	//enquanto has finished não for verdadeiro
	{
		if (pickup_fork(philo))
		//se pegar o garfo não funcionar
		{
			usleep(philo->info->time_to_die * 1000);
			//espera o tempo para morrer vezes 1 segundo 
			return NULL;
			//retorna NULL
		}
		eat(philo);
		//come
		sleeping(philo);
		//dorme
		think(philo);
		//pensa
	}
	return (NULL);
}

static int	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	//trava o garfo right_fork 
	print_philo_msg(philo, "has taken a fork to the right");
	//imprime mensagem
	if (philo->left_fork == philo->right_fork)
	// se o left_fork for igual ao right_fork
	{
		pthread_mutex_unlock(philo->right_fork);
		//desbloqueia o right_fork
		return (1);
		//retorna 1
	}
	pthread_mutex_lock(philo->left_fork);
	//locked left_fork
	print_philo_msg(philo, "has taken a fork to the left");
	//imprime mensagem
	return (0);
	//retorna 0
}

static void	eat(t_philo *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->check_lock);
	//lock check_lock
	gettimeofday(&philo->last_time_to_eat, NULL);
	//pega a hora do last_time_to_eat
	ms = time_to_ms(philo->last_time_to_eat) - \
		time_to_ms(philo->info->create_at);
	//ms recebe o tempo que passou desde o início do programa
	pthread_mutex_lock(&philo->info->finish_mutex);
	//lock finish_mutex
	if (!philo->info->finish)
	//se finish for diferente de NULL
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, "is eating");
		//imprime mensagem
	philo->num_of_eat += 1;
	//incrementa o num_of_eat
	if (philo->num_of_eat == philo->info->num_of_must_eat)
	//se o num_of_eat for igual ao num_of_must_eat
		philo->info->num_of_philo_finished_eat += 1;
		//incrementa o número de philos que terminou de comer
	pthread_mutex_unlock(&philo->info->finish_mutex);
	//desbloqueia finish_mutex
	usleep(philo->info->time_to_eat * 1000);
	//suspends time_to_eat vezes 1 segundo
	pthread_mutex_unlock(philo->right_fork);
	//desbloqueia right_fork
	pthread_mutex_unlock(philo->left_fork);
	//desbloqueia left_fork
	pthread_mutex_unlock(&philo->check_lock);
	//desbloqueia check_lock
}

static void	sleeping(t_philo *philo)
{
	print_philo_msg(philo, "is sleeping");
	//imprime mensagem
	usleep(philo->info->time_to_sleep * 1000);
	//suspends time_to_sleep vezes 1 segundo
}

static void	think(t_philo *philo)
{
	print_philo_msg(philo, "is thinking");
	//imprime mensagem
}
