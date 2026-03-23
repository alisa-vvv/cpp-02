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

static void	testText(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	std::cout << '\n';
	std::cout << clr_yel << "Testing: ";
	std::cout << clr_cya << var1_name << op << var2_name << clr_non << '\n';
	std::cout << clr_yel << var1_name << ": " << clr_non << var1 << '\n';
	std::cout << clr_yel << var2_name << ": " << clr_non << var2 << '\n';
}

void	testBigger(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 > var2) << "\n";
}
void	testSmaller(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 < var2) << "\n";
}
void	testSmallerOrEqual(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 <= var2) << "\n";
}
void	testBiggerOrEqual(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 >= var2) << "\n";
}

void	testMult(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 * var2) << "\n";
}
void	testDiv(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 / var2) << "\n";
}
void	testAdd(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 + var2) << "\n";
}
void	testSubstr(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << (var1 - var2) << "\n";
}

int	main(
	void
) {
	Fixed	a(125.51f);
	Fixed	b(125.50f);
	Fixed	c(125.50f);
	Fixed	neg_int(-7);
	Fixed	neg_float(-7.36f);
	Fixed	yes_mod(3);
	Fixed	no_mod(5.0f);

	// Comparisons
	testBigger(" > ", "a", a, "b", b);
	testBigger(" > ", "a", a, "neg_float", neg_float);
	std::cout << '\n';

	testSmaller(" < ", "a", a, "b", b);
	testSmaller(" < ", "a", a, "neg_float", neg_float);
	std::cout << '\n';

	testSmallerOrEqual(" <= ", "a", a, "b", b);
	testSmallerOrEqual(" <= ", "b", b, "a", a);
	testSmallerOrEqual(" <= ", "b", b, "c", c);
	testSmallerOrEqual(" <= ", "c", c, "b", b);
	std::cout << '\n';

	testBiggerOrEqual(" >= ", "a", a, "b", b);
	testBiggerOrEqual(" >= ", "b", b, "a", a);
	testBiggerOrEqual(" >= ", "b", b, "c", c);
	testBiggerOrEqual(" >= ", "c", c, "b", b);
	std::cout << '\n';

	//	Arythmetics
	testMult(" * ", "a", a, "yes_mod", yes_mod);
	std::cout << '\n';

	testDiv(" / ", "a", a, "yes_mod", yes_mod);
	testDiv(" / ", "a", a, "no_mod", no_mod);
	testDiv(" / ", "a", a, "neg_float", neg_float);
	testDiv(" / ", "neg_int", neg_int, "neg_float", neg_float);
	std::cout << '\n';

	testAdd(" + ", "a", a, "b", b);
	testAdd(" + ", "a", a, "a", b);
	testAdd(" + ", "a", a, "neg_float", neg_float);
	testAdd(" + ", "neg_int", neg_int, "neg_float", neg_float);
	std::cout << '\n';

	testSubstr(" - ", "a", a, "b", b);
	testSubstr(" - ", "a", a, "a", b);
	testSubstr(" - ", "a", a, "neg_float", neg_float);
	testSubstr(" - ", "neg_int", neg_int, "neg_float", neg_float);
	std::cout << '\n';

	return (0);
}
