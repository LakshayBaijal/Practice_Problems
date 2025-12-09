#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void function1(int v,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<"Thread "<<v<<" "<<i << endl;
    }
}

int main()
{
    thread t1(function1,1,10);
    thread t2(function1,2,10);
    t1.join();
    t2.join();
    
    return 0;
}



/*
[?2004l
Thread 2 0
Thread 2 1
Thread 2 2
Thread 2 3
Thread 2 4
Thread 2 5
Thread 2 6
Thread 2 7
Thread 2 8
Thread 2 9
Thread 1 0
Thread 1 1
Thread 1 2
Thread 1 3
Thread 1 4
Thread 1 5
Thread 1 6
Thread 1 7
Thread 1 8
Thread 1 9
*/
