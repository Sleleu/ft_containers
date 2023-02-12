/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:38:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/12 16:33:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define BLACK 0
#define RED 1
#define LEAF NULL

template <class T>
typedef struct s_node
{

	// public:

	// 	typedef T		value_type;

	// 	// default constructor
	// 	node() : left(NULL), right(NULL), parent(NULL), color(BLACK), key(0) {}
		
	// 	// assign constructor
	// 	node(value_type k) : left(NULL), right(NULL), parent(NULL), color(BLACK), key(k) {}



	// private:
	
		class node*	left;
		class node*	right;
		class node*	parent;
		int color; // RED or BLACK
		value_type	key;	
} node;

class RBTree
{
	class node;

	public:
	
//--------------------------- CONSTRUCTOR | DESTRUCTOR ----------------------------------
	RBTree() : root(); {}
//--------------------------- MEMBER FUNCTIONS ------------------------------------------

//--------------------------- ELEMENT ACCESS --------------------------------------------
		node* parent(node* n)
		{
			return n->parent; // retournera NULL si pas de racine
		}
		
		node* grandparent(node* n)
		{
			node* p = parent(n); // ptr sur parent de n
			if (p == NULL) // si n n'a pas de parent c'est la racine
				return (NULL);
			return parent(p);
		}
		
		node* brother(node* n)
		{
			node* p = parent(n);
			if (p == NULL)
				return NULL; // si n n'a pas de parent c'est la racine
			if (n == p->left) // check si n est du cote gauche ou droit du parent
				return p->right; // retourne le droit si n est du cote gauche
			else
				return (p->left);
		}
		
		node* uncle(node* n)
		{
			node* p = parent(n);
			node* g = grandparent(n);
			if (g == NULL) // check si un grandparent existe, sinon il y a pas d'oncle
				return (NULL);
			return (brother(p)); // retourne le frere du pere
		}
//---------------------------------------------------------------------------------------

//--------------------------- MODIFIERS -------------------------------------------------

/*
     		   P                         P
 			  /                         /  
			 x      ROTATE_LEFT()      y
			/ \     ============>     / \
		   O   \                     /   O 
				y                   x  
			   / \	               / \  
			  O   O               O   O
*/
		void	rotate_left(node *x)
		{
			struct node* y = x->right; // ptr sur node y pointe sur le fils droit de x
			
			x->right = y->left; // fils droit de x devient le fils gauche de y | ou x droit pointe sur y gauche
			if (y->left != LEAF) // si y gauche n'est pas une feuille
				y->left->parent = x; // le pointeur du parent de y gauche devient x (x prend la place de y dans l'arbre)
			y->parent = x->parent; // le parent de x devient le parent de y (on fait remonter y a la place de x dans l'arbre)
			if (x->parent == NULL) // si x n'a pas de parent, il est la racine
				x = y; // y devient donc la racine
			else if (x == x->parent->left) // si x etait a la gauche du parent
				x->parent->left = y; // on attache y a la gauche de l'ancien parent de x
			else if (x == x->parent->right) // si x etait a la droite du parent
				x->parent->right = y; // on attache y a la gauche de l'ancien parent de y
			
			// x est attache a gauche de y
			y->left = x; // x devient le fils gauche de y
			x->parent = y; // y devient le parent de x
		}

		void rotate_right()
		{
			struct node* y = x->left; // ptr sur node y pointe sur le fils gauche de x

			x->left = y->right; // fils gauche de x devient le fils droit de y
			if (y->right != LEAF) // si y droit n'est pas une feuille
				y->right->parent = x; // le ptr du parent de y droit devient x (x prend la place de y dans l'arbre)
			y->parent = x->parent; // le parent de x devient le parent de y (on descend y a la place de x dans l'arbre)
			if (x->parent == NULL) // si x n'a pas de parent, il est la racine
				x = y; // y devient donc la racine
			else if (x == x->parent->right) // si x etait le fils droit du parent
				x->parent->right = y; // on attache y a la droite de l'ancien parent de x
			else if (x == x->parent->left) // si x etait le fils gauche du parent
				x->parent->left = y; // on attache y a la gauche de l'ancien parent de x

			// x est attache a droite de y
			y->right = x; // x devient le fils droit de y
			x->parent = y; // y devient le parent de x
		}
//---------------------------------------------------------------------------------------

	void	insert(const value_type& n);
	

	private:
	
	node* root; // NULL if empty
	
};