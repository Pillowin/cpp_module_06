/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:33:00 by agautier          #+#    #+#             */
/*   Updated: 2021/12/09 13:14:37 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(char c, std::string s, int i, float f, double d) :
	c(c),
	s(s),
	i(i),
	f(f),
	d(d) {}

Data::Data(Data const& src) { *this = src; }

Data::~Data(void) {}

Data& Data::operator=(Data const& rhs) {
	if (this == &rhs)
		return (*this);
	c = rhs.c;
	s = rhs.s;
	i = rhs.i;
	f = rhs.f;
	d = rhs.d;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Data const& rhs) {
	os << "Addr: " << &rhs << std::endl;
	os << rhs.c << " - " << rhs.s << " - " << rhs.i << " - " << rhs.f << " - "
	   << rhs.d << std::endl;
	return os;
}

