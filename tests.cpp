#include "Fixed.hpp"
#include <iostream>

#define NORMAL "\033[0m"
#define RED "\033[31;1;1m"
#define GREEN "\033[32;1;1m"
#define YELLOW "\033[33;1;1m"

int main( void ) {
	
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2.0f ) );


	std::cout << YELLOW << "*** TESTS FROM SUBJECT ***" << NORMAL << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;


	std::cout << YELLOW << "*** OPERATORS ***" << NORMAL << std::endl;

	a = Fixed(5.0f);
	b = Fixed(2);

	std::cout << "+  : " << a + b << std::endl;
	std::cout << "-  : " << a - b << std::endl;
	std::cout << "Div: " << a / b << std::endl;
	std::cout << "Mul: " << a * b << std::endl;

	std::cout << "-- : " << --a << ' ' << --b << std::endl;
	std::cout << "++ : " << a++ << ' ' << b++ << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;

	return 0;
}
