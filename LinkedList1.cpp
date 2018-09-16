#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    int data;
    node *next;
};
void revers(node **head)// for reverse linked list//
{
    node *prev=NULL,*next=NULL,*cur;
    cur=*head;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;

}
void me(node *head) //for finding middle element using two pointer method//
{
    node *fast,*slow;
    fast=head;
    slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=(fast->next)->next;
        slow=slow->next;
    }
    cout<<slow->data;
}
void nprin(node *head,int n)// for printing nth node from start//
{
    node *temp;
    temp=head;
    int c=0;
    while(c!=n-1)
    {
        temp=temp->next;
        c++;
    }
    cout<<temp->data;
}
void inser(node **head,int d)// for inserting node value at end//
{
    node *p,*temp;
    p=new node();
    p->data=d;
    p->next=NULL;
    if(*head==NULL)
        *head=p;
    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    }
}
void print(node *head)// for print list//
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<"->"<<temp->data;
        temp=temp->next;
    }
}
int main()          // main function//
{
    int choice,n;
    node *head=NULL;
    while(1)
    {
    cout<<"\n 1 for insert";
    cout<<"\n 2 for print";
    cout<<"\n 3 for printing nth node";
    cout<<"\n 4 for middle element";
    cout<<"\n 5 for reverse";
    cout<<"\n 6 for exit\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter Number\n";
        cin>>n;
        inser(&head,n);
        break;
    case 2:
        print(head);
        break;
    case 3:
        cout<<"enter the location \n";
        cin>>n;
        nprin(head,n);
        break;
    case 4:
        me(head);
        break;
    case 5:
        revers(&head);
        break;
    case 6:
        return(0);
    }
    }
}
