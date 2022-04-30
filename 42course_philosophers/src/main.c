/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:09:01 by snovaes           #+#    #+#             */
/*   Updated: 2022/04/27 15:30:09 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	join_and_free_philos(t_info *info);
static void	create_philos(t_info *info);

int	main(int argc, char *argv[])
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	//chama memset pra zerar os dados da struct
	if (argc != 5 && != 6)
	//se o número de argumentos for diferente de 5 e diferente de 6
		return (ft_puterror("ERROR: you should specify at least\
num of philo, time to die, time to eat, time to sleep\n"));
	if (init(&info, argc, argv))
	//se a init return true
		return (1);
		//retorna erro
	create_philos(&info);
	//cria os philos
	join_and_free_philos(&info);
	//espera as trheads acabarem e libera a struct
	return (0);
}

static void	create_philos(t_info *info)
{
	int			i;
	pthread_t	th_id;

	gettimeofday(&info->create_at, NULL);
	//pega a hora atual;
	i = 0;
	//i recebe 0
	while (i < info->num_of_philo)
	//enquanto i for menor que o número de philos
	{
		info->philos[i].last_time_to_eat = info->create_at;
		//last_time_to_eat recebe a hora que foi criado
		pthread_create(&info->philos[i].th_id, NULL, philo, &info->philos[i]);
		//cria uma thread para o filósofo
		pthread_create(&th_id, NULL, monitor, &info->philos[i]);
		//cria uma thread para o monitor
		pthread_detach(th_id);
		//desanexa a thread
		++i;
		//incrementa o i
	}
	if (info->num_of_must_eat != 0)
	// se o número de vezes que precisa comer for diferente de 0
	{
		pthread_create(&th_id, NULL, monitor_each_must_eat, info);
		//cria uma thread para o monitor_each_must_eat
		pthread_detach(th_id);
		//desanexa a thread
	}
}

static void	join_and_free_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	//enquanto i for menor que o numero de philos
	{
		pthread_join(info->philos[i].th_id, NULL);
		//espera a thread atual terminar
		pthread_mutex_destroy(&info->philos[i++].check_lock);
		//destrói o mutex
	}
	free(info->philos);
	//libera memória de philos
	i = 0;
	while (i < info->num_of_philo)
	//enquanto i for menor que o numero de philos
		pthread_mutex_destroy(&info->forks[i++]);
		//destrói os garfos
	free(info->forks);
	//libera os garfos
}
