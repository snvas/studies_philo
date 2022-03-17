/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:51:35 by snovaes           #+#    #+#             */
/*   Updated: 2022/03/16 22:00:57 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int x = 0;
pthread_mutex_t mutex;

void* routine(){
	for (int i = 0; i < 1000000; i++){
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	};
//	printf("Hello from thread! Process id %d\n", getpid());
//	printf("Value of x: %d\n", x);
//	sleep(3);
//	printf("Goodbye from thread!\n");
}

int main(int argc, char *argv[])
{
	pthread_t th[8];
	int i;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 8; i++) 
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
		{
			perror("failed to create thread");
			return 1;
		}
		printf("Thread just start! Process id %d\n", getpid());	
	}
	for(i = 0; i < 8; i++) 
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			return 2;
		}
		printf("Thread %d finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of emails: %d\n", x);
	return (0);
}
