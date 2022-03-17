/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:51:35 by snovaes           #+#    #+#             */
/*   Updated: 2022/03/16 21:45:10 by snovaes          ###   ########.fr       */
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
	pthread_t t1, t2, t3, t4;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		printf("Error creating thread 1\n");
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		printf("Error creating thread 2\n");
	if (pthread_create(&t3, NULL, &routine, NULL) != 0)
		printf("Error creating thread 3\n");
	if (pthread_create(&t4, NULL, &routine, NULL) != 0)
		printf("Error creating thread 4\n");
	if (pthread_join(t1, NULL) != 0)
		printf("Error joining thread 1\n");
	if (pthread_join(t2, NULL) != 0)
		printf("Error joining thread 2\n");
	if (pthread_join(t3, NULL) != 0)
		printf("Error joining thread 3\n");
	if (pthread_join(t4, NULL) != 0)
		printf("Error joining thread 4\n");
	pthread_mutex_destroy(&mutex);
	printf("Number of emails: %d\n", x);
	return (0);
}
