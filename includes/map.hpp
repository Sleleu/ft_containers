/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:49:14 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/11 12:32:02 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "std_implementation.hpp"

#ifndef MAP_HPP
# define MAP_HPP

							/*--------------------------*/
							/*           MAP            */
							/*--------------------------*/
/*
	A map is a kind of associative container that supports unique keys (contains at most one of each key value)
	and provides for fast retrieval of values of another type T based on the keys. Map supports bidirectional
	iterators.
	A map satisfies all of the requirements of a container and of a reversible container and of an associative container.
	A map also provides most operations for unique keys. This
	means that a map supports the a_uniq operations but not the a_eq operations. For a
	map<Key,T> the key_type is Key and the value_type is pair<const Key,T>. Descriptions
	are provided here only for operations on map that are not described in one of those tables or for operations
	where there is additional semantic information.
*/


namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public:

//------------------------------ MEMBER TYPES -----------------------------------------------------
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const Key, T>							value_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference				const_reference;
		typedef ft::bidirectional_iterator<value_type>			iterator;
		typedef ft::bidirectional_iterator<const value_type>	const_iterator;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
//-------------------------------------------------------------------------------------------------

//----------------------------- VALUE_COMPARE -----------------------------------------------------
	class value_compare : public binary_function<value_type,value_type,bool>
	{
		friend class map;
		
			protected:
		
				Compare comp;
				value_compare(Compare c) : comp(c) {}
		
			public:
		
				bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
	};
//-------------------------------------------------------------------------------------------------

//------------------------ CONSTRUCTORS | COPY | DESTRUCTOR ---------------------------------------
		
		// 1 | Constructs an empty map using the specified comparison object and allocator
		explicit map(const Compare& comp = Compare(), const Allocator& = Allocator()) {}
		
		// 2 | Constructs an empty map using the specified comparison object and allocator, and
		//     inserts elements from the range [first, last).
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator()) {}
		
		
		map(const map<Key,T,Compare,Allocator>& x) {}
		
		~map() {}
		
		map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x) {}
//-------------------------------------------------------------------------------------------------

//---------------------------- ITERATORS ----------------------------------------------------------

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
//-------------------------------------------------------------------------------------------------


//---------------------------- CAPACITY -----------------------------------------------------------
		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;
//-------------------------------------------------------------------------------------------------


//---------------------------- ELEMENT_ACCESS -----------------------------------------------------
		T& operator[](const key_type& x)
		{ 
			return ((*((insert(make_pair(x, T()))).first)).second);
		}
//-------------------------------------------------------------------------------------------------


//---------------------------- MODIFIERS ----------------------------------------------------------
		pair<iterator, bool> insert(const value_type& x);
		iterator	insert(iterator position, const value_type& x);
		template <class InputIterator>
		void		insert(InputIterator first, InputIterator last);
		
		void 		erase(iterator position);
		size_type	erase(const key_type& x);
		void		erase(iterator first, iterator last);
		
		void		swap(map<Key, T, Compare, Allocator>&);
		
		void		clear();
//-------------------------------------------------------------------------------------------------


//---------------------------- OBSERVER -----------------------------------------------------------
		key_compare		key_comp() const;
		value_compare	value_comp() const;
//-------------------------------------------------------------------------------------------------


//---------------------------- MAP OPERATIONS -----------------------------------------------------
		iterator find(const key_type& x);
		const_iterator find(const key_type& x) const;

		size_type count(const key_type& x) const;
		
		iterator lower_bound(const key_type& x);
		const_iterator lower_bound(const key_type& x) const;
		iterator upper_bound(const key_type& x);
		const_iterator upper_bound(const key_type& x) const;
		
		pair<iterator,iterator>
		equal_range(const key_type& x);
		pair<const_iterator,const_iterator>
		equal_range(const key_type& x) const;
//-------------------------------------------------------------------------------------------------

	}; // map

//---------------------------- NON-MEMBER TYPES ---------------------------------------------------
		template <class Key, class T, class Compare, class Allocator>
		bool operator==(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
		template <class Key, class T, class Compare, class Allocator>
		bool operator< (const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
		template <class Key, class T, class Compare, class Allocator>
		bool operator!=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
		template <class Key, class T, class Compare, class Allocator>
		bool operator> (const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
		template <class Key, class T, class Compare, class Allocator>
		bool operator>=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
		template <class Key, class T, class Compare, class Allocator>
		bool operator<=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
//-------------------------------------------------------------------------------------------------

//---------------------------- SPECIALIZED ALGORITHMS ---------------------------------------------
		template <class Key, class T, class Compare, class Allocator>
		void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y) { x.swap(y); }
//-------------------------------------------------------------------------------------------------

} // namespace

#endif