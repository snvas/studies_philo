/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rolldice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:51:35 by snovaes           #+#    #+#             */
/*   Updated: 2022/03/17 13:13:04 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * roll_dice() {
	int value;
	int *result;

	value = (rand() %6 + 1);
	result = malloc(sizeof(int));
	*result = value;
	printf("Thread result: %p\n", result);
//	printf("%d\n", value);
	return (result);
}

int main(int argc, char *argv[])
{
	int * result;
	pthread_t th;
	
	srand(time(NULL));
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		{
			perror("failed to create thread");
			return (1);
		}
		printf("Thread just start! Process id %d\n", getpid());	
		if (pthread_join(th, (void *) &result) != 0)
		{
			return (2);
		}
	printf("Main result: %p\n", result);
	printf("Result %d\n", *result);
	free(result);
	return (0);
}
