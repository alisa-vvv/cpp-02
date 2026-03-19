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

class Fixed {
public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

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
