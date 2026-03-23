/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Fixed.hpp                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/17 18:09:25 by avaliull            #+#    #+#           */
/*   Updated: 2026/03/20 19:05:18 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <limits.h>
const std::string	clr_non = "\033[0m";
const std::string	clr_yel = "\033[93m";
const std::string	clr_cya = "\033[96m";
const std::string	clr_red = "\033[31m";
const std::string	clr_grn = "\033[92m";
const std::string	clr_mag = "\033[95m";

class Fixed {
public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

	// _fract_bits interfaces
		int	getRawBits(
			void
		) const;
		void	setRawBits(
			const int	raw
		);
	
	// Conversions
		float toFloat(
			void
		) const;
		int toInt(
			void
		) const;

	// Comparison operators
	int	operator>(const Fixed &right) const;
	int	operator<(const Fixed &right) const;
	int	operator<=(const Fixed &right) const;
	int	operator>=(const Fixed &right) const;
	int	operator==(const Fixed &right) const;
	int	operator!=(const Fixed &right) const;
	
	// Arithmetic operators
	Fixed	operator+(const Fixed &right) const;
	Fixed	operator-(const Fixed &right) const;
	Fixed	operator*(const Fixed &right) const;
	Fixed	operator/(const Fixed &right) const;

private:
	int					_fixed_point_value;
	static const int	_fract_bits = 8;

	// integer limit guards
	bool	_checkLimits(
		int&	value
	);
	bool	_checkLimits(
		float&	value
	);
};

// ostream overload, has to be outside of class for some reason
std::ostream& operator<<(
	std::ostream& stream,
	const Fixed& thing
);

