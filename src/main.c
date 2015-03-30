/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 14:57:33 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/30 14:57:34 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

static void	ftl_error_usage(void)
{
	ft_error_str_exit("usage: push_swap [-cvmn] [int_value ...]\n");
}


int		main(int argc, char **argv)
{
	if (argc == 2)
	{

	}
	else
		ftl_error_usage();

	return (0);
}
