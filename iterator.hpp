/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:32 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/03 14:17:53 by sleleu           ###   ########.fr       */
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
		typedef	typename	std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef	std::ptrdiff_t	difference_type;
		typedef	T	value_type;
		typedef	const T*	pointer;
		typedef	const T&	reference;
		typedef std::random_access_iterator_tag	iterator_category;
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
	class reverse_iterator
	{
		public:

		typedef          Iterator                                         iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::difference_type   difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type        value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer           pointer;
		typedef typename ft::iterator_traits<Iterator>::reference         reference;

		reverse_iterator() { this->current = NULL; };
		explicit reverse_iterator( iterator_type x ) { this->current = x; };
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ) { this->current = other.current; };

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other) { *this = other; return (*this);           }
		reference operator*() const                                    { Iterator tmp = current; return (*--tmp); }	
		pointer operator->() const                                     { return &(this->operator*());             }
		reverse_iterator& operator++()                                 { --current; return (*this);               }
		reverse_iterator& operator--()                                 { ++current; return (*this);               }
		reverse_iterator& operator+=( difference_type n )              { current -= n; return (*this);            }
		reverse_iterator& operator-=( difference_type n )              { current += n; return (*this);            }
		reverse_iterator operator+( difference_type n )                { return (reverse_iterator(current - n));  }
		reverse_iterator operator-( difference_type n )                { return (reverse_iterator(current + n));  }
		reference operator[]( difference_type n ) const                { return (current[-n-1]);                  }
		pointer base() const /* getter  */                             { return this->current;                    }
		reverse_iterator operator++(int) { // post incrementation
			reverse_iterator tmp = *this;
			--current;
			return (tmp);  }
		reverse_iterator operator--(int) { // post decrementation
			reverse_iterator tmp = *this;
			++current;
			return (tmp);  }	
//-------------------------------------------------------------------------------------------------

		protected:

		Iterator current;
		
	}; // reverse_iterator

//------------------------- NON-MEMBER FUNCTIONS --------------------------------------------------
		template <class first, class second>
		bool operator==(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() == rhs.base()); }
		template <class first, class second>
		bool operator< (const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() <  rhs.base()); }
		template <class first, class second>
		bool operator> (const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() >  rhs.base()); }
		template <class first, class second>
		bool operator!=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() != rhs.base()); }
		template <class first, class second>
		bool operator<=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() <= rhs.base()); }
		template <class first, class second>
		bool operator>=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() >= rhs.base()); }	
//-------------------------------------------------------------------------------------------------

		/*----------------------------*/
		/*   RANDOM_ACCESS_ITERATOR   */
		/*----------------------------*/

	template <typename T>
	class random_access_iterator
	{
		public:
			typedef typename iterator<random_access_iterator_tag, T>::iterator_category  iterator_category;
			typedef typename iterator<random_access_iterator_tag, T>::value_type         value_type;
			typedef typename iterator<random_access_iterator_tag, T>::difference_type    difference_type;
			typedef typename iterator<random_access_iterator_tag, T>::pointer            pointer;
			typedef typename iterator<random_access_iterator_tag, T>::reference          reference;

		random_access_iterator() { this->ptr = NULL; };
		random_access_iterator(const random_access_iterator& src) { *this = src; }
		random_access_iterator(const pointer src_ptr) { this->current = src_ptr; }
		~random_access_iterator() {}

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		random_access_iterator& operator=( const random_access_iterator<U>& other) { *this = other; return (*this); }
		reference operator*() const                              { pointer tmp = current; return (*++tmp); }	
		pointer operator->() const                               { return &(this->operator*());            }
		random_access_iterator& operator++()                     { ++current; return (*this);              }
		random_access_iterator& operator--()                     { --current; return (*this);              }
		random_access_iterator& operator+=( difference_type n )  { current += n; return (*this);           }
		random_access_iterator& operator-=( difference_type n )  { current -= n; return (*this);           }
		random_access_iterator operator+( difference_type n )    { return (random_access_iterator(current + n)); }
		random_access_iterator operator-( difference_type n )    { return (random_access_iterator(current - n)); }
		reference operator[]( difference_type n ) const          { return (current[-n-1]);                 }
		pointer base() const /* getter  */                       { return this->current;                   }
		random_access_iterator operator++(int) { // post incrementation
			random_access_iterator tmp = *this;
			++current;
			return (tmp);  }
		random_access_iterator operator--(int) { // post decrementation
			random_access_iterator tmp = *this;
			--current;
			return (tmp);  }	
//-------------------------------------------------------------------------------------------------
		protected:
			pointer current;
	}; // random_access_iterator

//------------------------- NON-MEMBER FUNCTIONS --------------------------------------------------
	template <typename first, typename second>
	bool operator==(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() == rhs.base()); }
	template <typename first, typename second>
	bool operator!=(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() != rhs.base()); }
	template <typename first, typename second>
	bool operator< (const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() < rhs.base()); }
	template <typename first, typename second>
	bool operator> (const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() > rhs.base()); }
	template <typename first, typename second>
	bool operator<=(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() <= rhs.base()); }
	template <typename first, typename second>
	bool operator>=(const random_access_iterator<first>& lhs, const random_access_iterator<second>& rhs)
	{ return (lhs.base() >= rhs.base()); }
//-------------------------------------------------------------------------------------------------

} // namespace

#endif