/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:17:17 by sleleu            #+#    #+#             */
/*   Updated: 2023/01/09 00:32:09 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>
#include "std_implementation.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

// TESTS

int main(void)
{

	std::cout << BOLDMAGENTA << "\n\n FT::IS_INTEGRAL COMPLETE TESTS \n\n";
    
	std::cout << std::boolalpha;

	std::cout << BOLDGREEN << "\nINT TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<int>::value << "\n";
    std::cout << std::is_integral<unsigned int>::value << "\n";
    std::cout << std::is_integral<const int>::value << "\n";
    std::cout << std::is_integral<const unsigned int>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<int>::value << "\n";
    std::cout << ft::is_integral<unsigned int>::value << "\n";
    std::cout << ft::is_integral<const int>::value << "\n";
    std::cout << ft::is_integral<const unsigned int>::value << "\n";

	std::cout << BOLDGREEN << "\nSIZE_T TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<size_t>::value << "\n";
    std::cout << std::is_integral<const size_t>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<size_t>::value << "\n";
    std::cout << ft::is_integral<const size_t>::value << "\n";

	std::cout << BOLDGREEN << "\nFLOAT TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<float>::value << "\n";
    std::cout << std::is_integral<const float>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<float>::value << "\n";
    std::cout << ft::is_integral<const float>::value << "\n";

	std::cout << BOLDGREEN << "\nDOUBLE TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<double>::value << "\n";
    std::cout << std::is_integral<const double>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<double>::value << "\n";
    std::cout << ft::is_integral<const double>::value << "\n";

	std::cout << BOLDGREEN << "\nCHAR TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<char>::value << "\n";
    std::cout << std::is_integral<unsigned char>::value << "\n";
    std::cout << std::is_integral<const char>::value << "\n";
    std::cout << std::is_integral<const unsigned char>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<char>::value << "\n";
    std::cout << ft::is_integral<unsigned char>::value << "\n";
    std::cout << ft::is_integral<const char>::value << "\n";
    std::cout << ft::is_integral<const unsigned char>::value << "\n";

	std::cout << BOLDGREEN << "\nCHAR16_T TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<char16_t>::value << "\n";
    std::cout << std::is_integral<const char16_t>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<char16_t>::value << "\n";
    std::cout << ft::is_integral<const char16_t>::value << "\n";

	std::cout << BOLDGREEN << "\nCHAR32_T TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<char32_t>::value << "\n";
    std::cout << std::is_integral<const char32_t>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<char32_t>::value << "\n";
    std::cout << ft::is_integral<const char32_t>::value << "\n";

	std::cout << BOLDGREEN << "\nWCHAR_T TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<wchar_t>::value << "\n";
    std::cout << std::is_integral<const wchar_t>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<wchar_t>::value << "\n";
    std::cout << ft::is_integral<const wchar_t>::value << "\n";

	std::cout << BOLDGREEN << "\nLONG TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<long>::value << "\n";
    std::cout << std::is_integral<unsigned long>::value << "\n";
    std::cout << std::is_integral<const long>::value << "\n";
    std::cout << std::is_integral<const unsigned long>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<long>::value << "\n";
    std::cout << ft::is_integral<unsigned long>::value << "\n";
    std::cout << ft::is_integral<const long>::value << "\n";
    std::cout << ft::is_integral<const unsigned long>::value << "\n";

	std::cout << BOLDGREEN << "\nLONG LONG TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<long long>::value << "\n";
    std::cout << std::is_integral<unsigned long long>::value << "\n";
    std::cout << std::is_integral<const long long>::value << "\n";
    std::cout << std::is_integral<const unsigned long long>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<long long>::value << "\n";
    std::cout << ft::is_integral<unsigned long long>::value << "\n";
    std::cout << ft::is_integral<const long long>::value << "\n";
    std::cout << ft::is_integral<const unsigned long long>::value << "\n";

	std::cout << BOLDGREEN << "\nSHORT TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<short>::value << "\n";
    std::cout << std::is_integral<unsigned short>::value << "\n";
    std::cout << std::is_integral<const short>::value << "\n";
    std::cout << std::is_integral<const unsigned short>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<short>::value << "\n";
    std::cout << ft::is_integral<unsigned short>::value << "\n";
    std::cout << ft::is_integral<const short>::value << "\n";
    std::cout << ft::is_integral<const unsigned short>::value << "\n";

	std::cout << BOLDGREEN << "\nBOOL TEST\n";
	std::cout << BOLDYELLOW << "std:\n";
    std::cout << std::is_integral<bool>::value << "\n";
    std::cout << std::is_integral<const bool>::value << "\n";
	std::cout << BOLDCYAN << "ft:\n";
    std::cout << ft::is_integral<bool>::value << "\n";
    std::cout << ft::is_integral<const bool>::value << "\n" << RESET;

    return (0);
}
