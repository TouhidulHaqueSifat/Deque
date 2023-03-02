#include<bits/stdc++.h>
using namespace std;
class node
{
public:

    int data;
    node* nxt;
    node* prv;
};
class Deque
{
public:
    node* head;
    node* tail;
    int sz;
    Deque()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }

    node* CreateNewNode(int value)
    {
        node* newnode=new node;
        newnode->data=value;
        newnode->nxt=NULL;
        newnode->prv=NULL;
        return newnode;
    }
    void push_back(int value)
    {
        node* a=CreateNewNode(value);
        if(sz==0)
        {
            head=a;
            tail=a;
            sz++;
            return;
        }
        tail->nxt=a;
        a->prv=tail;
        tail=a;
        sz++;

    }
    void push_front(int value)
    {
        node* a=CreateNewNode(value);
        if(sz==0)
        {
            head=a;
            tail=a;
            sz++;
            return;
        }
        head->prv=a;
        a->nxt=head;
        head=a;
        sz++;
    }
    void pop_back()
    {
        if(sz==0)
        {
            return;
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node* a=tail;
        tail=a->prv;
        a->nxt=NULL;
        sz--;
        delete a;
    }
    void pop_front()
    {
        if(sz==0)
        {
            return;
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node* a=head;
        head=a->nxt;
        a->prv=NULL;
        sz--;
        delete a;
    }
    int front()
    {
        if(sz==0)
        {
            return -1;
        }
        return head->data;
    }
    int back()
    {
        if(sz==0)
        {
            return -1;
        }
        return tail->data;
    }
    int size()
    {
        return sz;
    }

};
int main()
{
    Deque d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(5);
    cout<<"Deque Sizez: "<<d.size()<<"\n";

    cout<<d.front()<<"\n";
    d.pop_front();

    cout<<d.front()<<"\n";
    d.pop_front();

    cout<<d.front()<<"\n";
    d.pop_front();

    cout<<d.front()<<"\n";
    d.pop_back();

    cout<<d.back()<<"\n";
    d.pop_back();
    cout<<"Deque size: "<<d.size()<<"\n";



    return 0;
}
