/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void function1(int v,int &increment)
{
    while(increment<10)
    {
        increment++;
        cout<<"Thread"<<v <<" "<<increment;
    }
}

int main()
{
    int increment = 0;
    thread t1(function1,1,ref(increment));
    thread t2(function1,2,ref(increment));
    t1.join();
    t2.join();
    
    return 0;
}
