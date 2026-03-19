/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Fixed.cpp                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/19 15:16:58 by avaliull            #+#    #+#           */
/*   Updated: 2026/03/19 15:18:12 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <string>

Fixed::Fixed() : _fixed_point_value(0) {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int value) : _fixed_point_value(value) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	//union {
	//	float	number;
	//	struct	{
	//	unsigned int mantissa : 23;
	//	unsigned int exponent : 8;
	//	unsigned int sign : 1;
	//	}	parts;
	//}	float_cast;
	//float_cast.number = value;
	//std::cout << "float_cast.number: " << float_cast.number << '\n';
	//std::cout << "float_cast.mantissa: " << float_cast.parts.mantissa << '\n';
	//std::cout << "float_cast.exponent: " << float_cast.parts.exponent << '\n';
	//std::cout << "float_cast.sign: " << float_cast.parts.sign << '\n';
	//std::cout << "reconstructed float: " << (float_cast.parts.mantissa * std::pow(2, float_cast.parts.exponent) * ((float_cast.parts.sign == 0) ? 1 : -1)) << '\n';
	std::string	string_float = std::to_string(value);
	std::cout << "Float as string: " << string_float << '\n';
	size_t	dot_location = string_float.find_first_of(".");

	if (dot_location == std::string::npos) {
		_fixed_point_value = value;
	}
	else {
		std::string	whole = string_float.substr(0, dot_location);
		std::string	fraction = string_float.substr(dot_location + 1, string_float.length());
		std::cout << "whole string: " << whole << '\n';
		std::cout << "fraction string: " << fraction << '\n';
		_fixed_point_value = std::stoi(whole) * (std::pow(10, fraction.length())) + stoi(fraction);
		std::cout << "_fixed_point_value: " << _fixed_point_value << '\n';
	}
}


// Deep copy?
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

// Shallow copy?
Fixed &Fixed::operator =(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_fixed_point_value = other._fixed_point_value;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Default destructor called\n";
}

int	Fixed::getRawBits(
	void
) const {
	std::cout << "getRawBits called\n";
	return (_fixed_point_value);
}

void	Fixed::setRawBits(
	const int	raw
) {
	_fixed_point_value = raw;
}

float Fixed::toFloat(
	void
) const {
	std::cout << " to flaot\n";
	return ((float) _fixed_point_value);
}

int Fixed::toInt(
	void
) const {
	std::cout << " to int\n";
	return (_fixed_point_value);
}
