/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:36:31 by snovaes           #+#    #+#             */
/*   Updated: 2022/03/18 13:39:26 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

int main(){
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	printf("Seconds: %ld\nmicrosecond: %ld\n", current_time.tv_sec, current_time.tv_usec);
}