/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:15:55 by agautier          #+#    #+#             */
/*   Updated: 2021/12/09 13:17:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	switch (std::rand() % 3) {
	case 0:
		std::cout << "class a" << std::endl;
		return (new A);
	case 1:
		std::cout << "class b" << std::endl;
		return (new B);
	case 2:
		std::cout << "class c" << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Is class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Is class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Is class C" << std::endl;
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Is class A" << std::endl;
		return;
	} catch (std::exception const& e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Is class B" << std::endl;
		return;
	} catch (std::exception const& e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Is class C" << std::endl;
		return;
	} catch (std::exception const& e) {}
}

int main(void) {
	std::srand(std::time(NULL));
	Base* base = generate();
	if (!base)
		return 1;
	identify(base);
	identify(*base);
	return (0);
}
