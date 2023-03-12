/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:01:40 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/12 14:32:22 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

/* color codes for printf */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define DEFAULT "\033[0m"

# include <stdlib.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);

#endif
