/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Fixed.cpp                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/19 15:16:58 by avaliull            #+#    #+#           */
/*   Updated: 2026/03/20 19:25:15 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits.h>

// Default constructor
Fixed::Fixed() : _fixed_point_value(0) {
	std::cout << clr_mag << "Default constructor called" << clr_non << '\n';
}

// Int constructor
Fixed::Fixed(const int value) : _fixed_point_value(0) {
	std::cout << clr_mag << "Int constructor called" << clr_non << '\n';

	_fixed_point_value = value;
	for (int i = 0; i < _fract_bits; i++) {
		if (_checkLimits(_fixed_point_value) == false)
			return ;
		_fixed_point_value *= 2;
	}
}

// Float constructor
Fixed::Fixed(const float value) : _fixed_point_value(0) {
	std::cout << clr_mag << "Float constructor called" << clr_non << '\n';

	float	multiplied_value = value;
	for (int i = 0; i < _fract_bits; i++) {
		if (_checkLimits(multiplied_value) == false)
			return ;
		multiplied_value *= 2;
	}
	_fixed_point_value = roundf(multiplied_value);
}


// Deep copy?
Fixed::Fixed(const Fixed& other) {
	std::cout << clr_mag << "Copy constructor called" << clr_non << '\n';
	*this = other;
}

// Shallow copy?
Fixed& Fixed::operator =(const Fixed& other) {
	std::cout << clr_mag << "Copy assignment operator called" << clr_non << '\n';
	if (this != &other)
		this->_fixed_point_value = other._fixed_point_value;
	return (*this);
}

// Default destructor
Fixed::~Fixed() {
	std::cout << clr_mag << "Default destructor called" << clr_non << '\n';
}

// operator<< overload
std::ostream& operator<<(
	std::ostream& stream,
	const Fixed& thing
) {
	stream << thing.toFloat();
	return (stream);
}

int	Fixed::getRawBits(
	void
) const {
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

bool	Fixed::_checkLimits(
	int&	value
) {
	if (value >= roundf((float) (INT_MAX / 2))
		|| value <= roundf((float) (INT_MIN / 2)))
	{
		std::cout << clr_red << "Value outside integer limits. Setting to 0" << clr_non << '\n';
		value = 0;
		return (false);
	}
	return (true);
}

bool	Fixed::_checkLimits(
	float&	value
) {
	if (value >= roundf((float) (INT_MAX / 2))
		|| value <= roundf((float) (INT_MIN / 2)))
	{
		std::cout << clr_red << "Value outside integer limits. Setting to 0" << clr_non << '\n';
		value = 0.0f;
		return (false);
	}
	return (true);
}

// Comparison operators
int	Fixed::operator>(const Fixed &right) const {
	return (this->getRawBits() > right.getRawBits());
}
int	Fixed::operator<(const Fixed &right) const {
	return (this->getRawBits() < right.getRawBits());
}
int	Fixed::operator<=(const Fixed &right) const {
	return (this->getRawBits() <= right.getRawBits());
}
int	Fixed::operator>=(const Fixed &right) const {
	return (this->getRawBits() >= right.getRawBits());
}
int	Fixed::operator==(const Fixed &right) const {
	return (this->getRawBits() == right.getRawBits());
}
int	Fixed::operator!=(const Fixed &right) const {
	return (this->getRawBits() != right.getRawBits());
}

// Arithmetic operators
// note for divisions and mults: i wrote out multiplication steps and didn't
// for division. Im my tests, following the actual steps of calculating raw bit
// values vs just using default math turned out to have the same result.
//
Fixed	Fixed::operator+(const Fixed &right) const {
	Fixed	result;

	result.setRawBits(this->getRawBits() + right.getRawBits());
	return (result);
}
Fixed	Fixed::operator-(const Fixed &right) const {
	Fixed	result;

	result.setRawBits(this->getRawBits() - right.getRawBits());
	return (result);
}
Fixed	Fixed::operator*(const Fixed &right) const {
	Fixed	result;
	double	raw_bits_mult = this->getRawBits() * right.getRawBits();

	for (int i = 0; i < _fract_bits; i++) {
		raw_bits_mult /= 2;
	}
	raw_bits_mult = roundf(raw_bits_mult);
	result.setRawBits(raw_bits_mult);
	return (result);
}
Fixed	Fixed::operator/(const Fixed &right) const {
	return (this->toFloat() / right.toFloat());
}
