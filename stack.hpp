/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:33:12 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/01 18:53:27 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

namespace ft
{
	template <class T, class Container = std::vector<T> >
	class stack
	{
		public:
		
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;
		typedef			 Container						container_type;
		
		explicit stack(const Container& = Container()) {};
		~stack() {};

		// MEMBER FUNCTIONS

		reference	top() 						{ return (c.back()); }
		const_reference	top() const 			{ return (c.back()); }
		bool	empty() const 					{ return (c.empty()); }		
		size_type	size() const 				{ return (c.size()); }
		void	push(const value_type& value)	{ return (c.push_back(value)); }
		void	pop()							{ return (c.pop_back()); }	


		protected:
		
		Container c;

	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
	
	template <class T, class Container>
	bool operator<(const stack<T, Container>& x, const stack<T, Container>& y);
	
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator>(const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);
	
	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);
}