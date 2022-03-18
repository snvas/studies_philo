/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formattime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:40:27 by snovaes           #+#    #+#             */
/*   Updated: 2022/03/18 13:47:07 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(){
	struct timeval tv;
	time_t t;
	struct tm *info;
	char buffer[64];


	gettimeofday(&tv, NULL);
	t = tv.tv_sec;
	info = localtime(&t);
	printf("%s", asctime(info));
	strftime(buffer, sizeof(buffer), "Today is %A %B %d.\n", info);
	printf("%s", buffer);
	strftime(buffer, sizeof(buffer), "The time is %I:%M %p.\n", info);
	printf("%s", buffer);
}
