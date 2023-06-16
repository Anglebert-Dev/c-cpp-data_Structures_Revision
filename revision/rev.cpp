#include<iostream>

using namespace std ; 
// union used to store different data types in the same memory location 
int main(){
    union  Data{
        /* data */
        int number;
        float average;
        char letter;
    };

    Data data;
    data.average =12.3;
    cout<< "hello world" <<endl;
    cout<<data.average ;  
}