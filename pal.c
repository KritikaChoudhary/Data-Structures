#include<stdio.h>
typedef struct pal
{
    char data;
    struct pal *prev;
    struct pal *next;
}node;
node *create()
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->prev=newnode->next=NULL;
    printf("\nEnter character:");
    scanf(" %c",&newnode->data);
    return newnode;
}
void insert(node *head,node* tail)
{
    node *temp=create();
    if(head==NULL)
        head=tail=temp;
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void p(node *t1,node *t2)
{
    if(t1==t2)
    {
        return ;
    }
    else if(t1->data!=t2->data)
    {
        printf("\nNot palindrome");
        exit(0);
    }
    else
        p(t1->next,t2->prev);
}
void disp(node *head,node *tail)
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%c",temp->data);
        temp=temp->next;
    }
}
void main()
{
    node *head=NULL;
    node *tail=NULL;
    int c;
    while(c!=-1)
    {
        insert(head,tail);
        printf("\nEnter 1 to continue(-1 to exit):");
        scanf("%d",&c);
    }
    disp(head,tail);
    p(head,tail);
    printf("\nPalindrome");
}
