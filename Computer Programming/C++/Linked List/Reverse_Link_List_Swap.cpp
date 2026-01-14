#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


Node* vectortoarr(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        temp -> back = mover;
        mover = temp;
    }

    return head;
}

void print(Node* x)
{
    Node* temp = x;

    while(temp != NULL)
    {
        cout << temp ->data;
        temp = temp -> next;
    }
    cout << endl;
}

Node* reverse_link_list(Node* x)
{
    Node* mover = x;
    Node* temp = NULL;
    while(mover != NULL)
    {
        temp = mover -> back;
        mover -> back = mover -> next;
        mover -> next = temp;

        mover = mover -> back;
    }
    return temp -> back;
}

int main()
{
    vector<int> arr = {1,4,2,6,4,7};
    Node* x = vectortoarr(arr);
    print(x);

    x = reverse_link_list(x);
    print(x);
    return 0;
}
