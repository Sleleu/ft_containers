/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:20:41 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/10 22:58:46 by sleleu           ###   ########.fr       */
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

/*
Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).

Lexicographical comparison is an operation with the following properties:

Two ranges are compared element by element.
The first mismatching element defines which range is lexicographically less or greater than the other.
If one range is a prefix of another, the shorter range is lexicographically less than the other.
If two ranges have equivalent elements and are of the same length, then the ranges are lexicographically equal.
An empty range is lexicographically less than any non-empty range.
Two empty ranges are lexicographically equal.


@ first1, last1	-	the first range of elements to examine
@ first2, last2	-	the second range of elements to examine
*/

	template <class It1, class It2>
	bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2)
	{
		for (;first1 != last1 && first2 != last2; ++first1, (void) ++first2)
		{
		if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return ((first1 == last1) && (first2 == last2));
	}

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