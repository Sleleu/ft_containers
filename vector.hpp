/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/06 21:34:02 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <limits>
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
		typedef T												value_type;
		typedef Allocator 										allocator_type;
		typedef size_t									        size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::random_access_iterator<value_type>			iterator;
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
//-------------------------------------------------------------------------------------------------


//------------------------ CONSTRUCTORS | DESTRUCTOR ----------------------------------------------

		/* 1 | default | Constructs an empty container with the given allocator alloc */
		explicit vector(const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _size(0), _capacity(0) { _vector = _alloc.allocate(_capacity); }
		/* 2 | fill | Constructs the container with count copies of elements with value */
		explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _size(n), _capacity(n)
		{
			_vector = _alloc.allocate(_capacity);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_vector[i] , value); // Constructs an element object on the location pointed by ptr
		} 

	//	template < class InputIt >
	//	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()); // Constructs the container with the contents of the range (first,last)
	//	vector(const vector& other); // Constructs the container with the copy of the contents of other
		~vector()
		{
			if (_size > 0)
			   for (size_type i = 0; i < this->_size; i++)
				   	this->_alloc.destroy(&_vector[i]);
			if (_capacity > 0)
			 this->_alloc.deallocate(this->_vector, this->capacity());
		} // Destructs the vector
//-------------------------------------------------------------------------------------------------


//--------------------------- MEMBER FUNCTIONS ----------------------------------------------------
		
		vector& operator=(const vector& other) { *this = other; return (*this); }
		allocator_type get_allocator() const { return (Allocator(_alloc)); }

		//-------------- ELEMENT ACCESS ------------------------------

		reference front() { return (reference(*this->begin())); }
		const_reference front() const { return (const_reference(*this->begin())); }
		reference back() { return (reference(*--this->end())); }
		const_reference back() const { return (const_reference(*--this->end())); }

		//------------------------------------------------------------

		//-------------- ITERATORS -----------------------------------

		iterator begin()              { return iterator(_vector); }
		const_iterator begin() const  { return const_iterator(_vector); }
		iterator end()                { return iterator(_vector + _size); }
		const_iterator end() const    { return const_iterator(_vector + _size); }
		
		reverse_iterator rbegin()             { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend()               { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const   { return const_reverse_iterator(begin()); }

		//------------------------------------------------------------

		//-------------- CAPACITY -----------------------------------
		bool empty() const { return _size == 0; }
		size_type size() const { return (_size); }	
		size_type max_size() const { return this->_alloc.max_size(); }
		void reserve(size_type new_cap)
		{
			pointer new_vector = _alloc.allocate(new_cap);

			if (new_cap > this->max_size())
				throw (std::length_error("vector reserve error\n"));
			if (new_cap > capacity())
			{
				for (size_type i = 0; i < this->_size; i++)
					_alloc.construct(&new_vector[i], this->_vector[i]);
				_alloc.deallocate(this->_vector, this->capacity());
				this->_vector = new_vector;	
				this->_capacity = new_cap;
			}
			else
				return ;
		}
		size_type capacity() const { return (_capacity); }

		//-----------------------------------------------------------

		//--------------- MODIFIERS ---------------------------------
		
		void push_back(const value_type& value)
		{ 
			if (this->size() == 0)
				reserve(10);
			if (this->size() == this->capacity())
					reserve(this->size() * 2);
			_alloc.construct(&back() + 1, value);
			_size++;
		}
		// void pop_back()
		// { // Removes the last element of the container
		// 	this->erase(this->end());
		// }
		iterator insert(iterator pos, const T& value)
		{
			size_type index = pos - this->begin();
			
			if (_size == _capacity)
				this->reserve(_size * 2); // realloc si on depasse la capacite
			for (size_type i = _size; i > index; i--)
				_vector[i] = _vector[i - 1];
			_vector[index] = value;
			this->_size++;
			return (this->begin() + index);	// prevoir une capacite minimale pour eviter les reallocations ?
		}

		// iterator insert(const_iterator pos, size_type count, const T& value);
		// template<class InputIt>
		// iterator insert(const_iterator pos, InputIt first, InputIt last);
		// iterator erase(iterator pos); // Removes the elements at pos
		// iterator erase(iterator first, iterator last); // Removes the elements in the range (first, last)

		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const T& u);
		// void clear();

		/*
					RESIZE()
			Resizes the container to contain count elements.
			If the current size is greater than count, the container is reduced to its first count elements.
			If the current size is less than count,
			1) additional default-inserted elements are appended
			2) additional copies of value are appended.
		*/
		void	resize(size_type count, value_type value = value_type())
		{
			if (count > this->size())
				insert(this->end(), count - this->size(), value);
			else if (count < this->size())
				erase(this->begin() + count, this->end());
			else
				return ;
		}

		// void swap(vector& other);
		
		//-----------------------------------------------------------
		
//-------------------------------------------------------------------------------------------------


		private:
		
		pointer         _vector;
		allocator_type  _alloc;
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