/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:58:50 by kahirose          #+#    #+#             */
/*   Updated: 2022/02/13 14:40:43 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<unistd.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

int		eol_sensor(char *str);
size_t	gnl_strlen(const char *str, int mode);
char	*ft_strcat(char *dest, char *src);
char	*gnl_strjoin(char *s1, char *s2, bool *is_success);
char	*get_next_line(int fd, bool *is_success);
void	*error_clean(char *s1, char *s2, bool *is_success);

#endif
