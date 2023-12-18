#include "pipex.h"

char *take_path(char **env, char *set)
{
	int i;

	i = 0;
	while (ft_strncmp(env[i], set, 5) != 0)
		i++;
	if (env[i])
		return (&env[i][5]);
	return (0);
}


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
	if (ac != 5)
	{
		perror("Invalid argument count");
		return (1);
	}
    path = ft_split(take_path(env, "PATH="), ':');
	if (!path)
	{
		perror("Can't find path");
		return (1);
	}
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
			if (!access(temp, F_OK))
				execve(temp, flags, env);
            i++;
		}
        perror("Command!");
        exit(1);
    }
    else
	{
        waitpid(pid, &status, 0);
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
