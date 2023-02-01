/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:20:41 by sleleu            #+#    #+#             */
/*   Updated: 2023/01/31 16:11:04 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef STD_IMPLEMENTATION_HPP
# define STD_IMPLEMENTATION_HPP

namespace ft
{

		/*--------------------------*/
		/*   FT::ITERATOR_TRAITS    */
		/*--------------------------*/
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::value_type	value_type;
		typedef typename	Iterator::pointer	pointer;
		typedef typename	Iterator::reference	reference;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef	std::ptrdiff_t	difference_type;
		typedef	T	value_type;
		typedef	T*	pointer;
		typedef	T&	reference;
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef	std::ptrdiff_t	difference_type;
		typedef	T	value_type;
		typedef	const T*	pointer;
		typedef	const T&	reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

		/*--------------------------*/
		/*   FT::REVERSE_ITERATOR   */
		/*--------------------------*/	

	template <class Iterator>
	class reverse_iterator
	{
		public:
		
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
	};


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

	template <class T>
	struct is_integral { const static bool value = false; };

	template <>
	struct is_integral<bool> { const static bool value = true; };

	template <>
	struct is_integral<const bool> { const static bool value = true; };

	template <>
	struct is_integral<char> { const static bool value = true; };

	template <>
	struct is_integral<const char> { const static bool value = true; };

	template <>
	struct is_integral<unsigned char> { const static bool value = true; };

	template <>
	struct is_integral<const unsigned char> { const static bool value = true; };

	template <>
	struct is_integral<char16_t> { const static bool value = true; };

	template <>
	struct is_integral<const char16_t> { const static bool value = true; };

	template <>
	struct is_integral<char32_t> { const static bool value = true; };

	template <>
	struct is_integral<const char32_t> { const static bool value = true; };

	template <>
	struct is_integral<wchar_t> { const static bool value = true; };

	template <>
	struct is_integral<const wchar_t> { const static bool value = true; };

	template <>
	struct is_integral<short> { const static bool value = true; };

	template <>
	struct is_integral<const short> { const static bool value = true; };

	template <>
	struct is_integral<unsigned short> { const static bool value = true; };

	template <>
	struct is_integral<const unsigned short> { const static bool value = true; };

	template <>
	struct is_integral<int> { const static bool value = true; };

	template <>
	struct is_integral<const int> { const static bool value = true; };

	template <>
	struct is_integral<unsigned int> { const static bool value = true; };

	template <>
	struct is_integral<unsigned const int> { const static bool value = true; };

	template <>
	struct is_integral<long> { const static bool value = true; };

	template <>
	struct is_integral<const long> { const static bool value = true; };

	template <>
	struct is_integral<unsigned long> { const static bool value = true; };

	template <>
	struct is_integral<const unsigned long> { const static bool value = true; };

	template <>
	struct is_integral<long long> { const static bool value = true; };

	template <>
	struct is_integral<const long long> { const static bool value = true; };

	template <>
	struct is_integral<unsigned long long> { const static bool value = true; };

	template <>
	struct is_integral<const unsigned long long> { const static bool value = true; };

}

#endif