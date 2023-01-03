/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:58:07 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/13 20:08:13 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:

	vector() {};
	~vector() {};
	assign();
	at();
	back();
	const_iterator begin() const { return const_iterator(this->_vector); };
	capacity();
	//cbegin();
	//cend();
	clear();
	//crbegin();
	//crend();
	//data();
	//emplace();
	//emplace_back();
	empty();
	end();
	erase();
	front();
	get_allocator();
	insert();
	max_size();
	operator[]();
	vector & operator=(const vector &rhs);
	pop_back();
	push_back();
	rbegin();
	rend();
	reserve();
	resize();
	size();
	swap();

	private:
	
	T	_vector;
};