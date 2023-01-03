/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:33:12 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/13 18:52:51 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StackNode.hpp"

template <typename T>
class StackNode
{
	T data;
	StackNode *next;	
};

template <typename T>
class stack
{
	public:

	stack() {};
	~stack() {};
	
	void	push(T data);
	T		pop(void);
	T		peek(void);

	private:
	
	StackNode _stack;
};