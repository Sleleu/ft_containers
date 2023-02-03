/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:46:20 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/03 17:03:04 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <memory>
#include "iterator.hpp"

int main(void)
{
	ft::vector<int> ft_vector(4, 12);
	ft::vector<int>::iterator ft_it = ft_vector.begin();
	std::cout << *ft_it << std::endl;

	std::vector<int> std_vector(4, 10);
	std::vector<int>::iterator std_it = std_vector.begin();
	std::cout << *std_it << std::endl;

	return (0);
}