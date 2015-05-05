// John Gutierrez
// 861167274
// May 4, 2015

#ifndef _LAB_4_H_
#define _LAB_4_H_

#include <iostream>
#include <vector>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;


typedef pair<int,int> Entry;
class priority_queue {
    
    public:
        vector<Entry> entries;
        Entry& front() { return entries.back(); }
        void pop() { entries.pop_back(); }
        void push( Entry e ) 
        { 
            entries.push_back( e );
            
            for ( int i = entries.size()-1; i != 0; --i ) 
            {
                if ( entries[i].first + entries[i].second <= entries[i-1].first + entries[i-1].second) 
                {
                    if( entries[i].first + entries[i].second == entries[i-1].first + entries[i-1].second)
                    {
                        if( entries[i].first < entries[i-1].first) 
                        {
                            break;
                        }
                    }
                    break;
                }
                
                swap(entries[i], entries[i-1]);
            }
        }
};


void preOrder( int m, int n, int k )
{
    if( m+n >= k ) return;
    cout << m << ' ' << n << endl;
    preOrder( 2 * m - n , m ,   k );
    preOrder( 2 * m + n , m ,   k );
    preOrder( m + 2 * n , n ,   k );
}

void postOrder( int m, int n, int k )
{
    if( m+n >= k) return;
    postOrder( 2 * m - n , m ,   k );
    postOrder( 2 * m + n , m ,   k );
    postOrder( m + 2 * n , n ,   k );
    cout << m << ' ' << n << endl;
}

void inOrder( priority_queue& vals, int k )
{
    if( vals.front().first + vals.front().second >= k ) return;
    int m = vals.front().first;
    int n = vals.front().second;
    vals.pop();
    Entry add;
    add.first = ( 2 * m ) - n;
    add.second = m;
    vals.push(add);
    add.first = ( 2 * m ) + n;
    vals.push(add);
    add.first = m + ( 2 * n );
    add.second = n;
    vals.push(add);
    cout << m << ' ' << n << endl;
    inOrder( vals, k );
}

void sorted( int m , int n, int m1, int n1, int k )
{
    priority_queue vals;
    Entry example;
    example.first = m;
    example.second = n;
    vals.push( example );
    example.first = m1;
    example.second = n1;
    vals.push( example );
    inOrder(vals, k);
}

#endif
