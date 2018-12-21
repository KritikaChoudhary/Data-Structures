#include<stdio.h>
#include<ctype.h>
typedef struct expt
{
    char data;
    struct expt *left;
    struct expt *right;
}node;
int top=-1;
node *stack[20],*newnode;
void push(node *leaf)
{
        stack[++top]=leaf;
}
node *pop()
{
    return stack[top--];
}
int cal(node *temp)
{
    if(isdigit(temp->data))
     return temp->data-'0';
        if(temp->data=='+') return cal(temp->left)+cal(temp->right);
        if(temp->data=='-') return cal(temp->left)-cal(temp->right);
        if(temp->data=='*') return cal(temp->left)*cal(temp->right);
        if(temp->data=='/') return cal(temp->left)/cal(temp->right);
    else
        return 0;
}
void operand(char a)
{
    newnode=(node *)malloc(sizeof(node));
    newnode->left=newnode->right=NULL;
    newnode->data=a;
    push(newnode);
}
void operate(char b)
{
    newnode=(node *)malloc(sizeof(node));
    newnode->data=b;
    newnode->right=pop();
    newnode->left=pop();
    push(newnode);
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%c->",root->data);
    inorder(root->right);
}
void main()
{
    char postfix[20];
    printf("Enter a postfix expression:");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
            operand(postfix[i]);
        else
            operate(postfix[i]);
    }
    int result=cal(stack[top]);
    printf("\nResult:%d",result);
    printf("\nInorder traversal:");
    inorder(stack[top]);
}

