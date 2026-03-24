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
void	testIncrement(
	const std::string &op,
	const std::string&	var_name,
	Fixed&	var,
	const std::string&	pre_or_post
) {
	std::cout << '\n';
	std::cout << clr_yel << "Testing: " << clr_non;
	if (pre_or_post == "prefix") {
		std::cout << clr_cya << op << var_name << clr_non << "\n";
		std::cout << clr_yel << var_name << ": " << var << clr_non << '\n';
		std::cout << clr_yel << "Result inside expr: " << clr_non << ++var;
		std::cout << clr_yel << " Result after expr: " << clr_non << var;
	}
	else if (pre_or_post == "postfix") {
		std::cout << clr_cya << var_name << op << clr_non << "\n";
		std::cout << clr_yel << var_name << ": " << var << clr_non << '\n';
		std::cout << clr_yel << "Result inside expr: " << clr_non << var++;
		std::cout << clr_yel << " Result after expr: " << clr_non << var;
	}
	std::cout << '\n';
}
void	testDecrement(
	const std::string &op,
	const std::string&	var_name,
	Fixed&	var,
	const std::string&	pre_or_post
) {
	std::cout << '\n';
	std::cout << clr_yel << "Testing: " << clr_non;
	if (pre_or_post == "prefix") {
		std::cout << clr_cya << op << var_name << clr_non << "\n";
		std::cout << clr_yel << var_name << ": " << var << clr_non << '\n';
		std::cout << clr_yel << "Result inside expr: " << clr_non << --var;
		std::cout << clr_yel << " Result after expr: " << clr_non << var;
	}
	else if (pre_or_post == "postfix") {
		std::cout << clr_cya << var_name << op << clr_non << "\n";
		std::cout << clr_yel << var_name << ": " << var << clr_non << '\n';
		std::cout << clr_yel << "Result inside expr: " << clr_non << var--;
		std::cout << clr_yel << " Result after expr: " << clr_non << var;
	}
	std::cout << '\n';
}
void	testMin(
	const std::string &op,
	const std::string&	var1_name,
	Fixed&	var1,
	const std::string&	var2_name,
	Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << Fixed::min(var1, var2) << "\n";
}
void	testConstMin(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << Fixed::min(var1, var2) << "\n";
}
void	testMax(
	const std::string &op,
	const std::string&	var1_name,
	Fixed&	var1,
	const std::string&	var2_name,
	Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << Fixed::max(var1, var2) << "\n";
}
void	testConstMax(
	const std::string &op,
	const std::string&	var1_name,
	const Fixed&	var1,
	const std::string&	var2_name,
	const Fixed&	var2
) {
	testText(op, var1_name, var1, var2_name, var2);
	std::cout << clr_yel << "Result: " << clr_non << Fixed::max(var1, var2) << "\n";
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
	testDiv(" / ", "0", 0, "25", 25);
	testDiv(" / ", "0", 0, "-25", -25);
	testDiv(" / ", "0", 0, "25.7f", 25.7f);
	testDiv(" / ", "0", 0, "-25.7f", -25.7f);
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
	
	testIncrement("++", "c", c, "prefix");
	testIncrement("++", "b", b, "postfix");
	std::cout << '\n';

	b = 125.50f;
	c = 125.50f;
	testDecrement("--", "c", c, "prefix");
	testDecrement("--", "b", b, "postfix");
	std::cout << '\n';

	const Fixed& const_a = a;
	const Fixed& const_b = b;
	testMin(" min ", "a", a, "b", b);
	testMin(" min ", "b", b, "a", a);
	testMin(" min ", "b", b, "b", b);
	testConstMin(" min ", "const_a", const_a, "const_b", const_b);
	testConstMin(" min ", "const_b", const_b, "const_a", const_a);
	testConstMin(" min ", "const_b", const_b, "const_b", const_b);
	std::cout << '\n';

	testMax(" max ", "a", a, "b", b);
	testMax(" max ", "b", b, "a", a);
	testMax(" max ", "b", b, "b", b);
	testConstMax(" max ", "const_a", const_a, "const_b", const_b);
	testConstMax(" max ", "const_b", const_b, "const_a", const_a);
	testConstMax(" max ", "const_b", const_b, "const_b", const_b);
	std::cout << '\n';

	std::cout << clr_yel << "Test from the subject pdf:" << clr_non << "\n";
	Fixed subj_a;
	Fixed const subj_b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << subj_a << std::endl;
	std::cout << ++subj_a << std::endl;
	std::cout << subj_a << std::endl;
	std::cout << subj_a++ << std::endl;
	std::cout << subj_a << std::endl;
	std::cout << subj_b << std::endl;
	std::cout << Fixed::max( subj_a, subj_b ) << std::endl;
	return (0);
}
