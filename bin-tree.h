//Autor: Lucas Frank Hollmann

#include <stdio.h> //Library to use the printf function.
#include <stdlib.h> //Library to use the malloc function.

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
		
		
		
		/* Recursively finds the depth of the tree. 
		 * This function is private because it will only be called by 
		 * another member function, which is public.
		 * 
		 * curdepth - ponter to the variable that stores the current 
		 * 			  depth of the tree on the current path.
		 * depth - pointer to the variable that stores the depth of the tree.
		 * cur - current node, used to go through the tree.
		 */
		void getDepthR(int *curdepth, int *depth, tnode *cur)
		{
			if(root == NULL)
			{			/*If the root is NULL, ends the function 
						with depth = 0.*/
						
				*depth = 0;
				return;
			}
			if(cur == NULL) 
			{		/*If the current node is NULL, ends the function.
					Meaning it reached the higher depth for this path.*/
					printf("b");
				*curdepth = 0; //Resets the current path's depth.
				return;
			}
			
			if(cur == root)
			{		/*If the current node is the root (this boolean 
					expression compares the adress of both nodes), 
					initializes the value of depth.*/
				printf("a");
				*curdepth = 0;
				*depth = 0;
				
			}
			
			*curdepth = *curdepth+1; /*Increases the current depth as 
									  it just counted a valid node.*/
			printf("%d\n", *curdepth);
			if(curdepth > depth) 
			{					/*If the current depth is bigger than
								the tree's depth, updates tree's depth.*/
				*depth = *curdepth;
			}
			
			//Recursively calls itself for both sides of the current node.
			
			int temp = *curdepth;/*temp stores current depth before going
									to the left node, allowing to restore 
									the value for the current node before
									going to the right*/
									
			getDepthR(curdepth,depth,cur->left);
			
			*curdepth = temp;//Restores current node's depth.
			
			getDepthR(curdepth,depth,cur->right);
			
		}
		
		/* Recursively prints the whole tree (also it is a BFS function).
		 * This function is private because it will only be called by 
		 * another member function, which is public.
		 * 
		 * level - pointer to the variable that marks the current level on the tree.
		 * cur - current node, used to go through the tree.
		 * dir - direction of the current node in relation to it's parent.
		 * 		 shall be 'l' for left, 'r' for right and 'f' if the 
		 * 		 current node is the root.
		 */
		void printTreeR(int *level ,tnode *cur, char dir)
		{
			/*right this need to be a bfs so i'll do it later*/
			if(cur == NULL)
			{
				return;
			}
			
			int tabNum = getDepth(false); /*Number of tabs needed
			
			
			for(
		}
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
			return size; //Can be used as an is(not)Empty function, 
						 //as 0 has the boolean value of false.
		}
		
		/* Sets and calls the function that finds the depth of the tree.
		 *
		 * print - boolean flag to print the depth.
		 * return - the depth of the tree.
		 */
		int getDepth(bool print)
		{
			int curdepth, depth;/*Declaration for the variables for the
								  getDepthR function.*/

			getDepthR(&curdepth, &depth, root);/*Calls the function that 
											   finds the depth*/
											   
			if(print)//If print is true, show the depth on the screen.
			{
				printf("Tree's depth: %d\n", depth);
			}
			
			return depth;
		}
		
		/*	Calls the private member function printTreeR.
		 */ 
		void printTree()
		{
			int level = 0;/*Variable to keep track of the current level 
							on the tree in the printTreeR function.
							(represents current depth)*/
			
			printTreeR(&level, root, 'f');//Calls the function to print the tree.
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
				/*Could just return here so the following "else" wouldn't 
				be needed. But, this way, it seems to be more organized and readable.*/
			}
			else
			{
				tnode *temp =  root;//Temporary node to go through the tree.
				tnode *temp2;//Temporary node to store parent's node.
				
				while(temp!=NULL)
				{					/*While the current node isn't null, 
									  keep going ahead on the tree.*/
									  
					temp2 = temp;
					if(v < temp->value)
					{					/*If the value to be added is lower 
										 than the current, go to the left.*/
						temp = temp->left;
					}
					else if(v > temp->value)
					{						/*If the value to be added is 
											  bigger than the current, go 
										      to the right.*/
						temp = temp->right;
					}
					else
					{ /*If the value to be added is equal to the 
						current one, prints this information 
						and ends the function.*/
					
					
						printf("This value is already in the tree.\n");
						return;
					}
				} /*When temp reaches a NULL node, meaning it found a 
				valid slot to add the new node, the while loop ends.*/
				
				
				/*Adds the new node to the left or right of the last 
				  node on the correct path*/
				if(v < temp2->value)
				{
					temp2->left = newnode;
				}
				else if(v > temp2->value)
				{
					temp2->right = newnode;
				}

				size++; //Increases the size of the tree.
			}
		}

};

















