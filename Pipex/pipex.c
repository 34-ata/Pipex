#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

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
	int fd[2];
	int input;
	int output;
	char **flags;

    i = 0;
    path = ft_split((ft_strchr(env[2], '=') + 1), ':');
	pipe(fd);
    pid = fork();
    if (pid < 0)
    {
        perror ("Fork!");
        exit (1);
    }
    else if (pid == 0)
    {
		flags = ft_split(av[2], ' ');
		close (fd[0]);
		input = open(av[1], O_RDONLY, 0644);
		if (input == -1)
		{
			perror("Input File!");
			exit(1);
		}	
		dup2(fd[1], 1);
		close (fd[1]);
		dup2(input, 0);
		close (input);
        while (path[i])
        {
            temp = ft_strjoin(ft_strjoin(path[i], "/"), flags[0]);
			if (execve(temp, flags, env) == -1)
                	i++;
		}
        perror("Command!");
        exit(1);
    }
    else
	{
        //waitpid(pid, &status, 0);
		flags = ft_split(av[3], ' ');
		i = 0;
		output = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output == -1)
		{
			perror ("Output File!");
			exit (1);
		}
		close (fd[1]);
		dup2 (fd[0], 0);
		close (fd[0]);
		dup2 (output, 1);
		while (path[i])
        {
            temp = ft_strjoin(ft_strjoin(path[i], "/"), flags[0]);
			if (execve(temp, flags, env) == -1)
                	i++;
		}
        perror("Command!");
        exit(1);
	}
}
