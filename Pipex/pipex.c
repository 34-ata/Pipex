#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
            if (execve(temp, NULL, 0) == -1)
                i++;
            perror("Command!");
            exit(1);
        }
    }
    else 
        waitpid(pid, &status, 0);
}