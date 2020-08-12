#pragma once
///Structure for a node in the tree
///
///This contains details about the node, its children, its x and y coordinate in the tree and thread status
typedef struct node
{
	int info;									// Data inside the node
	struct node *left, *right, *L, *R;			// pointers to left and right sons
	int x_coord, y_coord;						// x,y coordinates of the node
	int offset;									// distance of node from each son
	bool thread=false;								// Tells which nodes to be threaded
}record;


///Structure to keep track of leftmost and rightmost node.
///
///If the current subtree is a single node, then that node is
///trivially both the leftmost and rightmost node on the lowest
///level of the subtree; otherwise, its extreme descendants can
///easily be chosen from among the extreme descendants of its
///sons.
typedef struct node2							//to keep track of the leftmost and rightmost node on the lowest level of subtree
{
	record *addr;								// address of the extreme node
	int lev;									// tree level
	int off;									// offset from root of subtree
}extreme;


///FUNCTION FOR CREATING A NEW NODE.
///
///Creates a new node by assigning "new" memory to a record node and initializing it with appropraite info and children details.
/// @param data Value to be stored in the info part of the node
/// @param height Level of the newly added node
record* newNode(int data, int height);

///FUNCTION TO INSERT A NODE TO THE BINARY TREE.
///
///Uses a Queue to perform Level Order traversal until it finds an empty place to add the node.
///@param temp Used for traversing through the tree
///@param data Value to be stored in the info part of the node
///@returns Pointer to the new node
void insert(record* temp, int data);

///TO INPUT A USER GENERATED BINARY TREE.
///
///Takes input as the info and adds a new node to the tree until input is -1, upon which it breaks out of the current recursive call and proceeds to the next node location.
///@param head For initializing the custom input binary tree with a root node
///@param ht Height of the current node
///@param root To keep track of the original root node in the tree
///@returns Pointer to the root of the tree formed
record* input(record **head,int ht,record *root);


///TO FORM A COMPLETE BINARY TREE WITH VALUES 1-N.
///
///Uses for loop to iteratively add a new node to the binary tree at the appropriate position by invoking the newNode and insert functions.
///@param root To keep track of the root node in the tree
///@param n Value to be stored in the node
void FormTree(record **root,int n);



///PERFORMS AN INORDER TRAVERSAL OF THE TREE WHICH CALLS CIRCLE AND LINE DRAWING FUNCTIONS TO PRINT THE TREE.
///
///Prints circles and lines at the appropriate positions (calculated using the setup and petrify functions) using Bresenham's Midpoint Line and Circle Drawing algorithm
///@param temp To traverse the binary tree using recursion
void inorder(record* temp);

///IMPLEMENTS ALGORITHM TR, ASSIGNING RELATIVE POSITIONINGS TO ALL NODES IN THE TREE POINTED TO BY PARAMETER T.
///
///Works by calculating the x offset of each node from the root, takes into account the contours to be followed for spacing between two nodes and calculates
///separation between two nodes based on the minsep value.
///@param T Root of the subtree
///@param level Current overall level
///@param rmost Extreme rightmost descendant
///@param lmost Extreme leftmost descendant
void setup(record* T, int level, extreme &rmost, extreme &lmost);

/// THIS FUNCTION PERFORMS A PREORDER TRAVERSAL OF THE TREE CONVERTING THE RELATIVE OFFSETS TO ABSOLUTE COORDINATES.
///
/// This computes the final position of each node, and erases all the threads as well.
///@param T Root of the subtree
///@param xpos Stores the calculated x position of each node in the tree
void Petrify(record *T, int xpos);

