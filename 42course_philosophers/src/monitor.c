/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:21:34 by snovaes           #+#    #+#             */
/*   Updated: 2022/04/28 19:20:01 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*monitor_each_must_eat(void *argv)
{
	t_info	*info;

	info = argv;
	while (!has_finished(info))
	//enquanto has_finished não for NULL
	{
		pthread_mutex_lock(&info->finish_mutex);
		//lock finish_mutex
		if (info->num_of_philo_finished_eat == info->num_of_philo)
		//se num_of_eat_finish_philo for igual num_of_philo
			info->finish = 1;
			//finish recebe 1
		pthread_mutex_unlock(&info->finish_mutex);
		//desbloqueia finish_mutex
	}
	return (NULL);
}

void	*monitor(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		msec;

	philo = argv;
	while (!has_finished(philo->info))
	//enquanto has_finished não for NULL
	{
		pthread_mutex_lock(&philo->check_lock);
		//lock check_lock
		pthread_mutex_lock(&philo->info->finish_mutex);
		//lock finish_mutex
		gettimeofday(&now, NULL);
		//pega a hora atual
		msec = time_to_ms(now) - time_to_ms(philo->last_time_to_eat);
		//msec recebe o tempo desde a última hora que o filósofo comeu
		gettimeofday(&now, NULL);
		//pega a hora atual
		if (msec >= philo->info->time_to_die && philo->info->finish == 0)
		//se msec for menor ou igual ao tempo pra morrer e finish for 0
		{
			printf("%lld\t%d\t %s\n", \
				time_to_ms(now) - time_to_ms(philo->info->create_at), \
				philo->n + 1, " died");
				//imprime mensagem
			philo->info->finish = 1;
			//finish recebe 1
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		//desbloqueia finish_mutex
		pthread_mutex_unlock(&philo->check_lock);
		//desbloqueia check_lock
	}
	return (NULL);
}
