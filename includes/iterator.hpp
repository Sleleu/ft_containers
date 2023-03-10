/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:32 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/11 12:45:40 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std_implementation.hpp"
#include <cstddef>

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{

		/*--------------------------*/
		/*      ITERATOR_TAG        */
		/*--------------------------*/
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

		/*--------------------------*/
		/*   FT::ITERATOR_TRAITS    */
		/*--------------------------*/
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::value_type	value_type;
		typedef typename	Iterator::pointer	pointer;
		typedef typename	Iterator::reference	reference;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef	std::ptrdiff_t	difference_type;
		typedef	T	value_type;
		typedef	T*	pointer;
		typedef	T&	reference;
		typedef	random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef	std::ptrdiff_t	difference_type;
		typedef	T	value_type;
		typedef	const T*	pointer;
		typedef	const T&	reference;
		typedef random_access_iterator_tag	iterator_category;
	};

		/*--------------------------*/
		/*   FT::ITERATOR           */
		/*--------------------------*/

	template <class Category,
	          class T,
			  class Distance = std::ptrdiff_t,
			  class Pointer = T*,
			  class Reference = T& >
	struct iterator
	{
//-------------------------- MEMBER TYPES----------------------------------------------------------		
		typedef Category           iterator_category;
		typedef T                  value_type;
		typedef Distance           difference_type;
		typedef Pointer            pointer;
		typedef Reference          reference;
//-------------------------------------------------------------------------------------------------	
	};


		/*--------------------------*/
		/*   FT::REVERSE_ITERATOR   */
		/*--------------------------*/

	template <class Iterator>
	class reverse_iterator :  public
										iterator < typename iterator_traits<Iterator>::iterator_category,
												   typename iterator_traits<Iterator>::value_type,
												   typename iterator_traits<Iterator>::difference_type,
												   typename iterator_traits<Iterator>::pointer,
												   typename iterator_traits<Iterator>::reference >
	{
		public:

		typedef          Iterator                                         iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::difference_type   difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type        value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer           pointer;
		typedef typename ft::iterator_traits<Iterator>::reference         reference;

		reverse_iterator() { this->_it = iterator_type(); };
		explicit reverse_iterator( iterator_type it ) { this->_it = it; };
		template< class Iter >
		reverse_iterator( const reverse_iterator<Iter>& other ) { this->_it = other.base(); };

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other)
		{ 
			this->_it = other.base();
			return (*this);           
		}
		reference operator*() const                                    { iterator_type tmp = base(); return (*--tmp); }	
		pointer operator->() const                                     { return &(this->operator*());             }
		reverse_iterator& operator++()                                 { --_it; return (*this);               }
		reverse_iterator& operator--()                                 { ++_it; return (*this);               }
		reverse_iterator& operator+=( difference_type n )              { _it -= n; return (*this);            }
		reverse_iterator& operator-=( difference_type n )              { _it += n; return (*this);            }
		reverse_iterator operator+( difference_type n ) const          { return (reverse_iterator(base() - n));  }
		reverse_iterator operator-( difference_type n ) const          { return (reverse_iterator(base() + n));  }
		reference operator[]( difference_type n ) const                { return (base()[-n-1]);                  }
		iterator_type base() const /* getter  */                       { return this->_it;                    }
		
		
		reverse_iterator operator++(int)
		{ // post-increment version
			reverse_iterator tmp = *this;
			--_it;
			return (tmp);
		}
		reverse_iterator operator--(int)
		{ // post-decrement version
			reverse_iterator tmp = *this;
			++_it;
			return (tmp); 
		}	
//-------------------------------------------------------------------------------------------------

		protected:

		iterator_type _it;
		
	}; // reverse_iterator

//------------------------- NON-MEMBER FUNCTIONS --------------------------------------------------
		template <class first, class second>
		bool operator==(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() == rhs.base()); }
		template <class first, class second>
		bool operator< (const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() >  rhs.base()); }
		template <class first, class second>
		bool operator> (const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() <  rhs.base()); }
		template <class first, class second>
		bool operator!=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() != rhs.base()); }
		template <class first, class second>
		bool operator<=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() >= rhs.base()); }
		template <class first, class second>
		bool operator>=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() <= rhs.base()); }

		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y) { return y.base() - x.base(); }

		template <class Iterator>
		reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x) { return reverse_iterator<Iterator> (x.base() - n); }
		
