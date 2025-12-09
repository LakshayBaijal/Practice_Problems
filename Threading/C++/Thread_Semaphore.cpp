/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
#include <thread>
#include <semaphore.h>

using namespace std;
sem_t s1,s2;

void function1()
{
    sem_wait(&s1);
    
    cout<<"thread 1";
    sem_post(&s2);
    return;
}

void function2()
{
    sem_wait(&s2);
    cout<<"thread 2";
    sem_post(&s1);
    
    return;
}

int main()
{
    int counter = 0;
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    
    thread t1(function1);
    thread t2(function2);
    
    t1.join();
    t2.join();
    
    return 0;
    
}
