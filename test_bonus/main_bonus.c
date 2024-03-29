/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:38:56 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/18 18:40:17 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

int
	main(void)
{
	run_strchr_tests();
	run_atoi_base_tests();
	run_list_push_front_tests();
	run_list_size_tests();
	run_list_sort_tests();
	run_list_remove_if_tests();
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
