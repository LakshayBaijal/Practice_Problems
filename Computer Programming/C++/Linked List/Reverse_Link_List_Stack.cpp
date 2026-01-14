#include<bits/stdc++.h>
using namespace std;

struct Node {
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

Node* vectortolinklist(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        temp -> back = mover;
        mover -> next = temp;
        mover = temp;

    }
    return head;
}

void print(Node* x)
{
    Node* temp = x;
    while(temp != NULL)
    {
        cout<<temp->data;
        temp = temp -> next;
        
    }

    cout << endl;
    return;
}

Node* reverselinklist(Node* x)
{
    stack <int> st;

    Node* temp = x;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp = temp -> next;
    }

    Node* temp_again = x;
    while(temp_again!=NULL)
    {
        int n = st.top();
        st.pop();

        temp_again -> data = n;
        temp_again = temp_again -> next;
    }
    return x;
}

int main()
{
    vector<int>arr = {1,5,2,7,4};
    Node* x = vectortolinklist(arr);
    print(x);

    x = reverselinklist(x);
    print(x);
}
