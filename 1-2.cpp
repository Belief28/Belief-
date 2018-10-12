#include<bits/stdc++.h>
using namespace std;
struct node
{
    int date;
    struct node *next;
} *head, *p, *q, *t;
int main()
{
    int n, i;
    cin>>n;
    head=new(node);
    head -> next = NULL;
    for(i = 0; i < n; i++)
    {
        p=new(node);
        cin>>p->date;
        p->next=head->next;   //逆向建立链表
        head->next=p;
    }
    cout<<n<<endl;
    p=head->next;
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
            cout<<p->date<<" ";
        }
        else
        {
            cout<<p->date<<endl;
        }
       p=p->next;
    }
    q=new(node);
    p = head -> next;
    while(p&&p->next!=NULL)
    {
        q = p;
        t = q -> next;
        while(t != NULL)
        {
            if(t -> date == p -> date)
            {
                q->next=t->next;
                free(t);
                t=q->next;
                n--;
            }
            else
            {
                q=t;
                t=t->next;
            }
        }
        p=p->next;
    }
    cout<<n<<endl;
    p=head->next;
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
            cout<<p->date<<" ";
        }
        else
        {
            cout<<p->date<<endl;
        }
        p = p -> next;
    }
    return 0;
}
