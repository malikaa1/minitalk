#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

// char	*ft_itoa(int nb);
int ft_atoi(const char *str);
size_t ft_strlen(const char *s);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char *str);
void handler(int sig, siginfo_t *siginfo, void *context);
void send_msg(int pid, char *argv, size_t len);

#endif