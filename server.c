#include "minitalk.h"

t_sig_info sig_info;

void handler(int sig)
{
    if (sig == SIGUSR2)
    {
        //ft_putstr("1");
        sig_info.c += (1 << sig_info.size);
        sig_info.size++;
    }
    else if (sig == SIGUSR1)
    {
        //ft_putstr("0");
        sig_info.c += (0 << sig_info.size);
        sig_info.size++;
    }

    if (sig_info.size == 8)
    {
        //ft_putstr("\n");
        ft_putchar(sig_info.c);
        if (!sig_info.c)
            ft_putstr("error");
        sig_info.size = 0;
        sig_info.c = 0;
    }
    else if (sig_info.size > 8)
    {
        ft_putstr("error exiting ...");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    pid_t pid;
    sigaction action;

    sig_info.c = 0;
    sig_info.size = 0;
    pid = getpid();
    ft_putnbr(pid);
    ft_putchar('\n');
    while (1)
    {
        //sigaction action;
        signal(SIGUSR2, handler);
        signal(SIGUSR1, handler);
        pause();
    }
}

// a
