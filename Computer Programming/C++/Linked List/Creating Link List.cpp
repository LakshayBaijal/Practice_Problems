#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};


int main()
{
    vector<int>arr = {1,3,2,6};
    Node y = Node(arr[3],nullptr);
    cout << y.data;
    

    Node* x = new Node(arr[2],nullptr);
    cout << x -> data;


    Node z = Node(arr[1]);
    cout << z.data;
    return 0;
}
