/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   main.cpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/17 18:08:33 by avaliull            #+#    #+#           */
/*   Updated: 2026/03/20 19:57:30 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <limits.h>

int	main(
	void
) {
	Fixed	a;
	Fixed const	b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << '\n';

	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";
	std::cout << "c is " << c << "\n";
	std::cout << "d is " << d << "\n";
	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	std::cout << "b is " << b.toInt() << " as integer" << "\n";
	std::cout << "c is " << c.toInt() << " as integer" << "\n";
	std::cout << "d is " << d.toInt() << " as integer" << "\n";

	std::cout << clr_yel << "\nTesting INT limits" << clr_non << '\n';

	std::cout << clr_yel << "0. Above INT_MAX:" << clr_non << '\n';

	std::cout << clr_yel << "1. Above INT_MAX:" << clr_non << '\n';
	a = Fixed(2173838291389212.3281f);
	std::cout << "a is " << a << "\n";

	std::cout << clr_yel << "2. INT_MAX / 2:" << clr_non << '\n';
	a = Fixed(INT_MAX / 2);
	std::cout << "a is " << a << "\n";

	std::cout << clr_yel << "3. Below INT_MIN:" << clr_non << '\n';
	a = Fixed(-2173838291389212.3281f);
	std::cout << "a is " << a << "\n";

	std::cout << clr_yel << "4. INT_MIN / 2:" << clr_non << '\n';
	a = Fixed(INT_MIN / 2);
	std::cout << "a is " << a << "\n";
	std::cout << '\n';

	return (0);
}
