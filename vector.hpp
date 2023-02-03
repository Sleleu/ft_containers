/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/03 13:59:53 by sleleu           ###   ########.fr       */
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
		typedef size_t									        size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef typename ft::random_access_iterator<value_type>			iterator;
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
//-------------------------------------------------------------------------------------------------


//------------------------ CONSTRUCTORS | DESTRUCTOR ----------------------------------------------
		vector() { } // Constructs an empty container with a default-constructed allocator
		explicit vector( const Allocator& alloc ); // Constructs an empty container with the given allocator alloc
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()); // Constructs the container with count copies of elements with value value
		template < class InputIt >
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()); // Constructs the container with the contents of the range (first,last)
		vector(const vector& other); // Constructs the container with the copy of the contents of other
		~vector() {} // Destructs the vector
//-------------------------------------------------------------------------------------------------


//--------------------------- MEMBER FUNCTIONS ----------------------------------------------------
		
		vector& operator=(const vector& other) { *this = other; return (*this); }
		allocator_type get_allocator() const { return (Allocator(_allocator)); }

		//-------------- ITERATORS -----------------------------------

		iterator begin()              { return iterator(_vector); }
		const_iterator begin() const  { return const_iterator(_vector); }
		iterator end()                { return iterator(_vector + _size); }
		const_iterator end() const    { return const_iterator(_vector + _size); }
		
		reverse_iterator rbegin()             { return reverse_iterator(_vector + _size - 1); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_vector + _size - 1); }
		reverse_iterator rend()               { return reverse_iterator(_vector - 1); }
		const_reverse_iterator rend() const   { return const_reverse_iterator(_vector - 1); }

		//------------------------------------------------------------

		//-------------- CAPACITY -----------------------------------
		bool empty() const { return _size == 0; }
		size_type size() const { return (_size); }
		//size_type max_size() const;
		//void reserve(size_type new_cap);
		size_type capacity() const { return (_capacity); }
		//-----------------------------------------------------------

		//--------------- MODIFIERS ---------------------------------
		
		// void push_back(const T& value);
		// void pop_back(); // Removes the last element of the container
		// iterator insert(const_iterator pos, const T& value);
		// iterator insert(const_iterator pos, size_type count, const T& value);
		// template<class InputIt>
		// iterator insert(const_iterator pos, InputIt first, InputIt last);
		// iterator erase(iterator pos); // Removes the elements at pos
		// iterator erase(iterator first, iterator last); // Removes the elements in the range (first, last)
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const T& u);
		// void clear();
		// void swap(vector& other);
		
		//-----------------------------------------------------------
		
//-------------------------------------------------------------------------------------------------



		// iterator begin()
		// {
		// 	return (this->_vector);
		// }


		private:
		
		pointer         _vector;
		allocator_type  _allocator;
		size_type		_size;
		size_type		_capacity;

	}; // vector

//--------------------------- NON-MEMBER FUNCTIONS ------------------------------------------------
		template <class Allocator> class vector< bool, Allocator>;
		template <class T, class Allocator>
		bool operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (lhs == rhs); }
		template <class T, class Allocator>
		bool operator< (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (lhs <  rhs); }
		template <class T, class Allocator>
		bool operator> (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (lhs >  rhs); }
		template <class T, class Allocator>
		bool operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (lhs != rhs); }
		template <class T, class Allocator>
		bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (lhs <= rhs); }
		template <class T, class Allocator>
		bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (lhs >= rhs); }
//-------------------------------------------------------------------------------------------------

} // namespace

#endif