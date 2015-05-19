//John Gutierrez
//861167274

#include <utility>
#include <typeinfo>
#include <iostream>
#include <iterator>

using namespace std;

template <typename t, typename x>
void display(pair<t,x> l)
{
    cout << '(' << l.first << ',' << l.second << ')' << ' ';
}

template <typename D>
void display(D l)
{
    cout <<l << ' ';
}

template <typename L>
void selectionsort(L &l)
{
    cout << "pre: ";
    for (auto temp = l.begin(); temp!=l.end(); ++temp)
    {
        display(*temp);
    }
    cout << endl;
    int swapCnt = 0;
    for(auto out = l.begin(); out!=l.end(); ++out)
    {
        auto lowest = out;
        for(auto curr=out; curr!= l.end(); ++curr)
        {
            if(*curr<*lowest)
            {
                lowest=curr;
            }
        }
        if(lowest !=out)
        {
            swapCnt++;
            swap(*lowest, *out);
        }
    }
    cout <<endl;
    cout << "0 copies and " << 3*swapCnt << "moves\n";
}