/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/09 18:46:06 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>
# include <string>
# include <sstream>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace ft;

namespace ft
{
	std::string	to_string(size_t n)
	{
		std::stringstream tmp;

		tmp << n;

		return tmp.str();
	}
}

int main()
{
	vector<std::string> JOHN;
	vector<std::string> BOB(5, "Hello");
	std::cout << "BOB(5, 8) : ";
	for (size_t i = 0; i < BOB.size(); i++)
		std::cout << BOB[i] << ' ';
	std::cout << '\n';
	vector<std::string> MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;


	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, "juste some random string");
	/*
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 5;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 83;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	/*
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2) << '\n';
		std::cout << MIKE.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n";
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	BOB.assign(42, "James BOND");

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	vector<std::string>	assign_range;
	assign_range.assign(8, "Covfefe");
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(41) : " << BOB.at(41) << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	BOB.push_back("My name is Bond");
	std::cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	vector<std::string>	insert_in_me;
	for (size_t i = 0; i < 15; i++)
		insert_in_me.push_back(ft::to_string(i) + " I love hbaudet\n");
	std::cout << "after push_back, before at\n";
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	vector<std::string>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, "Norminet");
	for (size_t i = 0; i < insert_in_me.size(); i++)
		std::cout << insert_in_me.at(i) << ' ';
	std::cout << '\n';

	vector<std::string>::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it : " << std::endl;
	std::cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator


	//INSERT
	std::cout << "\nINSERT\n";
	vector<std::string>	std_insert_in_me;
	for (size_t i = 0; i < 15; i++)
		std_insert_in_me.push_back(ft::to_string(i) + " 42 ");
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i) << ' ';
	std::cout << '\n';

	vector<std::string>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, "Why are you reading this!?");
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i) << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	vector<std::string>	insert_bis;
	for (size_t i = 0; i < 7; i++)
		insert_bis.push_back(ft::to_string(3 * i));
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i] << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i] << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	vector<std::string>	erase_in_me;
	for (size_t i = 0; i < 15; i++)
		erase_in_me.push_back(ft::to_string(2 * i));
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			std::cout << ' ';
		std::cout << erase_in_me.at(i) << ' ';
	}
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	BOB.swap(MIKE);
	/*
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	MIKE.swap(JOHN);
	/*
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	/*
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	/*
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		std::cout << MIKE[i] << ' ';
	std::cout << std::endl;
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	vector<std::string> MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	vector<std::string> real;
	real.assign(5, "foo");
	for (vector<std::string>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';

	std::cout << std::endl;
	return (0);
}
