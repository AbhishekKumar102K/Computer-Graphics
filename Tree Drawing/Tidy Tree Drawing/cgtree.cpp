#pragma once
#include "cgtree.h"
#include "draw.h"
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<iostream>
#include<queue>
#define minsep 1
using namespace std;

int theight = 0,max_xcoord = 0;
int a,r,s,sx;
Draw d1;
// THIS FUNCTION IMPLEMENTS ALGORITHM TR, ASSIGNINE RELATIVE
//POSITIONINGS TO ALL NODES IN THE TREE POINTED TO BY PARAMETER T
void Cgtree::setup(record* T, int level, extreme &rmost, extreme &lmost)
{
	int cursep;							//  *SEPARATION ON CURRENT LEVEL
	int rootsep;						//  *CURRENT SEPARATION AT NODE T
	int loffsum,roffsum; 			    //  *OFPSET FROM L & R TO T

	record *L, *R;						//	*LEFT AND RIGHT SONS
	extreme lln,lrn,rln,rrn;			//	*lrn - RIGHTMOST NODE ON
										//	*LOWEST LEVEL OF LEFT SUBTREE
										//	*AND SO ON




	if(!T)								// * AVOID SELECTING AS EXTREME
	{
		lmost.lev = -1;
		rmost.lev = -1;
	}
	else
	{

		T->y_coord = level;
		L = T->left;				// *FOLLOWS CONTOUR OF LEFT SUBTREE
		R = T->right;				// *FOLLOWS CONTOUR OF RIGHT SUBTREE
		setup(L,level+1,lrn,lln);	// * POSITION SUBTREES RECURSIVELY
		setup(R,level+1,rrn,rln);
		if(!R && !L)				// *LEAF*
		{
			rmost.addr = T;			// * A LEAF IS BOTH THE LEFTMOST
			lmost.addr = T;			// * AND RIGHTMOST NODE ON THE
			rmost.lev = level;		// * LOWEST LEVEL OF THE SUBTREE
			lmost.lev = level;		// * CONSISTING OF ITSELF
			rmost.off = 0;
			lmost.off = 0;
			T->offset = 0;
		}
		else						// * T NOT A LEAF
		{
			 // *SET UP FOR SUBTREE PUSHING. PLACE ROOTS OF
			 // *SUBTREES MINIMUM DISTANCE APART.
			cursep = minsep;
			rootsep = minsep;
			loffsum = 0;
			roffsum = 0;

			 // *NOW CONSIDER EACH LEVEL IN TURN UNTIL ONE
			 // *SUBTREE IS EXHAUSTED, PUSHING THE SUBTREES
			 // *APART WHEN NECESSARY.

			while( L!=NULL && R!=NULL )
			{
				if(cursep < minsep)
				{
					rootsep = rootsep + (minsep-cursep);
					cursep = minsep;
				} //  *IF CURSEP < MINSEP
				// * ADVANCE L & R *
				if(L->right!=NULL)
				{
					loffsum = loffsum + L->offset;
					cursep = cursep - L->offset;
					L = L->right;
				}
				else
				{
					loffsum = loffsum - L->offset;
					cursep = cursep + L->offset;
					L = L->right;
				}
				if(R->left!=NULL)
				{
					roffsum = roffsum - R->offset;
					cursep = cursep - R->offset;
					R = R->left;
				}
				else
				{
					roffsum = roffsum + R->offset;
					cursep = cursep + R->offset;
					R = R->right;
				} // * ELSE

			} // *END OF WHILE

			// *SET THE OFFSET IN NODE T, AND INCLUDE IT IN
			// * ACCUMULATED OFFSETS FOR L AND R

			T->offset = (rootsep+1)/2;
			loffsum = loffsum - T->offset;
			roffsum = roffsum + T->offset;
			// * UPDATE EXTREME DESCENDANTS INFORMATIONS *

			if ((rln.lev > lln.lev) || (T->left==NULL))
			{
				lmost = rln;
				lmost.off = lmost.off + T->offset;
			}
			else
			{
				lmost = lln;
				lmost.off = lmost.off - T->offset;
			}
			if ((lrn.lev > rrn.lev) || (T->right==NULL))
			{
				rmost = lrn;
				rmost.off = rmost.off - T->offset;
			}
			else
			{
				rmost = rrn;
				rmost.off = rmost.off + T->offset;
			}
			// *IF SUBTREES OF T WERE OF UNEVEN HEIGHTS, CHECK
			// *TO SEE IF THREADING IS NECCESSARY. AT MOST ONE
			// *THREAD NEEDS TO BE INSERTED.
			if(L!=NULL && L!=T->left)
			{
				(rrn.addr)->thread = true;
				(rrn.addr)->offset = abs((rrn.off+T->offset)-loffsum);
				if((loffsum - T->offset) <= rrn.off)
				{
					(rrn.addr)->left = L;
				}
				else
				{
					(rrn.addr)->right = L;
				}
			}
			else if( R!=NULL && R!=T->right)
			{
				(lln.addr)->thread = true;
				(lln.addr)->offset = abs((lln.off+T->offset)-roffsum);
				if((roffsum + T->offset) >= lln.off)
				{
					(lln.addr)->right = R;
				}
				else
				{
					(lln.addr)->left = R;
				}
			}
		} 	// * END OF IF NOT LEAF *
	} 		// * END OF T != NIL *
}			// * END OF PROCEDURE*


