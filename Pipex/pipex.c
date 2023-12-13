#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *str, char c);
char *ft_strchr(const char *s, int c);

int main(int ac, char *av[], char **env)
{
    pid_t pid;
    int status;
    char **path;
    int i;
    char *temp;

    i = 0;
    path = ft_split((ft_strchr(env[14], '=') + 1), ':');
    pid = fork();
    if (pid < 0)
    {
        perror ("Fork!");
        exit (1);
    }
    else if (pid == 0)
    {
        while (path[i])
        {
            temp = ft_strjoin(ft_strjoin(path[i], "/"), av[1]);
		printf("%s\n", temp);
		if (execve(temp, NULL, 0) == -1)
                	i++;
	}
            perror("Command!");
            exit(1);
    }
    else 
        waitpid(pid, &status, 0);
}
