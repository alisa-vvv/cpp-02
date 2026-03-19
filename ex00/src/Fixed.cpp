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

Fixed::Fixed() : _value(0){
	std::cout << "default constructor called\n";
}

// Deep copy?
Fixed::Fixed(const Fixed &other) {
	std::cout << "default copy constructor called\n";
	*this = other;
}

// Shallow copy?
Fixed &Fixed::operator =(const Fixed &other) {
	std::cout << "assignment operator called\n";
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "default destructor called\n";
}

int	Fixed::getRawBits(
	void
) const {
	std::cout << "getRawBits called\n";
	return (_value);
}

void	Fixed::setRawBits(
	const int	raw
) {
	_value = raw;
}
	//	Fixed();
	//	Fixed(const Fixed &other);
	//	void operator=(const Fixed &other);
	//	~Fixed();

	//	int	getRawBits(
	//		void
	//	) const;
	//	void	setRawBits(
	//		const int	raw
	//	) const;
