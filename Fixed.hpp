#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	int					value;
	static const int	number_of_fractional_bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed&);
	Fixed(const int);
	Fixed(const float);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const);
	float	toFloat(void) const;
	int		toInt(void) const;

	static const Fixed&	min(Fixed const &a, Fixed const &b);
	static const Fixed&	max(Fixed const &a, Fixed const &b);

	// ? Arithmetic operators
	Fixed&	operator=(Fixed const &);
	Fixed	operator+(Fixed const &);
	Fixed	operator-(Fixed const &);
	Fixed	operator*(Fixed const &);
	Fixed	operator/(Fixed const &);

	// ? -crements
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	// ? Logical operators
	bool	operator==(Fixed const &) const;
	bool	operator!=(Fixed const &) const;
	bool	operator<(Fixed const &) const;
	bool	operator<=(Fixed const &) const;
	bool	operator>(Fixed const &) const;
	bool	operator>=(Fixed const &) const;

};

std::ostream&	operator<<(std::ostream &out, Fixed const &obj);
const Fixed&	min(Fixed const &a, Fixed const &b);
const Fixed&	max(Fixed const &a, Fixed const &b);
