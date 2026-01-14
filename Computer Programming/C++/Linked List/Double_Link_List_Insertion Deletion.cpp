#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1)
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


Node* vectortodoublelinklist(vector<int>&arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i = 1;i<arr.size();i++)
    {
        Node *temp = new Node(arr[i]);
        mover -> next = temp;
        temp -> back = mover;
        mover = temp;
    }

    return head;
}





void print(Node* x)
{
    while(x != NULL)
    {
        cout << x->data;
        x = x->next;
    }
    cout<<endl;

}

Node* doublelinklist_delete_head(Node* x)
{
    if(x == NULL || x -> next == NULL)
    {
        return NULL;
    }

    Node* prev = x;
    x = x -> next;

    prev -> next = nullptr;
    x -> back = nullptr;

    delete prev;

    return x;
}

Node* doublelinklist_delete_tail(Node* x)
{
    if(x == NULL || x -> next == NULL)
    {
        return NULL;
    }

    Node* tail = x;
    while(tail->next != NULL)
    {
        tail = tail -> next;
    }

    Node* prev = tail -> back;
    tail->back = nullptr;
    prev -> next = nullptr;

    delete(tail);
    return x;
}

Node* doublelinklist_delete_ele(Node* x,int k)
{
    if(x == NULL)
    {
        return NULL;
    }
    int count = 0;
    
    Node* current = x;
    while(current!=NULL)
    {
        count++;
        if(count == k)
        {
            break;
        }
        current = current -> next;
    }

    Node* prev = current -> back;
    Node* front = current -> next;

    if(prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if(prev == NULL)
    {
        return doublelinklist_delete_head(x);
    }
    else if(front == NULL)
    {
        return doublelinklist_delete_tail(x);
    }

    prev -> next = front;
    front -> back = prev;
    
    current -> next = nullptr;
    current -> back = nullptr;
    delete(current);
    return x;
}

Node* doublelinklist_insert_head(Node* x,int ele)
{
    Node* newhead = new Node(ele,x,nullptr);
    
    x -> back = newhead;
    return newhead;

}

Node* doublelinklist_insert_tail(Node* x,int ele)
{
    Node* tail = x;

    while(tail->next != NULL)
    {
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* addtail = new Node(ele,tail,prev);

    prev -> next = addtail;
    tail -> back = addtail;
    return x;

}



int main()
{
    vector<int>arr = {1,3,6,3,7,5,3,7};

    Node* x = vectortodoublelinklist(arr);

    print(x);
    
    x = doublelinklist_delete_head(x);
    print(x);

    x = doublelinklist_delete_tail(x);
    print(x);

    int k = 2;
    x = doublelinklist_delete_ele(x,k);
    print(x);

    x = doublelinklist_insert_head(x,5);
    print(x);

    x = doublelinklist_insert_tail(x,1);
    print(x);
    return 0;
}
