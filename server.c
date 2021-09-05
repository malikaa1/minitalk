#include "minitalk.h"


void handler(int sig, siginfo_t *siginfo, void *context)
{
    static char c;
    static size_t size;

    if (sig == SIGUSR2)
    {
        //ft_putstr("1");
        c += (1 << size);
        size++;
    }
    else if (sig == SIGUSR1)
    {
        //ft_putstr("0");
        c += (0 << size);
        size++;
    }

    if (size == 8)
    {
        //ft_putnbr(siginfo->si_pid);
        //ft_putstr("\n");
        ft_putchar(c);
        if (!c)
            ft_putstr("error");
        size = 0;
        c = 0;
    }
    else if (size > 8)
    {
        ft_putstr("error exiting ...");
        exit(EXIT_FAILURE);
    }

    // if (sig == SIGUSR1)
    //     kill(siginfo->si_pid, SIGUSR2);
    // if (sig == SIGUSR2)
    kill(siginfo->si_pid, SIGUSR2);
}

int main()
{
    pid_t pid;
    struct sigaction action;

    //sig_info.c = 0;
    //sig_info.size = 0;
    pid = getpid();
    ft_putnbr(pid);
    ft_putchar('\n');

    action.sa_sigaction = *handler;
    action.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &action, NULL) != 0)
    {
        ft_putstr("error signal");
    }

    if (sigaction(SIGUSR2, &action, NULL) != 0)
    {
        ft_putstr("error signal");
    }

    while (1)
    {
        //sigaction action;
        //signal(SIGUSR2, handler);
        //signal(SIGUSR1, handler);
        pause();
    }
}

// a
