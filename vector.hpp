/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/01/03 13:03:38 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

#ifndef VECTOR_HPP
#define VECTOR_HPP

template < class T, class Alloc = std::allocator<T> >
class vector
{	
	public:

	// CONSTRUCTORS
	explicit vector(const allocator_type& Alloc = allocator_type()) {} // default
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {} // fill
	template <class InputIterator>	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {} // range
	vector(const vector& x) {} // copy

	// DESTRUCTOR
	~vector() {};
	
	// MEMBER FUNCTIONS
	assign();
	at();
	back();
	iterator begin() { return iterator(this->_vector); };
	capacity();

	clear();

	bool empty()
	{
		if (!this)
			return (false);
		return (true);
	}
	end();
	erase();
	front();
	get_allocator();
	insert();
	max_size();
	operator[]();
	vector & operator=(const vector &rhs);
	pop_back();
	
	void push_back(const T &value)
	{
		if (this->size() < this->capacity())
		{
			// put the element at the end
			this->size++;
		}
		else if (this->size() == this->capacity())
		{
			//realloc before, twice as large as the initial vector
			// put the element at the end
			this->_size++;
		}
	}
	
	rbegin();
	rend();
	void reserve(size_type n)
	{
		if (n <= this->capacity())
			this->_vector = allocator.allocate(n);
		else
		
	}
	resize();
	size_t size() const
	{
		return (std::distance(this->begin(), this->end()));
	}
	swap();

	private:
	
	T	_vector;
	size_t _size;
};

#endif