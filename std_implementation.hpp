/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:20:41 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/07 21:56:55 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef STD_IMPLEMENTATION_HPP
# define STD_IMPLEMENTATION_HPP

namespace ft
{

		/*----------------------------------------*/
		/*      FT::LEXICOGRAPHICAL_COMPARE       */
		/*----------------------------------------*/

// continuer ici

		/*--------------------------*/
		/*      FT::ENABLE_IF       */
		/*--------------------------*/

	template < bool B, class T = void >
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {typedef T type; };
	
		/*--------------------------*/
		/*      FT::IS_INTEGRAL     */
		/*--------------------------*/

// remove_cv to check for volatile and volatile const

	template <class T>
	struct is_integral { const static bool value = false; };

	template <> struct is_integral<bool> { const static bool value = true; };
	template <> struct is_integral<volatile bool> { const static bool value = true; };
	template <> struct is_integral<volatile const bool> { const static bool value = true; };
	template <> struct is_integral<const bool> { const static bool value = true; };
	
	template <> struct is_integral<char> { const static bool value = true; };
	template <> struct is_integral<volatile char> { const static bool value = true; };
	template <> struct is_integral<volatile const char> { const static bool value = true; };
	template <> struct is_integral<const char> { const static bool value = true; };
	template <> struct is_integral<unsigned char> { const static bool value = true; };
	template <> struct is_integral<const unsigned char> { const static bool value = true; };

	template <> struct is_integral<wchar_t> { const static bool value = true; };
	template <> struct is_integral<const wchar_t> { const static bool value = true; };
	template <> struct is_integral<volatile wchar_t> { const static bool value = true; };
	template <> struct is_integral<volatile const wchar_t> { const static bool value = true; };
	
	template <> struct is_integral<short> { const static bool value = true; };
	template <> struct is_integral<const short> { const static bool value = true; };
	template <> struct is_integral<unsigned short> { const static bool value = true; };
	template <> struct is_integral<const unsigned short> { const static bool value = true; };
	template <> struct is_integral<volatile short > { const static bool value = true; };
	template <> struct is_integral<volatile const short > { const static bool value = true; };
	
	template <> struct is_integral<int> { const static bool value = true; };
	template <> struct is_integral<const int> { const static bool value = true; };
	template <> struct is_integral<unsigned int> { const static bool value = true; };
	template <> struct is_integral<volatile unsigned int> { const static bool value = true; };
	template <> struct is_integral<volatile unsigned const int> { const static bool value = true; };
	template <> struct is_integral<unsigned const int> { const static bool value = true; };
	template <> struct is_integral<volatile int> { const static bool value = true; };
	template <> struct is_integral<volatile const int> { const static bool value = true; };
	
	template <> struct is_integral<long> { const static bool value = true; };
	template <> struct is_integral<const long> { const static bool value = true; };
	template <> struct is_integral<unsigned long> { const static bool value = true; };
	template <> struct is_integral<const unsigned long> { const static bool value = true; };
	template <> struct is_integral<volatile long> { const static bool value = true; };
	template <> struct is_integral<volatile const long> { const static bool value = true; };
	
	template <> struct is_integral<long long> { const static bool value = true; };
	template <> struct is_integral<const long long> { const static bool value = true; };
	template <> struct is_integral<unsigned long long> { const static bool value = true; };
	template <> struct is_integral<const unsigned long long> { const static bool value = true; };
	template <> struct is_integral<volatile long long> { const static bool value = true; };
	template <> struct is_integral<volatile const long long> { const static bool value = true; };

}

#endif