// THIS FUNCTION PERFORMS A PREORDER TRAVERSAL OF THE TREE,
//	 CONVERTING THE RELATIVE OFFSETS TO ABSOLUTE COORDINATES.
void Cgtree::Petrify(record *T, int xpos)
{
	if(T!=NULL)
	{

		T->x_coord = xpos;
		max_xcoord = max(max_xcoord,abs(xpos));
		if(T->thread)               //T->thread me problem hai always shows yes
		{
			T->thread = false;
			T->right = NULL;		// * THREADED NODE MUST BE A LEAF
			T->left = NULL;
		}
		Petrify(T->left,xpos-T->offset);
		Petrify(T->right,xpos+T->offset);
	}


}
/**
	* TO INPUT A USER GENERATED BINARY TREE
 */
record* Cgtree::input(record **head,int ht, record *root)
{
    int x;
    cin>>x;
    if(x==-1)
    {
        *head=NULL;			// *IF X=-1 THEN THAT NODE WILL BE NULL
        return *head;		// *GO BACK
    }

    record *temp2;
    temp2=(record*)malloc(sizeof(record));		//* ALLOCATING THE DYNAMIC MEMEORY TO THE TEMPORARY VARIABLE POINTER temp2
	temp2->info=x;							//* ASSIGNING THE INFO =X
	temp2->y_coord = ht;					//* ASSIGNING Y COORDINATE OF THE temp
    *head=temp2;
    record* lef=(node*)malloc(sizeof(record));
    record* righ=(node*)malloc(sizeof(record));
    temp2->left=input(&lef,ht+1,root);		//* RECURSIVELY CALLING THE LEFT SON
    temp2->right=input(&righ,ht+1,root);	//* RECURSIVELY CALLING THE RIGHT SON
    temp2->thread = false;
    if(ht>theight)
    	theight = ht;
    if(temp2==root)
    {
        return 0;						// * EXIT CONDITION WHEN TEMP=ROOT WE HAVE RECEIVED ALL THE INPUTS
    }

    return *head;
}

//FUNCTION FOR CREATING A NEW NODE
record* Cgtree::newNode(int data, int height)
{
	if(height>theight)					//TO KEEP TRACK OF THE MAXIMUM HEIGHT OF THE TREE
		theight = height;
    record* temp = new record;
    temp->info = data; 					//ASSIGNING INFO OF NODE
    temp->left = temp->right = NULL; 	//SINCE temp IS A LEAF NODE FOR NOW
    temp->y_coord = height;				// ASSIGNING Y COORDINATE OF temp
    return temp;
}


//FUNCTION TO INSERT A NODE TO THE BINARY TREE
void Cgtree::insert_node(record *temp, int data)
{
	queue<record*> q;
    q.push(temp);

    // Do level order traversal until we find
    // an empty place.
    while (!q.empty()) {
        record* temp = q.front();
        q.pop();

        if (!temp->left) { 									//CHECK IF LEFT IS EMPTY
            temp->left = newNode(data,temp->y_coord+1);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) { 								//CHECK IF RIGHT IS EMPTY
            temp->right = newNode(data,temp->y_coord+1);
            break;
        } else
            q.push(temp->right);
    }
}


//INORDER TRAVERSAL OF THE TREE WHICH CALLS CIRCLE AND LINE DRAWING ALGO TO PRINT THE TREE
void Cgtree::inorder(record* temp)
{
    if (!temp)
        return;

    inorder(temp->left);

    if(theight==0)
	{
		d1.printCircle(0,-670,100);
		return;
	}

	s = 1300/theight;											// Y SCALING FACTOR
	sx = 1000/max_xcoord;										// X SCALING FACTOR
    r = min(sx/3,50);
    a = r/1.414;
    d1.printCircle((temp->x_coord)*sx,(temp->y_coord)*(-s),r);		//TO PRINT THE CIRCLE
    if(temp->right)
    	d1.line(a+(temp->x_coord)*sx,-a+(temp->y_coord)*(-s),-a+(temp->right->x_coord)*sx,a+(temp->right->y_coord)*(-s));		//TO PRINT LINE BETWEEN FATHER AND RIGHT SON
    if(temp->left)
    	d1.line(a+(temp->left->x_coord)*sx,a+(temp->left->y_coord)*(-s),-a+(temp->x_coord)*sx,-a+(temp->y_coord)*(-s));		//TO PRINT LINE BETWEEN FATHER AND LEFT SON
    inorder(temp->right);
}

//TO FORM A COMPLETE BINARY TREE WITH VALUES 1-N
void Cgtree::FormTree(record **root,int n)
{
	*root = newNode(1,0);
	for(int i=1;i<n;i++)
	{
		insert_node(*root,i+1);
	}
}


