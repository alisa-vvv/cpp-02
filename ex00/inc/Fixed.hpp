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
		Fixed(const Fixed &other);
	// copy destr operator overload
		~Fixed();

		int	getRawBits(
			void
		) const;
		void	setRawBits(
			const int	raw
		) const;
private:
	int					value;
	static const int	fract_bits;
};
