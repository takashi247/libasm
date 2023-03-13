/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:38:56 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/14 00:00:38 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int
	main(void)
{
	run_strlen_tests();
	run_strcpy_tests();
	run_strcmp_tests();
	run_write_tests();
	run_read_tests();
	run_strdup_tests();
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
