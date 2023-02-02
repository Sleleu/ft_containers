/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:32 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/02 14:02:39 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define RERVERSE_ITERATOR_HPP 

namespace ft
{

	template <class Iterator>
	class reverse_iterator
	{
		public:
		
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;


//------------------------- NON-MEMBER FUNCTIONS ----------------------------------------
		bool operator==( const reverse_iterator<Iterator>& rhs) { return (this->current == rhs.current); }
		bool operator!=( const reverse_iterator<Iterator>& rhs) { return (this->current != rhs.current); }
		bool operator< ( const reverse_iterator<Iterator>& rhs) { return (this->current <  rhs.current); }
		bool operator> ( const reverse_iterator<Iterator>& rhs) { return (this->current >  rhs.current); }
		bool operator<=( const reverse_iterator<Iterator>& rhs) { return (this->current <= rhs.current); }
		bool operator>=( const reverse_iterator<Iterator>& rhs) { return (this->current >= rhs.current); }
//---------------------------------------------------------------------------------------		
		protected:

		Iterator current;
		
	};
}

#endif