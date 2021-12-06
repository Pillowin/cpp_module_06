/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:16:45 by agautier          #+#    #+#             */
/*   Updated: 2021/12/06 20:00:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
**	Default private constructor.
*/
Convert::Convert(void) {}

/*
**	Copy constructor.
*/
Convert::Convert(Convert const& src) { *this = src; }

/*
**	Parametric constructor.
*/
Convert::Convert(std::string const& literal_value) :
	literal_value(literal_value),
	literal_error(false) {
	this->setConv();
}

/*
**	Destructor.
*/
Convert::~Convert(void) {}

/*
**	Print all values by calling corresponding func.
*/
void Convert::print(void) {
	if (this->literal_error)
		return;
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

/*
**	Detect which conv is the initial one then call corresponding conv func.
*/
void Convert::setConv(void) {
	int index;
	bool (Convert::*is[NB_CONV])()	= {&Convert::isChar,
									   &Convert::isInt,
									   &Convert::isFloat,
									   &Convert::isDouble};
	void (Convert::*set[NB_CONV])() = {&Convert::setFromChar,
									   &Convert::setFromInt,
									   &Convert::setFromFloat,
									   &Convert::setFromDouble};

	for (index = 0; index < NB_CONV; index++)
		if ((this->*is[index])())
			return (this->*set[index])();
	std::cerr << "Error: unknow literal value." << std::endl;
	this->literal_error = true;
}

/*
**	Check if literal_value is a char.
*/
bool Convert::isChar(void) {
	return (this->literal_value.length() == 1
			&& !std::isdigit(this->literal_value.at(0)))
			 ? true
			 : false;
}

/*
**	Check if literal_value is an int.
*/
bool Convert::isInt(void) {
	std::stringstream ss;
	std::string garbage;

	ss << this->literal_value;
	ss >> this->i;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> garbage;
	return (garbage.empty()) ? true : false;
}

/*
**	Check if literal_value is a float.
*/
bool Convert::isFloat(void) {
	std::stringstream ss;
	std::string garbage;

	if (this->literal_value == "nanf" || this->literal_value == "+inff"
		|| this->literal_value == "inff" || this->literal_value == "-inff")
		return (true);

	ss << this->literal_value;
	ss >> this->f >> this->c;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> garbage;
	if (this->c == 'f' && garbage.empty()) {
		std::cout << std::setprecision(this->literal_value.length() - 2);
		return (true);
	}
	return (false);
}

/*
**	Check if literal_value is a double.
*/
bool Convert::isDouble(void) {
	std::stringstream ss;
	std::string garbage;

	if (this->literal_value == "nan" || this->literal_value == "+inf"
		|| this->literal_value == "inf" || this->literal_value == "-inf")
		return (true);

	ss << this->literal_value;
	ss >> this->d;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> garbage;
	if (garbage.empty()) {
		std::cout << std::setprecision(this->literal_value.length() - 1);
		return (true);
	}
	return (false);
}

/*
**	Set all attributes from char.
*/
void Convert::setFromChar(void) {
	std::stringstream ss;

	ss << this->literal_value;
	ss >> this->c;
	this->i = static_cast<int>(this->c);
	this->f = static_cast<float>(this->c);
	this->d = static_cast<double>(this->c);
}

/*
**	Set all attributes from int.
*/
void Convert::setFromInt(void) {
	std::stringstream ss;

	ss << this->literal_value;
	ss >> this->i;
	this->c = static_cast<int>(this->i);
	this->f = static_cast<float>(this->i);
	this->d = static_cast<double>(this->i);
}

/*
**	Set all attributes from float.
*/
void Convert::setFromFloat(void) {
	std::stringstream ss;

	ss << this->literal_value;
	ss >> this->f;

	if (this->literal_value == "inff" || this->literal_value == "+inff")
		this->f = std::numeric_limits<float>::infinity();
	else if (this->literal_value == "-inff")
		this->f = std::numeric_limits<float>::infinity() * -1;
	else if (this->literal_value == "nanf")
		this->f = std::numeric_limits<float>::quiet_NaN();

	this->c = static_cast<int>(this->f);
	this->i = static_cast<float>(this->f);
	this->d = static_cast<double>(this->f);
}

/*
**	Set all attributes from double.
*/
void Convert::setFromDouble(void) {
	std::stringstream ss;

	ss << this->literal_value;
	ss >> this->d;

	if (this->literal_value == "inf" || this->literal_value == "+inf")
		this->d = std::numeric_limits<double>::infinity();
	else if (this->literal_value == "-inf")
		this->d = std::numeric_limits<double>::infinity() * -1;
	else if (this->literal_value == "nan")
		this->d = std::numeric_limits<double>::quiet_NaN();

	this->c = static_cast<int>(this->d);
	this->i = static_cast<float>(this->d);
	this->f = static_cast<double>(this->d);
}

/*
**	Print literal_value converted to char.
*/
void Convert::printChar(void) const {
	if (this->literal_value == "inf" || this->literal_value == "+inf"
		|| this->literal_value == "-inf" || this->literal_value == "nan"
		|| this->literal_value == "inff" || this->literal_value == "+inff"
		|| this->literal_value == "-inff" || this->literal_value == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(this->c))
		std::cout << "char: '" << this->c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

/*
**	Print literal_value converted to int.
*/
void Convert::printInt(void) const {
	if (this->literal_value == "inf" || this->literal_value == "+inf"
		|| this->literal_value == "-inf" || this->literal_value == "nan"
		|| this->literal_value == "inff" || this->literal_value == "+inff"
		|| this->literal_value == "-inff" || this->literal_value == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->i << std::endl;
}

/*
**	Print literal_value converted to float.
*/
void Convert::printFloat(void) const {
	std::cout << "float: " << this->f << ((!fmod(this->f, 1.0f)) ? ".0f" : "f")
			  << std::endl;
}

/*
**	Print literal_value converted to double.
*/
void Convert::printDouble(void) const {
	std::cout << "double: " << this->d << ((!fmod(this->d, 1.0)) ? ".0" : "")
			  << std::endl;
}

/*
**	Assignation operator.
*/
Convert& Convert::operator=(Convert const& rhs) {
	if (this == &rhs)
		return (*this);
	this->literal_value = rhs.literal_value;
	this->c				= rhs.c;
	this->i				= rhs.i;
	this->f				= rhs.f;
	this->d				= rhs.d;
	this->literal_error = rhs.literal_error;
	return (*this);
}
