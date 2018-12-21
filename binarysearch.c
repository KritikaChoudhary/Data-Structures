#include<stdio.h>
typedef struct binaryt
{
    int data;
    struct binaryt* left;
    struct binaryt *right;
} node;
void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}
node *create(int data)
{
    //printf("\nEnter data(-1) for null:");
    //int x;
    //scanf("%d",&x);
    if(data==-1)
        return NULL;
    node *newnode=(node *)malloc(sizeof(node));
    newnode->left=newnode->right=NULL;
    newnode->data=data;
    return newnode;
}
//node *t;
node * insert(node *root,int data)
{
if(root==NULL)
{
    return create(data);
}
//node *temp=create();
//while(1)
//{
    if(data>root->data)//&&root->right!=NULL)
        root->right=insert(root->right,data);
    else if(data<root->data)//&&root->left!=NULL)
        root->left=insert(root->left,data);
//}
/*if(temp->data>=root->data)
    root->right=temp;
else if(temp->data<root->data)
    root->left=temp;
else*/
    return root ;
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
        case 1:printf("\nEnter the data(-1 for NULL):");
                int x;
                scanf("%d",&x);
            root=insert(root,x);
            break;
        case 2:preorder(root);
            break;
        case 3:inorder(root);
            break;
        case 4:postorder(root);
        }
    }
}

