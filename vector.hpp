/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/02 17:56:54 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include "iterator.hpp"

#ifndef VECTOR_HPP
#define VECTOR_HPP

template < class T, class Allocator = std::allocator<T> >
class vector
{

	public:


//----------------------- MEMBER TYPES ------------------------------------------------------------
	typedef	T												value_type;
	typedef Allocator 										allocator_type;
	typedef std::size_t										size_type;
	typedef std::ptrdiff_t									difference_type;
	typedef value_type&										reference;
	typedef const value_type&								const_reference;
	typedef Allocator::pointer								pointer;
	typedef Allocator::const_pointer						const_pointer;
	typedef ft::random_access_iterator<value_type>			iterator;
	typedef ft::random_access_iterator<const value_type>	const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
//-------------------------------------------------------------------------------------------------


//------------------------ CONSTRUCTORS | DESTRUCTOR ----------------------------------------------
	vector(); // Constructs an empty container with a default-constructed allocator
	explicit vector( const Allocator& alloc ); // Constructs an empty container with the given allocator alloc
	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()); // Constructs the container with count copies of elements with value value
	template < class InputIt >
	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()); // Constructs the container with the contents of the range (first,last)
	vector(const vector& other); // Constructs the container with the copy of the contents of other
	~vector() {} // Destructs the vector
//-------------------------------------------------------------------------------------------------
	
	// MEMBER FUNCTIONS
	// assign();
	// at();
	// back();
	iterator begin()
	{
		return (this->_vector);
	}
	// capacity();

	// clear();

	// bool empty()
	// {
	// 	if (!this)
	// 		return (false);
	// 	return (true);
	// }
	// end();
	// erase();
	// front();
	// get_allocator();
	// insert();
	// max_size();
	// operator[]();
	// vector & operator=(const vector &rhs);
	// pop_back();
	
	// void push_back(const T &value)
	// {
	// 	if (this->size() < this->capacity())
	// 	{
	// 		// put the element at the end
	// 		this->size++;
	// 	}
	// 	else if (this->size() == this->capacity())
	// 	{
	// 		//realloc before, twice as large as the initial vector
	// 		// put the element at the end
	// 		this->_size++;
	// 	}
	// }
	
	// rbegin();
	// rend();
	// void reserve(size_type n)
	// {
	// 	if (n <= this->capacity())
	// 		this->_vector = allocator.allocate(n);
	// 	else
		
	// }
	// resize();
	// size_t size() const
	// {
	// 	return (std::distance(this->begin(), this->end()));
	// }
	// swap();

	private:
	
	T	_vector;
	size_t _size;
};

#endif