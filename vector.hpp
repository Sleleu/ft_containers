/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/10 17:47:56 by sleleu           ###   ########.fr       */
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

		/* 3 | range | Constructs the container with the contents of the range (first,last) */
		template < class InputIt >
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0) : _alloc(alloc)
		{
			size_type n = 0;
			InputIt ptr = first;
			
			for (; ptr < last; ptr++, n++);
			_size = n;
			_capacity = n;
			_vector = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++, first++)
				_alloc.construct(&_vector[i], *first);		
		}
		
		/* 4 | copy | Constructs the container with the copy of the contents of other */
		vector(const vector& other) : _alloc(other._alloc), _size(other._size) ,_capacity(other._size)
		{
			vector::const_iterator it = other.begin();

			_vector = _alloc.allocate(_capacity);
			for (size_type i = 0; it < other.end(); i++, it++)
				_alloc.construct(&_vector[i], *it);
		}
		~vector()
		{
			if (_size > 0)
			   for (size_type i = 0; i < this->_size; i++)
				   	this->_alloc.destroy(&_vector[i]);
			//if (_capacity > 0) // to fix leak on operator=
				this->_alloc.deallocate(this->_vector, this->capacity());
		} // Destructs the vector
//-------------------------------------------------------------------------------------------------


//--------------------------- MEMBER FUNCTIONS ----------------------------------------------------


		/*
				OPERATOR=()
			Assigns new contents to the container, replacing its current contents,
			and modifying its size accordingly.
			
			Copies all the elements from x into the container.
			The container preserves its current allocator, which is used to allocate storage in
			case of reallocation.
			Any elements held in the container before the call are either assigned to or destroyed.
		*/
		vector& operator=(const vector& other)
		{
			if (this == &other)
				return (*this);
			assign(other.begin(), other.end());
			return (*this);
		}
		allocator_type get_allocator() const { return (Allocator(_alloc)); }

		//-------------- ELEMENT ACCESS ------------------------------

		reference operator[](size_type pos)             { return (_vector[pos]);                    }
		const_reference operator[](size_type pos) const { return (_vector[pos]);                    }
		reference front()                               { return (reference(*this->begin()));       }
		const_reference front() const                   { return (const_reference(*this->begin())); }
		reference back()                                { return (reference(*--this->end()));       }
		const_reference back() const                    { return (const_reference(*--this->end())); }
		reference at(size_type pos)						
		{
			if (!(pos < size()))
				throw (std::out_of_range("vector at() error\n"));
			else
				return (_vector[pos]);		
		}
		const_reference at(size_type pos) const
		{
			if (!(pos < size()))
				throw (std::out_of_range("vector at() error\n"));
			else
				return (_vector[pos]);	
		}

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
		bool empty() const
		{
			if (_size == 0)
				return (true);
			return (false);
		}
		size_type size() const { return (_size); }	
		size_type max_size() const { return this->_alloc.max_size(); }

		/*
					RESERVE()
			Requests that the vector capacity be at least enough to contain n elements.

			If n is greater than the current vector capacity, the function causes the container to reallocate
			its storage increasing its capacity to n (or greater).
			In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.

			This function has no effect on the vector size and cannot alter its elements.
		*/
		void reserve(size_type new_cap)
		{
			if (new_cap > this->max_size())
				throw (std::length_error("vector::reserve"));
			else if (new_cap > this->capacity())
			{
				pointer new_vector;
			
				new_vector = _alloc.allocate(new_cap);
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
			if (this->capacity() == 0)
				reserve(1);
			else if (this->size() == this->capacity())
					reserve(this->size() * 2);
			_alloc.construct(&back() + 1, value);
			_size++;
		}
		
		void pop_back() // Removes the last element of the container
		{
			this->erase(this->end() - 1);
		}

		/*
					INSERT()
		The vector is extended by inserting new elements before the element at the specified position,
		effectively increasing the container size by the number of elements inserted.

		This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size
		surpasses the current vector capacity.
		*/
		// 1 | inserts value before pos
		iterator insert(iterator pos, const T& value)
		{
			size_type i = 0;

			for (; begin() + i < pos; i++); // incrementer i jusqu'a pos
			if (_size == _capacity)
				reserve(_size * 2); // si reserve, les pointeurs sont invalides donc recuperer la bonne pos
			iterator new_pos = begin() + i;
			i = _size; // affecter i a la fin
			for (; begin() + i > new_pos; i--)
				this->_alloc.construct(&_vector[i], _vector[i - 1]); // deplacer les elements vers la droite
			this->_alloc.construct(&_vector[i], value); // affecter la nouvelle valeur a l'index new_pos
			this->_size++;
			
			return (new_pos);
		}
		
		// 2 | inserts count copies of the value before pos.
		void insert(iterator pos, size_type count, const T& value)
		{	
			size_type i = 0;
							
			for (; begin() + i < pos; i++); // incrementer i jusqu'a pos
			if (_size + count + 1 >= _capacity) // ajout a supprimer si pas de fix de size test
			 	reserve(_size * 2);
			iterator new_pos = begin() + i;
			for (; count > 0; count--)
				new_pos = this->insert(new_pos, value); // recuperer l'iterateur ayant potentiellement change apres un reserve()
		}

		// 3 | inserts elements from range [first, last) before pos
		template<class InputIt>
		iterator insert(iterator pos, InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value>::type* = 0)
		{				
			size_type index = pos - this->begin();

			last--;
			for (; first - 1 < last; last--)
				pos = this->insert(pos, *last);
			return (this->begin() + index);
		}

		/*
					ERASE()
			Removes from the vector either a single element (position) or a range
			of elements ([first,last)).
			This effectively reduces the container size by the number of elements removed,
			which are destroyed.
			return value = Iterator following the last removed element.
		*/
		// 1 | Removes the elements at pos
		iterator erase(iterator pos)
		{
			size_type index = pos - this->begin();
			if (pos == this->end()) // If pos refers to the last element, then the end() iterator is returned
				return (this->end());
			for (size_type i = 0 ; begin() + i < this->end(); i++)
				if (begin() + i > pos) // on deplace vers la gauche quand i arrive a pos
					_vector[i - 1] = _vector[i];
			this->_size--;
			return (this->begin() + index);
		}
		// 2 | Removes the elements in the range (first, last)
		iterator erase(iterator first, iterator last)
		{
			size_type remove_dist = 0;
			size_type i = 0;
			size_type index;
			if (first == last) // If [first, last) is an empty range, then last is returned
				return (last);
			for (; begin() + i < first; i++); // placer i sur position du first
			index = i; // emplacement du erase
			for (; first + remove_dist < last; remove_dist++); // calculer l'ecart de distance a remove
			for (; first + i < this->end(); i++)
				_vector[i] = _vector[i + remove_dist]; // deplacement vers la gauche en prenant en compte l'ecart a retirer
			this->_size -= remove_dist;
			return (this->begin() + index);
		}

		/*
					ASSIGN()
		    Replaces the contents of the container.

			1) Replaces the contents with count copies of value value
			2) Replaces the contents with copies of those in the range [first, last).
			The function template argument InputIterator shall be an input iterator type that points to elements
			of a type from which value_type objects can be constructed.
		*/
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			this->clear();
			for (; first < last; first++)
				this->push_back(*first);		
		}
		void assign(size_type n, const T& u)
		{
			this->clear();
			for (; n > 0; n--)
				this->push_back(u);
		}

		/*
				CLEAR()
			Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		*/
		void clear()
		{
			if (_size > 0)
			{
			   for (size_type i = 0; i < this->_size; i++)
				   	this->_alloc.destroy(&_vector[i]);
				_size = 0;
			}
		}

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
			if (count > _capacity)
				reserve(count);
			if (count >= this->size())
				insert(this->end(), count - this->size(), value);
			if (count < this->size())
				erase(this->begin() + count, this->end() - 1);
			this->_size = count;
		}

		/*
					SWAP()
			Exchanges the content of the container by the content of x, which is another vector object of the
			same type. Sizes may differ.
		
			After the call to this member function, the elements in this container are those which were in x before
			the call, and the elements of x are those which were in this. All iterators, references and pointers
			remain valid for the swapped objects.
		*/
		void swap(vector& other)
		{
			pointer vector_tmp       = this->_vector;
			allocator_type alloc_tmp = this->_alloc;
			size_type size_tmp       = this->_size;
			size_type capacity_tmp   = this->_capacity;
			
			this->_vector            = other._vector;
			this->_alloc             = other._alloc;
			this->_size              = other._size;
			this->_capacity          = other._capacity;

			other._vector            = vector_tmp;
			other._alloc             = alloc_tmp;
			other._size              = size_tmp;
			other._capacity          = capacity_tmp;
		}
		
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
		bool operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (&lhs == &rhs); }
		template <class T, class Allocator>
		bool operator< (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (&lhs >  &rhs); }
		template <class T, class Allocator>
		bool operator> (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (&lhs <  &rhs); }
		template <class T, class Allocator>
		bool operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (&lhs != &rhs); }
		template <class T, class Allocator>
		bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (&lhs >= &rhs); }
		template <class T, class Allocator>
		bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)	{ return (&lhs <= &rhs); }

		template <class T, class Allocator>
		void	swap(vector<T, Allocator>& lhs, vector<T, Allocator>& rhs)
		{
			lhs.swap(rhs);
		}
//-------------------------------------------------------------------------------------------------

} // namespace

#endif