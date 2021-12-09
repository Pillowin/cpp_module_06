/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:33:05 by agautier          #+#    #+#             */
/*   Updated: 2021/12/09 13:14:55 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }

int main(void) {
	Data data('1', "coucou", 2, 3.0f, 4.0);

	std::cout << data << std::endl;
	std::cout << "serialize return = " << serialize(&data) << std::endl
			  << std::endl;
	std::cout << *deserialize(serialize(&data));

	return 0;
}
