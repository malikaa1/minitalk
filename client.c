#include "minitalk.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int received = 1;

// void wait_for_ack()
// {
// 	while (received == 0);
// }

void send_msg(int pid, char *argv, size_t len)
{
	int bit;
	size_t i;
	char current_char;

	i = 0;
	while (i < len)
	{
		current_char = argv[i];
		bit = 0;
		while (bit <= 7)
		{
			if (((current_char >> bit) & 1) == 1)
			{
				//ft_putstr("1");
				//wait_for_ack();
				kill(pid, SIGUSR2);
				received = 0;
			}
			else
			{
				//ft_putstr("0");
				//wait_for_ack();
				kill(pid, SIGUSR1);
				received = 0;
			}
			bit++;
			//usleep(500);
		}
		//ft_putstr("\n");
		i++;
	}
}

//0 1 1 0 0 0 0 1
// 01100010

// void ack_handler(int sig)
// {
// 	if (sig == SIGUSR2)
// 	{
// 		received = 1;
// 	}
// }

int main(int argc, char **argv)
{
	int server_pid;
	if (argc == 3)
	{
		//signal(SIGUSR2, ack_handler);
		server_pid = ft_atoi(argv[1]);
		send_msg(server_pid, argv[2], ft_strlen(argv[2]));
		send_msg(server_pid, "\n", 1);
	}
	else
		ft_putstr("usage : ./clien <PID>  <message>\n");
	
	return 0;
}