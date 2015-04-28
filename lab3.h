//John Gutierrez
//861167274
// tried to imagine the two stacks closing in on each other, with the
//tops of the stacks initially outside the array
#include <iostream>
using namespace std;
template <typename t>

class TwoStackFixed{
public:
    TwoStackFixed()
    :sz(NULL), maxtop(NULL), vals(0){}
    
    TwoStackFixed(int size, t maxtop)
    :sz(size), top1(vals-1), top2(vals+size), maxtop(&vals[maxtop]), vals(new t[size]){}
    
    ~TwoStackFixed(){
        delete[] vals;
    }
    
    void push_Stack1(t value){
        if(!isFullStack1()){
            top1++;
            *top1 = value;
            display();
            cout << endl;
        }
        else{
            cout << "Error: stack 1 is full." << endl;
            return;
        }
        return;
    }
    
    
    void push_Stack2(t value){
        if(!isFullStack2()){
            --top2;
            *top2= value;
            display();
            cout << endl;
        }
        else{
            cout << "Error: Stack 2 is full." << endl;
            return;
        }
        return;
    }
    
    bool isFullStack1(){
        if(top1 ==maxtop) return true;
        else return false;
    }
    
    bool isFullStack2(){
        if(top2-1 ==maxtop) return true;
        else return false;
    }
    
    bool isEmptyStack1(){
        if(top1==vals-1) return true;
        else return false;
    }
    bool isEmptyStack2(){
        if(top2==vals+sz) return true;
        else return false;
    }
    
    t popStack1(){
        assert(!isEmptyStack1());
        t temp1=*top1;
        --top1;
        return temp1;
    }
    
    t popStack2(){
        assert(!isEmptyStack2());
        t temp2= *top1;
        ++temp2;
        return temp2;
    }
    
    void display(){
        if(!isEmptyStack1()){
            for(auto temp= vals; temp!=top1+1; ++temp){
                cout << *temp << ' ';
            }
        }
        for(auto temp= top1+1; temp!= top2; ++temp){
            cout << '_';                    
        }
        if(!isEmptyStack2()){
            cout << *top2;
            for(auto temp= top1+1; temp!= top2; ++temp){
                cout<< *temp;
            }
        }
    }
private:
    int sz;
    t* top1;
    t* top2;
    t* maxtop;
    t* vals;
};


template <typename t2>
class TwoStackOptimal
{
public:
    TwoStackOptimal(int size)
    : vals(new t2[size]), sz(size), top1(vals-1), top2(vals+size){}
  
    ~TwoStackOptimal(){
        delete[] vals;
    }
    
    void pushFlexStack1(t2 value){
        if(!isFullStack1()){
            ++top1;
            *top1= value;
            display();
            cout << endl;
        }
        else{
            cout << "Error: Stack 1 is full\n";
            return;
        }
    }
    
    void pushFlexStack2(t2 value){
        if(!isFullStack2()){
            --top2;
            *top2= value;
            display();
            cout << endl;
        }
        else{
            cout << "Error: Stack 2 is full\n";
            return;
        }
    }
    
    t2 popFlexStack1(){
        assert(!isEmptyStack1());
        t2 temp1= *top1;
        --top1;
        return temp1;
    }
    
    t2 popFlexStack2(){
        assert(!isEmptyStack2());
        t2 temp2= *top2;
        --top2;
        return temp2;
    }
    
    bool isFullStack1(){
        return (top1+1==top2);
    }
    bool isFullStack2(){
        return (top2-1 == top1);
    }
    bool isEmptyStack1(){
        return (top1 == vals-1);
    }
    bool isEmptyStack2(){
        return (top2 == vals+sz);
    }
    
    void display(){
        if(!isEmptyStack1()){
            for( auto temp= vals; temp !=top1;  ++temp){
                cout << *temp << ' ';
            }
        }
        for( auto temp= top1+1; temp!= top2; ++temp){
            cout << "  ";
        }
        if(!isEmptyStack2()){
            cout << *top2;
            for( auto temp= top2+1; temp!= vals+sz; ++temp){
                cout << ' ' << *temp;
            }
        }
    }
    
private:
    t2* vals;
    t2* top1;
    t2* top2;
    int sz;
};
