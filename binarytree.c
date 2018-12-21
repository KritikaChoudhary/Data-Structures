#include<stdio.h>
typedef struct binaryt
{
    int data;
    struct binaryt* left;
    struct binaryt *right;
} node;
node *t;
void preorder(node *r)
{
    node *ro=r;
    if(ro==NULL)
    {
        return;
    }
    printf("%d->",ro->data);
    preorder(ro->left);
    preorder(ro->right);
}
void inorder(node *r)
{
    node *ro=r;
    if(ro==NULL)
    {
        return;
    }
    inorder(ro->left);
    printf("%d->",ro->data);
    inorder(ro->right);
}
void postorder(node *r)
{
    node *ro=r;
    if(ro==NULL)
    {
        return;
    }
    postorder(ro->left);
    postorder(ro->right);
    printf("%d->",ro->data);
}
node *create()
{
    printf("\nEnter data(-1 for null):");
    int data;
    scanf("%d",&data);
    if(data==-1)
        return NULL;
    node *newnode=(node *)malloc(sizeof(node));
    newnode->left=newnode->right=NULL;
    newnode->data=data;
        return newnode;
}
node * insert(node *root)
{
    if(root==NULL)
    {
        root=create();
        t=root;
    }
    printf("\nLeft branch of %d\n",root->data);
    root->left=create();
    printf("\nRight branch of %d\n",root->data);
    root->right=create();
    if(root->left!=NULL)
        insert(root->left);
    if(root->right!=NULL)
        insert(root->right);
    else
        return t;
}
void main()
{
    node *root=NULL;
    int ch;
    printf("1.Insert\n2.Pre\n3.in\n4.post\n5.exit");
    while(ch!=5)
    {
        printf("\nEnter ch:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:root=insert(root);
            break;
        case 2:preorder(root);
            break;
        case 3:inorder(root);
            break;
        case 4:postorder(root);
        }
    }
}
