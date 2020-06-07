//Autor: Lucas Frank Hollmann

#include <stdio.h> //Biblioteca para usar printf.
#include <stdlib.h> //Biblioteca para usar malloc.

struct tnode //Node structure, representing the elements of a tree.
{
	int valor;//Value stored in the element.
	
	struct tnode *left, *right; //Nodes to the right and left of the current element. (In the binary search tree, the left node has a lower value than the current node, while the right one stores a higher value).
	
};typedef struct tnode tnode;



class BinaryTree
{
	private:
		
		tnode *root; //The starting node of the tree.
		int size; //The tree's size.
		
	public:
	
		/* Class constructor, sets initial values to the variables root and size;
		 */
		BinaryTree()
		{
			root = NULL; //root is set to NULL, meaning the tree is empty.
			size = 0; 
		}
		
		/* Returns and prints the size of the tree.
		 * 
		 * print - boolean flag for printing or not the size of the tree.
		 * return - the size of the tree.
		 */
		int getSize(bool print)
		{
			if(print)
			{	
				printf("Current tree's size is: %d\n", size);
			}
			return size; //Can be used as an isEmpty function, as 0 has the boolean value of false.
		}
};
