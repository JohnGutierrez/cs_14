// John Gutierrez
// 861167274
// May 4, 2015
// used recursive functions for preOrder and postOrder, needed assistance with sorted function.

#include "lab4.h"

#include<vector>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;


int main(int argc, char * argv[] )
{
    if(argc != 2)
    {
        cout << "Usage: <end number>" << endl;
        exit(1);
    }
    int k = 0;
    
    for( unsigned int i = 0 ; i != strlen(argv[1]); ++i)
    {
        if( i + 1 < strlen(argv[1]))
        {
            cout << "check " << ((argv[1][i] - '0') * (pow(10, (strlen(argv[1]) - (i + 1))))) << endl;
            k = k + ((argv[1][i] - '0') * (pow(10, (strlen(argv[1]) - (i+1)))));
        }
        else
        {
            k = k + argv[1][i] - '0';
        }
    }
    
    cout << "testing with k value: " << k << endl << endl;
    cout << "preOrder: " << endl;
    preOrder(2, 1, k );
    preOrder(3, 1, k );
    cout << "postOrder: " << endl;
    postOrder(2, 1, k );
    postOrder(3, 1, k );
    cout << "sorted: " << endl;
    sorted (2, 1, 3, 1, k );
    return 0;
