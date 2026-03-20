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
#include <fstream>
#include <cmath>

Fixed::Fixed() : _fixed_point_value(0) {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int value) : _fixed_point_value(value) {
	std::cout << "Int constructor called\n";

	for (int i = 0; i < _fract_bits; i++) {
		_fixed_point_value *= 2;
	}
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";

	float	multiplied_value = value;
	for (int i = 0; i < _fract_bits; i++) {
		multiplied_value *= 2;
	}
	_fixed_point_value = roundf(multiplied_value);
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

void Fixed::operator<<(std::ofstream& stream) {
	if (!stream.is_open())
		return ;
	stream << toFloat();
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
	float	float_value = _fixed_point_value;
	for (int i = 0; i < _fract_bits; i++) {
		float_value /= 2;
	}
	return (float_value);
}

int Fixed::toInt(
	void
) const {
	float	float_value = toFloat();
	return (roundf(float_value));
}
