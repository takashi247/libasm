/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnishina <tnishina@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:38:56 by tnishina          #+#    #+#             */
/*   Updated: 2023/03/14 18:39:34 by tnishina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

int
	main(void)
{
	run_atoi_base_tests();
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
