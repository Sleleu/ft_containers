/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:46:20 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/03 18:49:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <memory>
#include "iterator.hpp"

int main(void)
{
	ft::vector<int> ft_vector(4, 10);
	ft::vector<int>::iterator ft_it = ft_vector.begin();
	ft::vector<int>::iterator ft_ite = ft_vector.end();
	for (; ft_it < ft_ite; ft_it++)
		std::cout << "ft : " << *ft_it << std::endl;
	std::cout << "size : " << ft_vector.size() << std::endl;
	std::cout << "capacity : " << ft_vector.capacity() << std::endl;
	std::cout << "max size : " << ft_vector.max_size() << std::endl;
	std::vector<int> ft_v2;
	std::cout << "empty function for empty vector : " << ft_v2.empty() << std::endl;	
	std::cout << "empty function for not empty vector : " << ft_vector.empty() << std::endl;

	std::vector<int> std_vector(4, 10);
	std::vector<int>::iterator std_it = std_vector.begin();
	std::vector<int>::iterator std_ite = std_vector.end();
	for (; std_it < std_ite; std_it++)
		std::cout << "std : " << *std_it << std::endl;
	std::cout << "size : " << std_vector.size() << std::endl;
	std::cout << "capacity : " << std_vector.capacity() << std::endl;
	std::cout << "max size : " << std_vector.max_size() << std::endl;
	std::vector<int> std_v2;
	std::cout << "empty function for empty vector : " << std_v2.empty() << std::endl;
	std::cout << "empty function for not empty vector : " << std_vector.empty() << std::endl;

	ft::vector<int>::reverse_iterator rit1 = ft_vector.rbegin();
	ft::vector<int>::reverse_iterator rite1 = ft_vector.rend();
	for (; rit1 < rite1; rit1++)
		std::cout << "ft reverse_iterator test " << *rit1 << "\n";


	std::vector<int>::reverse_iterator rit2 = std_vector.rbegin();
	std::vector<int>::reverse_iterator rite2 = std_vector.rend();
	for (; rit2 < rite2; rit2++)
		std::cout << "std reverse_iterator test " << *rit2 << "\n";

	return (0);
}