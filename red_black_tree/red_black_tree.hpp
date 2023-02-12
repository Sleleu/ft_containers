/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:38:07 by sleleu            #+#    #+#             */
/*   Updated: 2023/02/12 20:10:12 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define BLACK 0
#define RED 1
#define LEAF NULL


							/*-------------------------------------*/
							/*           RED-BLACK TREE            */
							/*-------------------------------------*/

/*
                                           (B)
                                          /   \
                                         /     \
                                        /       \
                                      (R)       (R)
                                      / \       / \
                                     /   \     /   \
                                   (B)   (B) (B)   (B)
                                   / \     \       / \
                                 (R) (R)   (R)   (R) (R)

	A red-black tree is a balanced binary search tree with the following properties:

	1 | Every node is colored red or black.
	2 | Every leaf is a sentinel node, and is colored black.
	3 | If a node is red, then both its children are black.
	4 | Every simple path from a node to a descendant leaf contains the same number of black nodes.
	5 | The root is always black.
*/					
							
template <class T>
typedef struct s_node
{	
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

//--------------------------- ROTATION --------------------------------------------------

/*
               P                         P
              /                         /  
             x      ROTATE_LEFT()      y
            / \     ============>     / \
           O   \                     /   O 
                y                   x  
               / \                 / \  
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

//--------------------------- INSERTION -------------------------------------------------

		node*	insert(node* root, node* new_node)
		{
			recursive_insert(root, new_node); // on descend dans l'arbre et on insere le nouveau node
			repair_tree(new_node); // reparer l'arbre si les proprietes red/black sont violees
			root = new_node; // on descend la racine en bas de l'arbre pour retrouver la bonne racine apres repair_tree
			while (parent(root) != NULL) // tant qu'il existe un pointeur sur parent, on est pas a la racine
				root = parent(root); // on remonte dans les parents jusqu'a la nouvelle racine
			return root;
		}

		void	recursive_insert(node* root, node* new_node)
		{
			if (root != NULL && new_node->key < root->key) // si le new_node est < a la racine
			{
				if (root->left != LEAF) // si la racine a des fils
					recursive_insert(root->left, new_node); // on rappelle la fonction en utilisant le ptr du fils gauche en parametre de root	
			}
			else if (root != NULL) // si la racine n'est pas nulle
			{
				if (root->right != LEAF) // si la racine a des fils
					recursive_insert(root->right, new_node);  // on rappelle la fonction en utilisant le ptr du fils droit en parametre de root
			}
			else
				root->right = new_node;

			// insertion du new_node dans l'arbre
			new_node->parent = root; // la racine est descendu de l'arbre par les appels recursifs jusqu'au new_node
			new_node->left = LEAF;
			new_node->right = LEAF;
			new_node->color = RED;	// couleur rouge par defaut potentiellement modifiee apres reparation de l'arbre
		}

		void	repair_tree(node *new_node)
		{
			if (parent(new_node) == NULL) // new_node est la racine
				new_node->color = BLACK; // donc couleur black
			else if (parent(new_node)->color == BLACK) // arbre rouge-noir valide
				return ; // ne rien faire
			else if (uncle(new_node) != NULL && uncle(new_node)->color == RED) // le parent du new_node est rouge, arbre invalide
			{
				parent(new_node)->color = BLACK;
				uncle(new_node)->color = BLACK;

				node* g = grandparent(new_node); // ptr sur le grand parent de new_node 
				g->color = RED;
				repair_tree(g); // appel recursif en partant du grand parent afin de corriger de potentielles violations plus haut
			}
			else // si l'oncle est noir, rotations des nodes pour reequilibrer l'arbre
				rearrange_tree(new_node);
		}

		void	rearrange_tree(node* new_node)
		{
			node* p = parent(new_node);
			node* g = grandparent(new_node);
			
			if (new_node == g->left->right) // Si le new_node est le fils droit du fils gauche
			{
				rotate_left(p); // rotate le new_node pour le placer au dessus de p et en dessous de g
				new_node = new_node->left; // on redescend new_node a gauche
			}
			else if (new_node == g->right->left)
			{
				rotate_right(p);
				new_node = new_node->right;
			}
			
			p = parent(new_node);
			g = grandparent(new_node);
			
			if (new_node == p->left) // parent prend la place de grand parent
				rotate_right(g); // le grand parent prend la place de l'oncle
			else
				rotate_left(g);
			p->color = BLACK;
			g->color = RED;
		}

//---------------------------------------------------------------------------------------
	void	insert(const value_type& n);
	

	private:
	
	node* root; // NULL if empty
	
};