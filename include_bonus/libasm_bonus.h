/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:17 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/14 18:14:36 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

/* color codes for printf */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

/* mandatory part */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

/* bonus part */
int		ft_atoi_base(char *str, char *base);

/* test functions */

void	run_atoi_base_tests(void);

#endif
