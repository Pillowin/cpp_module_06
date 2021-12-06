/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:50:16 by agautier          #+#    #+#             */
/*   Updated: 2021/12/06 19:52:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Bad number of arguments." << std::endl
				  << "Usage ./convert \"literal_value\"" << std::endl;
		return (EXIT_FAILURE);
	}

	Convert convert(argv[1]);
	convert.print();

	return (EXIT_SUCCESS);
}

