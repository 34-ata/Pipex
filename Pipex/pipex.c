/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:26:49 by faata             #+#    #+#             */
/*   Updated: 2023/12/19 12:27:07 by faata            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*take_path(char **env, char *set)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], set, 5) != 0)
		i++;
	if (env[i])
		return (&env[i][5]);
	return (0);
}

void	ft_error(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void	son_process(t_pipe	*def, char *av[], char **env)
{
	def->flags = ft_split(av[2], ' ');
	close (def->fd[0]);
	def->input = open(av[1], O_RDONLY, 0644);
	if (def->input == -1)
		ft_error("Input File!");
	dup2(def->fd[1], 1);
	close (def->fd[1]);
	dup2(def->input, 0);
	close (def->input);
	while (def->path[def->i])
	{
		def->temp2 = ft_strjoin(def->path[def->i], "/");
		def->temp = ft_strjoin(def->temp2, def->flags[0]);
		free(def->temp2);
		if (!access(def->temp, F_OK))
			execve(def->temp, def->flags, env);
		free(def->temp);
		def->i++;
	}
	ft_error("Child Command!");
}

void	father_process(t_pipe	*def, char *av[], char **env)
{
	waitpid(def->pid, &def->status, 0);
	def->flags = ft_split(av[3], ' ');
	def->i = 0;
	def->output = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (def->output == -1)
		ft_error("Output File!");
	close (def->fd[1]);
	dup2 (def->fd[0], 0);
	close (def->fd[0]);
	dup2 (def->output, 1);
	while (def->path[def->i])
	{
		def->temp2 = ft_strjoin(def->path[def->i], "/");	
		def->temp = ft_strjoin(def->temp2, def->flags[0]);
		free(def->temp2);
		if (!access(def->temp, F_OK))
			execve(def->temp, def->flags, env);
		free(def->temp);
		def->i++;
	}
	ft_error("Output File!");
}

int	main(int ac, char *av[], char **env)
{
	t_pipe	def;

	def.i = 0;
	if (ac != 5)
		ft_error("Invalid argument count");
	def.path = ft_split(take_path(env, "PATH="), ':');
	if (!def.path)
		ft_error("Can't find path");
	pipe(def.fd);
	def.pid = fork();
	if (def.pid < 0)
		ft_error("Fork!");
	else if (def.pid == 0)
		son_process(&def, av, env);
	else
		father_process(&def, av, env);
	return (0);
}
