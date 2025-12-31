#include<bits/stdc++.h>

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

Node convertlinklist(vector<int>&arr)
{
    Node head = Node(arr[0]);
    Node mover = head;

    for(auto it : arr)
    {
        Node Temp = Node(it);
        mover.next = Temp;
        mover = Temp;
    }
    return head;
}

int main()
{
    vector<int>arr = {1,3,5,7};
    Node head = convertlinklist(arr);
    cout << head.data;
    return 0;
}
