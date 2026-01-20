#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }

};
Node* oddeven(Node*head)
{
    Node*odd=head;
    Node*even=odd->next;
    Node*evenhead=even;

    while(even!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    
    return head;
}
int main()
{
    Node*head=new Node(1);
    Node* temp1=new Node(2);
    Node*temp2=new Node(3);
    Node* temp3=new Node(4);
    Node* temp4=new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
     
    oddeven(head);
    Node*curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    return 0;
}