//-------------------------------------------------------------------------------------------------

		/*----------------------------*/
		/*   RANDOM_ACCESS_ITERATOR   */
		/*----------------------------*/

	template <typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename iterator<random_access_iterator_tag, T>::iterator_category  iterator_category;
			typedef typename iterator<random_access_iterator_tag, T>::value_type         value_type;
			typedef typename iterator<random_access_iterator_tag, T>::difference_type    difference_type;
			typedef typename iterator<random_access_iterator_tag, T>::pointer            pointer;
			typedef typename iterator<random_access_iterator_tag, T>::reference          reference;

		random_access_iterator() { this->current = NULL; };
		random_access_iterator(const random_access_iterator& src) { this->current = src.current; } // PB ICI ITERATOR SWAP
		random_access_iterator(const pointer src_ptr) { this->current = src_ptr; }
		virtual ~random_access_iterator() {}

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		random_access_iterator& operator=( const random_access_iterator<U>& other)
		{
			if (*this != other)
				this->current = other.current;
			return (*this);
		}
		reference operator*() const                              { return (*this->current); }	
		pointer operator->() const                               { return &(this->operator*());            }
		random_access_iterator& operator++()                     { ++current; return (*this);              }
		random_access_iterator& operator--()                     { --current; return (*this);              }
		random_access_iterator& operator+=( difference_type n )  { current += n; return (*this);           }
		random_access_iterator& operator-=( difference_type n )  { current -= n; return (*this);           }
		random_access_iterator operator+( difference_type n )    { return (random_access_iterator(current + n)); }
		random_access_iterator operator-( difference_type n )    { return (random_access_iterator(current - n)); }
		reference operator[]( difference_type n ) const          { return (current[n]);                 }
		pointer base() const /* getter */                        { return current;                         }
		random_access_iterator operator++(int) { // post incrementation
			random_access_iterator tmp = *this;
			++current;
			return (tmp);  }
		random_access_iterator operator--(int) { // post decrementation
			random_access_iterator tmp = *this;
			--current;
			return (tmp);  }
		operator random_access_iterator<const value_type>() const {
			return (random_access_iterator<const value_type>(this->current));
		}
//-------------------------------------------------------------------------------------------------
		protected:
			pointer current;
	}; // random_access_iterator

//------------------------- NON-MEMBER FUNCTIONS --------------------------------------------------
	template <class first, class second>
	bool operator==(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() == rhs.base()); }
	template <class first, class second>
	bool operator!=(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() != rhs.base()); }
	template <class first, class second>
	bool operator< (const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() < rhs.base()); }
	template <class first, class second>
	bool operator> (const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() > rhs.base()); }
	template <class first, class second>
	bool operator<=(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() <= rhs.base()); }
	template <class first, class second>
	bool operator>=(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() >= rhs.base()); }

	template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator>& x,
	const random_access_iterator<Iterator>& y)
	{ return x.base() - y.base(); }

	template <class Iterator>
	random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n,
	const random_access_iterator<Iterator>& x)
	{ return random_access_iterator<Iterator> (x.base() + n); }
		
//-------------------------------------------------------------------------------------------------

		/*----------------------------*/
		/*   BIDIRECTIONAL_ITERATOR  */
		/*----------------------------*/

/*
	Bidirectional iterators are iterators that can be used to access the sequence of elements in a range in
	both directions (towards the end and towards the beginning).
*/

	template <typename T>
	class bidirectional_iterator : public iterator<bidirectional_iterator_tag, T>
	{
		public:
			typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category  iterator_category;
			typedef typename iterator<bidirectional_iterator_tag, T>::value_type         value_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::difference_type    difference_type;
			typedef typename iterator<bidirectional_iterator_tag, T>::pointer            pointer;
			typedef typename iterator<bidirectional_iterator_tag, T>::reference          reference;

		bidirectional_iterator() { this->current = NULL; };
		bidirectional_iterator(const bidirectional_iterator& src) { this->current = src.current; }
		bidirectional_iterator(const pointer src_ptr) { this->current = src_ptr; }
		virtual ~bidirectional_iterator() {}

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		bidirectional_iterator& operator=( const bidirectional_iterator<U>& other)
		{
			if (*this != other)
				this->current = other.current;
			return (*this);
		}
		reference operator*() const                              { return (*this->current); }	
		pointer operator->() const                               { return &(this->operator*());            }
		bidirectional_iterator& operator++()                     { ++current; return (*this);              }
		bidirectional_iterator& operator--()                     { --current; return (*this);              }
		pointer base() const /* getter */                        { return current;                         }
		bidirectional_iterator operator++(int) { // post incrementation
			bidirectional_iterator tmp = *this;
			++current;
			return (tmp);  }
		bidirectional_iterator operator--(int) { // post decrementation
			bidirectional_iterator tmp = *this;
			--current;
			return (tmp);  }
		operator bidirectional_iterator<const value_type>() const {
			return (bidirectional_iterator<const value_type>(this->current));
		}
//-------------------------------------------------------------------------------------------------
		protected:
			pointer current;
	}; // bidirectional_iterator

//------------------------- NON-MEMBER FUNCTIONS --------------------------------------------------
	template <class first, class second>
	bool operator==(const bidirectional_iterator<first>& lhs, const bidirectional_iterator<second>& rhs)
	{ return (lhs.base() == rhs.base()); }
	template <class first, class second>
	bool operator!=(const bidirectional_iterator<first>& lhs, const bidirectional_iterator<second>& rhs)
	{ return (lhs.base() != rhs.base()); }
//-------------------------------------------------------------------------------------------------

} // namespace

#endif
