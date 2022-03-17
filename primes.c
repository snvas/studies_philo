/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:09:55 by snovaes           #+#    #+#             */
/*   Updated: 2022/03/17 12:19:03 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void * arg){
	int index = *(int *)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int main(int argc, char *argv[])
{
	pthread_t th[10];
	int i;
	for (i = 0; i < 10; i++){
		int* a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			perror("failed to create thread");
		}
	}
	for (i = 0; i < 10; i++){
		if (pthread_join(th[i], NULL) != 0)
		{
			perror("failed to join thread");
		}
	}
	return (0);
}