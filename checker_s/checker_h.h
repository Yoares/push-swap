/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_h.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:40:09 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/05 21:47:48 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*_strjoin(char *s1, char *s2);
void	*_calloc(size_t count, size_t size);
size_t	_strlen(char *s1);
char	*_strchr(const char *s, int c);
void	*_memcpy(void *dst, const void *src, size_t n);
#endif