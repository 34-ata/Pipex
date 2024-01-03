/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:28:49 by faata             #+#    #+#             */
/*   Updated: 2023/12/19 15:48:11 by faata            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipe
{
	pid_t	pid;
	int		status;
	char	**path;
	int		i;
	char	*temp;
	char	*temp2;
	int		fd[2];
	int		input;
	int		output;
	char	**flags;
}	t_pipe;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *str, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char	*s);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t sz);
char	*ft_strdup(const char	*src);
#endif
