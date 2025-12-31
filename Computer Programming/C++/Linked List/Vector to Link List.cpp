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

Node* convertLinkList(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    
    Node* mover = head;

    for(int i = 1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover ->next = temp;
        mover = temp;
    }
    
    return head;
}

int main()
{
    vector<int> arr = {1,4,2,6};
    Node* x = convertLinkList(arr);

    Node* temp = x;

    while(temp)
    {
        cout << temp -> data;
        cout <<endl;
        temp = temp -> next;
    }

    return 0;
}
