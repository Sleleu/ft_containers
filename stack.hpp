/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:33:12 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/02 14:03:00 by sleleu           ###   ########.fr       */
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

//------------------------- DEFINITION --------------------------------------------------		
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;
		typedef			 Container						container_type;
//---------------------------------------------------------------------------------------


//-------------------------- MEMBER FUNCTIONS -------------------------------------------
		
		explicit stack(const Container& cont = Container()) { (void)cont;   }
		~stack()                                {  return;                  }
		
		reference   top()                       {  return (c.back());       }
		const_reference top() const             {  return (c.back());       }
		bool    empty() const                   {  return (c.empty());      }		
		size_type   size() const                {  return (c.size());       }
		void    push(const value_type& x)       {  return (c.push_back(x)); }
		void    pop()                           {  return (c.pop_back());   }	
//---------------------------------------------------------------------------------------


//---------------------------- OPERATORS ------------------------------------------------
		stack& operator=(const stack& rhs)
		{
			this->c = rhs.c;
			return (*this);
		}
		
		bool operator==(const stack<T, Container>& rhs)	{ return (this->c == rhs.c); }
		bool operator< (const stack<T, Container>& rhs)	{ return (this->c <  rhs.c); }
		bool operator> (const stack<T, Container>& rhs)	{ return (this->c >  rhs.c); }
		bool operator!=(const stack<T, Container>& rhs)	{ return (this->c != rhs.c); }
		bool operator<=(const stack<T, Container>& rhs)	{ return (this->c <= rhs.c); }
		bool operator>=(const stack<T, Container>& rhs)	{ return (this->c >= rhs.c); }	
//---------------------------------------------------------------------------------------


//---------------------------- MEMBER OBJECTS -------------------------------------------
		protected:
	
		Container c;
//---------------------------------------------------------------------------------------


	}; // class

} // namespace