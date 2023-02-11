/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:20:41 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/10 23:46:17 by sleleu           ###   ########.fr       */
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
		/*      FT::EQUAL           */
		/*--------------------------*/

/*
	Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)),
	and false otherwise.

*/

	template <class It1, class It2>
	bool equal(It1 first1, It1 last1, It2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
			if (!(*first1 == *first2))
				return (false);
		return (true);
	}

		/*--------------------------*/
		/*      FT::PAIR            */
		/*--------------------------*/

/*
	std::pair is a class template that provides a way to store two heterogeneous objects as a single unit.

	@ T1, T2	-	the types of the elements that the pair stores.
*/

	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		/* ATTRIBUTES */
		T1 first;
		T2 second;

		/* CONSTRUCTORS */

		// Default constructor. Value-initializes both elements of the pair, first and second.
		pair() : first(0), second(0) {}
		
		// Initializes first with x and second with y.
		pair(const T1& x, const T2& y) : first(x), second(y) {}
		
		//  Initializes first with p.first and second with p.second.
		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}


		/* OPERATOR */
		
		pair& operator=(const pair& other)
		{
			this->first = other.first;
			this->second = other.second;
			return (*this);
		}

	};

	/*-------- PAIR NON-MEMBER FUNCTION --------*/

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first != rhs.first && lhs.second != rhs.second); // CONTINUER ICI
	}

	// template <class T1, class T2>
	// bool operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {}

	// template <class T1, class T2>
	// bool operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {}

	// template <class T1, class T2>
	// bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {}

	// template <class T1, class T2>
	// bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {}	

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