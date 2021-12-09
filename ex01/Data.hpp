/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:32:54 by agautier          #+#    #+#             */
/*   Updated: 2021/12/09 12:33:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <ostream>
#include <string>

class Data {
	public:
		char c;
		std::string s;
		int i;
		float f;
		double d;

		Data(char c		   = '0',
			 std::string s = "default",
			 int i		   = 0,
			 float f	   = 0.0f,
			 double d	   = 0.0);
		Data(Data const& src);

		~Data();

		Data& operator=(Data const& rhs);
};

std::ostream& operator<<(std::ostream& os, Data const& rhs);

#endif
