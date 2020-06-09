//Autor: Lucas Frank Hollmann

#include <stdio.h> //Biblioteca para usar printf.
#include <stdlib.h> //Biblioteca para usar malloc.

struct tnode //Node structure, representing the elements of a tree.
{
	int value;//Value stored in the element.
	
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
			return size; //Can be used as an is(not)Empty function, as 0 has the boolean value of false.
		}
		
		/*	Prints the content of the tree.
		 */ 
		void printTree()
		{
			
		}
		
		/* Inserts a value on the tree, doesn't add duplicated values.
		 * 
		 * v - value to be added.
		 */
		void insert(int v)
		{
			tnode *newnode = (tnode*)malloc(sizeof(tnode));//Node to add to the tree.
			
			newnode->value = v; //Sets default values for the new node.
			newnode->left = NULL;
			newnode->right = NULL;
			
			if(root == NULL) //If the root is NULL, insert the new node on the root.
			{
				root = newnode;
				size++; //Increases the tree's size.
				//Could just return here so the following "else" wouldn't be needed. But, this way, it seems to be more organized and readable.
			}
			else
			{
				tnode temp =  root;//Temporary node to go through the tree.
				
				while(temp!=NULL)//While the current node isn't null, keep going ahead on the tree.
				{
					if(v < temp->value)//If the value to be added is lower than the current, go to the left.
					{
						temp = temp->left;
					}
					else if(v > temp->value)//If the value to be added is bigger than the current, go to the right.
					{
						temp = temp->right;
					}
					else//If the value to be added is equal to the current one, prints this information and ends the function.
					{
						printf("This value is already in the tree.\n");
						return;
					}
				} //When temp reaches a NULL node, meaning it found a valid slot to add the new node, the while loop ends.
				
				temp = newnode; //Adds the new node to the position found.
				size++; //Increases the size of the tree.
			}
		}
};

















