/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:20:41 by sleleu            #+#    #+#             */
/*   Updated: 2023/01/09 00:32:30 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef STD_IMPLEMENTATION_HPP
# define STD_IMPLEMENTATION_HPP

namespace ft
{
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