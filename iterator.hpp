/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:32 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/06 11:29:28 by sleleu           ###   ########.fr       */
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
	class reverse_iterator :  public
										iterator <typename iterator_traits<Iterator>::iterator_category,
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
		reverse_iterator( const reverse_iterator<Iter>& other ) { this->_it = other._it; };

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other)
		{ 
			this->_it = other.base();
			return (*this);           
		}
		reference operator*() const                                    { iterator_type tmp = _it; return (*--tmp); }	
		pointer operator->() const                                     { return &(this->operator*());             }
		reverse_iterator& operator++()                                 { --_it; return (*this);               }
		reverse_iterator& operator--()                                 { ++_it; return (*this);               }
		reverse_iterator& operator+=( difference_type n )              { _it -= n; return (*this);            }
		reverse_iterator& operator-=( difference_type n )              { _it += n; return (*this);            }
		reverse_iterator operator+( difference_type n ) const          { return (reverse_iterator(_it - n));  }
		reverse_iterator operator-( difference_type n ) const          { return (reverse_iterator(_it + n));  }
		reference operator[]( difference_type n ) const                { return (_it[-n-1]);                  }
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
		{ return (lhs.base() <= rhs.base()); }
		template <class first, class second>
		bool operator>=(const reverse_iterator<first>& lhs ,const reverse_iterator<second>& rhs)
		{ return (lhs.base() >= rhs.base()); }

		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y) { return y._it - x._it; }

		template <class Iterator>
		reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x) { return reverse_iterator<Iterator> (x._it - n); }
		
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
		random_access_iterator(const random_access_iterator& src) { this->current = src.current; }
		random_access_iterator(const pointer src_ptr) { this->current = src_ptr; }
		~random_access_iterator() {}

//-------------------------- MEMBER FUNCTIONS -----------------------------------------------------
		template< class U >
		random_access_iterator& operator=( const random_access_iterator<U>& other)
		{
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
//-------------------------------------------------------------------------------------------------

} // namespace

#endif
