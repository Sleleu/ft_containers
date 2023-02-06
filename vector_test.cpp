/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:46:20 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/06 16:57:10 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <memory>
#include "iterator.hpp"
#include "colors.hpp"

template <class T1, class T2>
void	print_vector(T1& std_vector, T2& ft_vector) // si pas de reference std ne change pas de capacity ?
{
	typename T1::iterator it = std_vector.begin();
	typename T1::iterator ite = std_vector.end();
	typename T2::iterator it2 = ft_vector.begin();
	typename T2::iterator ite2 = ft_vector.end();

	for (; it < ite || it2 < ite2 ; it++, it2++)
		std::cout << BOLDYELLOW << "std value : " << *it << " | " << BOLDCYAN << "ft value : " << *it2 << std::endl;
	std::cout << BOLDYELLOW << "std size :  " << std_vector.size() << " | " << BOLDCYAN <<  "ft size : " << ft_vector.size()  << " |" << std::endl;
	std::cout << BOLDYELLOW << "std capacity : " << std_vector.capacity() << " | " << BOLDCYAN <<  "ft capacity : " << ft_vector.capacity() << " |" << std::endl;		
}

int main(void)
{
	ft::vector<int> ft_vector(4, 10);
	std::vector<int> std_vector(4, 10);
	std::vector<int> ft_v2;
	std::vector<int> std_v2;
	
	print_vector(std_vector, ft_vector);
	std::cout << BOLDYELLOW << "std size :  " << std_vector.max_size() << " | " << BOLDCYAN <<  "ft max_size : " << ft_vector.max_size()  << " |" << std::endl;
	std::cout << BOLDCYAN << "ft : empty function for empty vector : " << ft_v2.empty() << std::endl;	
	std::cout << "ft : empty function for not empty vector : " << ft_vector.empty() << std::endl;
	std::cout << BOLDYELLOW << "std : empty function for empty vector : " << std_v2.empty() << std::endl;
	std::cout << "std : empty function for not empty vector : " << std_vector.empty() << std::endl;

	std::cout << BOLDGREEN << "\nVECTOR REVERSE_ITERATOR : " << "\n";

	std::cout << BOLDYELLOW << "STD TESTS" << "\n";
	std::vector<int>::reverse_iterator rit2 = std_vector.rbegin();
	std::vector<int>::reverse_iterator rite2 = std_vector.rend();
	for (; rit2 < rite2; rit2++)
		std::cout << "std reverse_iterator test " << *rit2 << "\n";
	std::cout << BOLDCYAN << "FT TESTS" << "\n";
	ft::vector<int>::reverse_iterator rit1 = ft_vector.rbegin();
	ft::vector<int>::reverse_iterator rite1 = ft_vector.rend();
	for (; rit1 < rite1; rit1++)
		std::cout << "ft reverse_iterator test " << *rit1 << "\n";

	std::cout << BOLDGREEN << "\nVECTOR RESERVE : " << "\n";
	ft_vector.reserve(50); // new_cap > capacity
	std_vector.reserve(50);
	ft_vector.reserve(10); // new_cap < capacity 
	std_vector.reserve(10);
	print_vector(std_vector, ft_vector);
	
	std::cout << BOLDGREEN << "\nVECTOR PUSH_BACK | INSERT : " << "\n";
	std_vector.push_back(42);
	ft_vector.push_back(42);
	print_vector(std_vector, ft_vector);

	ft::vector<int>::iterator ft_it3 = ft_vector.begin();
	ft::vector<int>::iterator ft_ite3 = ft_vector.end();
	for (; ft_it3 < ft_ite3 + 1; ft_it3++)
		std::cout << "ft : " << *ft_it3 << std::endl;
	
	std::cout << RESET;
	return (0);
}