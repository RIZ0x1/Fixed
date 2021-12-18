#include "Fixed.hpp"

// ? CONSTURCTORS & DESTRUCTOR

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &init_obj)
{
	this->value = init_obj.getRawBits();
}

Fixed::Fixed(const int value)
{
	this->value = (value << this->number_of_fractional_bits);
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << this->number_of_fractional_bits));
}

Fixed::~Fixed()
{
}

// ? METHODS

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const value)
{
	this->value = value;
}

float Fixed::toFloat(void) const
{
	return ( float(this->value) / float(1 << this->number_of_fractional_bits) );
}

int Fixed::toInt(void) const
{
	return ( this->value >> this->number_of_fractional_bits );
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	return ( (a.value < b.value) ? a : b );
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
	return ( (a.value > b.value) ? a : b );
}

// ? OPERATORS

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return (out);
}

Fixed&	Fixed::operator=(Fixed const &obj)
{
	this->value = obj.value;
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &obj)
{
	Fixed	ret;

	ret.value = (this->value + obj.value);
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &obj)
{
	Fixed	ret;

	ret.value = (this->value - obj.value);
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &obj)
{
	Fixed	ret(*this);
	long	left;
	long	right;

	left = long(this->getRawBits());
	right = long(obj.getRawBits());
	ret.value = ((left * right) / (1 << Fixed::number_of_fractional_bits));
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &obj)
{
	Fixed	ret(*this);
	long	left;
	long	right;

	left = long(this->getRawBits());
	right = long(obj.getRawBits());
	ret.value = (left * (1 << Fixed::number_of_fractional_bits) / right);
	return (ret);
}

Fixed&	Fixed::operator++(void)
{
	(this->value++);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed ret(*this);

	(this->value++);
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	(this->value--);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed ret(*this);

	(this->value--);
	return (ret);
}

bool	Fixed::operator==(Fixed const &obj) const
{
	return (this->value == obj.value);
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (this->value != obj.value);
}

bool	Fixed::operator<(Fixed const &obj) const
{
	return (this->value < obj.value);
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (this->value <= obj.value);
}

bool	Fixed::operator>(Fixed const &obj) const
{
	return (this->value > obj.value);
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (this->value >= obj.value);
}
