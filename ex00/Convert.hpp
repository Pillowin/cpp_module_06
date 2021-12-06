/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:16:07 by agautier          #+#    #+#             */
/*   Updated: 2021/12/06 19:56:13 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#define NB_CONV 4

class Convert {
	public:
		Convert(Convert const& src);
		Convert(std::string const& literal_value);

		~Convert(void);

		void print(void);

		Convert& operator=(Convert const& rhs);

	private:
		std::string literal_value;
		int i;
		char c;
		float f;
		double d;
		bool literal_error;

		Convert(void);

		bool isChar(void);
		bool isInt(void);
		bool isFloat(void);
		bool isDouble(void);
		void setConv(void);
		void setFromChar(void);
		void setFromInt(void);
		void setFromFloat(void);
		void setFromDouble(void);
		void printChar(void) const;
		void printInt(void) const;
		void printFloat(void) const;
		void printDouble(void) const;
};

#endif
