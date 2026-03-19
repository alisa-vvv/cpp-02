/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   main.cpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/17 18:08:33 by avaliull            #+#    #+#           */
/*   Updated: 2026/03/17 18:09:01 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>

int	main(
	void
) {
	const std::string	clr_non = "\033[0m";
	const std::string	clr_yel = "\033[93m";
	const std::string	clr_cya = "\033[96m";
	const std::string	clr_red = "\033[31m";
	const std::string	clr_grn = "\033[92m";
	const std::string	clr_mag = "\033[95m";

	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;
	std::cout << clr_cya << "Fixed a:" << '\n' << clr_non;
	std::cout << a.getRawBits() << std::endl;
	std::cout << clr_cya << "Fixed b:" << '\n' << clr_non;
	std::cout << b.getRawBits() << std::endl;
	std::cout << clr_cya << "Fixed c:" << '\n' << clr_non;
	std::cout << c.getRawBits() << std::endl;

	std::cout << clr_yel << "address of a: " << &a << '\n' << clr_non;
	std::cout << clr_yel << "address of b: " << &b << '\n' << clr_non;
	std::cout << clr_yel << "address of c: " << &c << '\n' << clr_non;

	a.setRawBits(123);
	c.setRawBits(456);

	std::cout << clr_cya << "Fixed a:" << '\n' << clr_non;
	std::cout << a.getRawBits() << std::endl;
	std::cout << clr_cya << "Fixed b:" << '\n' << clr_non;
	std::cout << b.getRawBits() << std::endl;
	std::cout << clr_cya << "Fixed c:" << '\n' << clr_non;
	std::cout << c.getRawBits() << std::endl;
}
