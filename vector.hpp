/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/02 20:10:43 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include "iterator.hpp"

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
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


//--------------------------- MEMBER FUNCTIONS ----------------------------------------------------
		
		//vector& operator=(const vector& other) {}
		allocator_type get_allocator() const { return (Allocator(_allocator)); }
		
		//-------------- CAPACITY -----------------------------------
		//bool empty() const;
		size_type size() const { return (this->_size); }
		//size_type max_size() const;
		//void reserve(size_type new_cap);
		size_type capacity() const { return (this->_capacity); }
		//-----------------------------------------------------------

		//--------------- MODIFIERS ---------------------------------
		
		// void clear();
		// void swap(vector& other);
		
		//-----------------------------------------------------------
		
//-------------------------------------------------------------------------------------------------



		// iterator begin()
		// {
		// 	return (this->_vector);
		// }


		private:
		
		allocator_type _allocator;
		size_type	_size;
		size_type	_capacity;

	}; // vector

//--------------------------- NON-MEMBER FUNCTIONS ------------------------------------------------

		vector& operator=(const vector& rhs)
		{
			this->c = rhs.c;
			return (*this);
		}
		
		template <class Allocator> class vector< bool, Allocator>;
		template <class Allocator>
		bool operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (this->c == rhs.c); }
		template <class Allocator>
		bool operator< (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (this->c <  rhs.c); }
		template <class Allocator>
		bool operator> (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (this->c >  rhs.c); }
		template <class Allocator>
		bool operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (this->c != rhs.c); }
		template <class Allocator>
		bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (this->c <= rhs.c); }
		template <class Allocator>
		bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (this->c >= rhs.c); }
//-------------------------------------------------------------------------------------------------

} // namespace

#endif