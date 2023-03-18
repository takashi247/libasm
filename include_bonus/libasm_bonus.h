/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:17 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/18 14:21:37 by tnishina         ###   ########.fr       */
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

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

/* mandatory part */

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);


/* bonus part */
int		ft_atoi_base(char *str, char *base);
char	*ft_strchr(const char *s, int c);
int		ft_strchr_index(const char *s, int c);
int		ft_isspace(int c);
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
// void	ft_list_sort(t_list **begin_list, int (*cmp)(const char *, const char *));
void	ft_list_sort(t_list **begin_list, int (*cmp)());

/* test functions */

void	run_strchr_tests(void);
void	run_atoi_base_tests(void);
void	run_list_push_front_tests(void);
void	run_list_size_tests(void);
void	run_list_sort_tests(void);

#endif
