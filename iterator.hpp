/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:32 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/02 17:28:12 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std_implementation.hpp"
#include <cstddef>

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

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
//-------------------------- MEMBER TYPES------------------------------------------------		
		typedef Category           iterator_category;
		typedef T                  value_type;
		typedef Distance           difference_type;
		typedef Pointer            pointer;
		typedef Reference          reference;
//---------------------------------------------------------------------------------------		
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

		reverse_iterator() {};
		explicit reverse_iterator( iterator_type x ) {};
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ) {};

//-------------------------- MEMBER FUNCTIONS -------------------------------------------
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other) { return (*this); }
		reference operator*() const { Iterator tmp = current; return (*--tmp); }	
		pointer operator->() const { return &(this->operator*()); }
		reverse_iterator& operator++() { --current; return (*this); }
		reverse_iterator& operator--() { ++current; return (*this); }
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--current;
			return (tmp);  }
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++current;
			return (tmp);  }	
		reverse_iterator& operator+=( difference_type n ) { current -= n; return (*this); }
		reverse_iterator& operator-=( difference_type n ) { current += n; return (*this); }
		reverse_iterator operator+( difference_type n ) { return (reverse_iterator(current - n)); }
		reverse_iterator operator-( difference_type n ) { return (reverse_iterator(current + n)); }
		reference operator[]( difference_type n ) const { return (current[-n-1]); }
//---------------------------------------------------------------------------------------


//------------------------- NON-MEMBER FUNCTIONS ----------------------------------------
		bool operator==(const ft::reverse_iterator<Iterator>& rhs)	{ return (this->c == rhs.c); }
		bool operator< (const ft::reverse_iterator<Iterator>& rhs)	{ return (this->c <  rhs.c); }
		bool operator> (const ft::reverse_iterator<Iterator>& rhs)	{ return (this->c >  rhs.c); }
		bool operator!=(const ft::reverse_iterator<Iterator>& rhs)	{ return (this->c != rhs.c); }
		bool operator<=(const ft::reverse_iterator<Iterator>& rhs)	{ return (this->c <= rhs.c); }
		bool operator>=(const ft::reverse_iterator<Iterator>& rhs)	{ return (this->c >= rhs.c); }	
//---------------------------------------------------------------------------------------	

		protected:

		Iterator current;
		
	};
}

#endif