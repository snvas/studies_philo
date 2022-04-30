/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:27:15 by snovaes           #+#    #+#             */
/*   Updated: 2022/04/29 21:21:45 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	parsing_arg(t_info *info, int argc, char *argv[]);
static int	check_info(t_info *info, int argc);
static int	init_philos(t_info *info);

int	init(t_info *info, int argc, char *argv[])
{
	parsing_arg(info, argc, argv);
	//chama a parsing_arg
	if (check_info(info, argc))
	//se a check_info for NULL
		return (1);
	if (init_philos(info))
	//se init_philos for NULL
		return (1);
	return (0);
}

static void	parsing_arg(t_info *info, int argc, char *argv[])
{
	info->num_of_philo = ft_atoi(argv[1]);
	//num_of_philo recebe o argv[1] convertido em número
	info->time_to_die = ft_atoi(argv[2]);
	//time_to_die recebe o argv[2] convertido em número
	info->time_to_eat = ft_atoi(argv[3]);
	//time_to_eat recebe o argv[3] convertido em número
	info->time_to_sleep = ft_atoi(argv[4]);
	//time_to_sleep recebe o argv[4] convertido em número
	if (argc == 6)
	//se o número de argumentos for igual a 6
		info->num_of_must_eat = ft_atoi(argv[5]);
		//num_of_must_eat recebe o argv[5] convertido em número
}

static int	check_info(t_info *info, int argc)
{
	if (argc == 6 && info->num_of_must_eat <= 0)
	//se o numero de argumentos for igual a 6 e num_of_must_eat for menor ou igual a 0
		return (ft_puterror("ERROR: num of must eat must be > 0\n"));
		//retorna mensagem
	if (info->num_of_philo < 0)
	//se o num_of_philo for menor que 0
		return (ft_puterror("ERROR: num of philo must be > 0\n"));
	if (info->time_to_die < 0)
	//se o time_to_die for menor que 0
		return (ft_puterror("ERROR: time to die must be > 0\n"));
	if (info->time_to_eat < 0)
	//se o time_to_eat for menor que 0
		return (ft_puterror("ERROR: time to eat must be > 0\n"));
	if (info->time_to_sleep < 0)
	//se o time_to_sleep for menor que 0
		return (ft_puterror("ERROR: time to sleep must be > 0\n"));
	return (0);
}

static int	init_philos(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->finish_mutex, NULL);
	//function initialize the mutex referenced
	if (ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo) || \
		ft_malloc(&info->forks, sizeof(pthread_mutex_t) * info->num_of_philo))
	//se a alocação de memória dos philos e dos garfos não funcionar
		return (ft_puterror("ERROR: malloc failed\n"));
		//retorna erro
	while (i < info->num_of_philo)
	//enquanto i for menor que o n de philos	
	{
		info->philos[i].n = i;
		//n recebe i
		pthread_mutex_init(&info->forks[i], NULL);
		//inicializa os garfos
		pthread_mutex_init(&info->philos[i].check_lock, NULL);
		//inicializa o check_lock
		if (i == 0)
		//se i igual a 0
			info->philos[i].left_fork = &info->forks[info->num_of_philo - 1];
			//left_fork recebe endereço de fork na posição num_of_philo - último garfo
		else
			info->philos[i].left_fork = &info->forks[i - 1];
			//left_fork recebe endereço de fork na posição i - 1
		info->philos[i].right_fork = &info->forks[i];
		//right_fork recebe endereço de fork na posição i
		info->philos[i].info = info;
		//philos[i] info receb info
		++i;
		//incrementa o i
	}
	return (0);
}
