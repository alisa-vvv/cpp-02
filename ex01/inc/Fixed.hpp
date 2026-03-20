/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Fixed.hpp                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/17 18:09:25 by avaliull            #+#    #+#           */
/*   Updated: 2026/03/17 18:18:09 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>

class Fixed {
public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		int	getRawBits(
			void
		) const;

		void	setRawBits(
			const int	raw
		);
	
		float toFloat(
			void
		) const;
		int toInt(
			void
		) const;
private:
	int					_fixed_point_value;
	static const int	_fract_bits = 8;
};

std::ostream& operator<<(
	std::ostream& stream,
	const Fixed& thing
);

