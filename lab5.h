#ifndef _LAB_5_H_
#define _LAB_5_H_

#include <iostream>
#include <cassert>
#include <map>
#include <cstdlib>
#include <list>
#include <math.h>
using namespace std;
#define nil 0

    template < typename Value >
    class BST {
        class Node { // binary tree node
            public:
                
                Node* left;
                
                Node* right;
                
                bool selected;
                
                Value value;
                
                Node( const Value v = Value() )
                
                : value(v), left(nil), right(nil){}
                
                Value& content() { return value; }
                
                bool isInternal() { return left != nil && right != nil; }
                
                bool isExternal() { return left != nil || right != nil; }
                
                bool isLeaf() { return left == nil && right == nil; }
                
                int height() 
                {
                    // returns the height of the subtree rooted at this node
                    // FILL IN**
                    if( this->left== nil && this-> right ==nil) return 0;
                    int left_height= 1+ this->left.height();
                    int right_height= 1+ this->left.height();
                    if(right_height > left_height ) return right_height;
                    else return left_height;
                }
                
                int size() 
                {
                    // returns the size of the subtree rooted at this node,
                    // FILL IN**
                    if(this == nil)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1 + this->left.size() + this->right.size();
                    }
                }
                
        }; // Node
        
        // const Node* nil; 
        // later nil will point to a sentinel node.
        
        Node* root;
        int count;
    
        public:
        int size() 
        {   
            // size of the overall tree.
            // FILL IN**
            //this is the number of total nodes.
            Node* temp = root;
            if(root == nil)
            {
                return 0;
            }
            else
            {
                return 1 + temp->left.size() + temp->right.size();
            }
        }
        
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) {
            // Print the node’s value.
            // FILL IN**
            cout << n->value << ' ';
        }
        bool search ( Value x ) 
        {
            // search for a Value in the BST and return true if it was found
            // FILL IN**
            Node* temp = root;
            while( temp != nil)
            {
                if( temp->value== x )
                {
                    return true;
                }
                else if(temp->value > x) 
                {
                    temp = temp->left;
                }
                else
                {
                    temp= temp->right;
                }
            }return false;
        }
        
        void preorder()const {
            // Traverse and print the tree one Value per line in preorder.
            // FILL IN**
            if(root==nil) return;
            Node* temp = root;
            cout << temp->value<< endl;
            if( temp->left != nil)
            {
                temp->left.preorder();
            }
            if( temp->right != nil)
            {
                temp->right.preorder();
            }
        }
        
        void postorder()const 
        {
            // Traverse and print the tree one Value per line in postorder
            // FILL IN**
            if (root==nil) return;
            Node* temp = root;
            if( temp->left != nil)
            {
                temp->left.postorder();
            }
            if( temp>right!= nil)
            {
                temp->right.postorder();
            }
            cout << temp->value<< endl;
        }
        
        void inorder()const 
        {
            // Traverse and print the tree one Value per line in inorder.
            // FILL IN**
            if(root==nil) return;
            Node* temp = root;
            if( temp->left != nil)
            {
                temp->left.inorder();
            }
            cout << temp->value<< endl;
            if( temp->right!= nil)
            {
                temp->right.inorder();
            }
        }
        
        Value& operator[] (int n) {
            // returns reference to the value field of the n-th Node.
            // FILL IN**
            if( n >= size() || n<0) exit(1);
            int position = 0;
            Value final;
            return bracket_helper(n, position, root, final);
            
        }
        
        Value& bracket_helper( int n, int& position, Node* temp, Value& final)
        {
            if(temp->left != nil)
            {
                bracket_helper(n, position, temp->left, final);
            }
            if( position == n)
            {
                final = temp->value;
            }
            ++position;
            if(temp->right != nil)
            {
                bracket_helper(n, position, temp->right, final);
            }
            return final;
        }
        
    
    void vertSum(int hd, map<int,int>& m)
    {
        int temp = 0;
        int sum = 0;
        verticalSum(root, hd, m, temp, sum);
        cout << m[hd];
    }
            
    void verticalSum(Node* n, int hd, map<int,int>& m, int temp, int &tot)
    {
        if(n == nil) return;
        if(hd == temp)
        {
            tot = tot + n->value;
            m[hd] = tot;
        }
            
        verticalSum(n->right, hd, m, temp + 1, tot);
        verticalSum(n->left, hd, m, temp - 1, tot);
    }
    
    void makeAllFalse( Node* n)
    {
        if ( n == nil)
        n.selected = false;
        makeAllFalse( n->left);
        makeAllFalse( n->right);
    }
    
    bool makeCover( Node* n, bool cover)
    {
        if(n->left!=nil && n->right!=nil)
        {
            return n->selected;
        }
        n->selected = !cover;
        if(n->left != nil)
        {
            if(!makeCover(n->left, !cover))
            {
                n->selected = true;
            }
        }
        if(n->right != nil)
        {
            if(!makeCover(n->right, !cover))
            {
                n->selected = true;
            }
        }return n->selected;
    }
    
    void minCover()
    {
        if(root-> left != nil)
        {
            if(root->left->selected == true)
            {
                makeAllFalse(root);
            }
        }
        makeCover(root, true);
    }
    
    void cover(Node* n, int& num)
    {
        if(n->left != nil)
        {
            cover(n->left, num);
        }
        if(n->selected == true)
        {
            cout << n->value << ' ';
            ++num;
        }
        if(n->right != nil)
        {
            cover( n->right, num);
        }return;
    }
    
    void displayMinCover()
    {
        int nodes =0;
        cout << "Part 1\n";
        cover(root, nodes);
        cout << endl << nodes << endl;
    }
    
    void SumPath( int n)
    {
        cout << "Part 2\n";
        int buffer[100];
        if(!findSumPath(root, n, buffer)) cout << "0\n";
        return;
    }
    
    void findSumPath( Node*n,int num, int buffer[] )
    {
        buffer[root->height() - n->height()] = n->value;
        cout << n->value << ' ' << root->height() - n->height() << endl;
        int sum =0;
        for ( int i =0; i<= root->height(); ++i)
        {
            sum = sum+buffer[i];
        }
        if( sum == num)
        {
            for( int i = 0 ;    i <= root->height(); ++i)
            {
                cout << buffer[i] << ' ';
            }
            cout << endl;
        }
        if( n ->left != nil) findSumPath(n->left, num, buffer);
        if( n ->right != nil) findSumPath(n->right, num, buffer);
        return;
    }
    
    
    
        BST() : count(0), root(nil) {}
        
        void insert( Value X ) { 
            root = insert( X, root ); 
            
        }
        
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ...
        if ( T == nil ) {
            T = new Node( X ); // the only place that T gets updated.
            } 
            else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } 
            else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } 
            else {
                T->value = X;
            }
    
        // later, rebalancing code will be installed here
        return T;
        }
    
    
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) 
        {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
    
    
            if ( T != nil ) {
                if ( X > T->value ) {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value ) {
                    T->left = remove( X, T->left );
                } 
                else {// X == T->value
                    if ( T->right != nil ) {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } 
                    else if ( T->left != nil ) {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                    else { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
        // later, rebalancing code will be installed here
        return T;
        }
        
        void okay( ) { okay( root ); }
        
        void okay( Node* T ) {
        
            // diagnostic code can be installed here
            return;
        }
    
        
    }; // BST

#endif
