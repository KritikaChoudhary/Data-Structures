#include<stdio.h>
#define size 5
int q1[size];
int q2[size];
int q3[size];
int front=-1; int rear=-1;
void lq()
{

    printf("1.Nq\n2.Dq\n3.Search\n4.Sort\n5.Disp\n6.exit");
    int ch;
    do
    {
        printf("\nEnter:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Enter the element:");
                int e;
                scanf("%d",&e);
                lnq(e);
                break;
        case 2:if(ldq()==-1)
                printf("Empty q");
                else
                printf("\nDeleted element:%d",ldq());
                break;
        case 3:printf("Enter the element to be searched for:");
                int e1;
                scanf("%d",&e1);
                if(search(e1,q1)==-1)
                    printf("%d not present",e1);
                else
                    printf("%d at %d",e,search(e1,q1));
                break;
        case 4:s(q1);
                break;
        case 5:ldisp();
        }
    }while(ch!=6);
}
void lnq(int val)
{
    if(rear==size-1)
        printf("q full");
    else
    {
        if(front==-1)
            front=0;
        q1[++rear]=val;
        ldisp();
    }
}
int ldq()
{
    if(front==-1)
        return -1;
    else
    {
        int e=q1[front];
        front=front+1;
        ldisp();
        if(front==rear+1)
            front=rear=-1;
        return e;
    }
}
void ldisp()
{
    if(front==-1)
        printf("Empty queue");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d\t",q1[i]);
    }
}
void s(int q[])
{
    if(front==-1)
        printf("Empty queue");
    else
    {
        for(int i=front;i<=rear;i++)
        {
            for(int j=i+1;j<=rear;j++)
            {
                if(q[i]>q[j])
                {
                    int temp=q[i];
                    q[i]=q[j];
                    q[j]=temp;
                }
            }
            printf("%d\t",q[i]);
        }
    }
}
int search(int e,int q[])
{
    for(int i=front;i<=rear;++i)
    {
        if(q[i]==e)
        return i;
    }
    return -1;
}
void cq()
{
    int front=-1; int rear=-1;
    printf("1.Nq\n2.Dq\n3.Search\n4.Sort\n5.Disp\n6.exit");
    int ch;
    do
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("\nEnter the element:");
                int e;
                scanf("%d",&e);
                cnq(e);
                break;
        case 2:cdq();

                break;
        case 3:printf("Enter the element to be searched for:");
                int e1;
                scanf("%d",&e1);
                if(search(e1,q2)==-1)
                    printf("%d not present",e1);
                else
                    printf("%d at %d",e1,search(e1,q2));
                break;
        case 4:s(q2);
                break;
        case 5:cdisp();
        }
    }while(ch!=6);
}
void cnq(int val)
{
    if((front==0&&rear==size-1)||(front==rear+1))
        printf("q full");
    else
    {
        if(front==-1)
            front=0;
        q2[++rear]=val;
        cdisp();
        if(rear==size-1)
            rear=-1;

    }
}
int cdq()
{
   if(front==-1&&rear==-1)
    printf("Empty q");
   else
   {
       int e=q2[front];
       front=front+1;
       printf("\nDeleted element:%d",e);
       if(front==rear+1)
        front=rear=-1;
        if(front==size)
        front=-1;
   }
}
void cdisp()
{
    if(front==-1&&rear==-1)
        printf("Empty q");
    else
    {
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
                printf("%d\t",q2[i]);
        }
        else
        {
            for(int i=rear;i<front;i++)
               printf("%d\t",q2[i]);
        }
    }
}
void pq()
{
    int front=-1; int rear=-1;
    printf("1.Nq\n2.Dq\n3.Search\n4.Sort\n5.Disp\n6.exit");
    int ch;
    do
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1:printf("Enter the element:");
                int e;
                scanf("%d",&e);
                pnq(e);
                break;
        case 2:pdq();
                break;
        case 3:printf("Enter the element to be searched for:");
                int e1;
                scanf("%d",&e1);
                if(search(e1,q3)==-1)
                    printf("%d not present",e1);
                else
                    printf("%d at %d",e1,search(e1,q3));
                break;
        case 4:s(q3);
                break;
        case 5:pdisp();
        }
    }while(ch!=6);
}
void pnq(int val)
{
    if(rear==size-1)
        printf("Q full");
    else
    {
        int i;
            if(front ==-1)
            front=0;
            if(rear==-1)
                q3[++rear]=val;
            else
            {
                for(i=rear;i>=front;i--)
                {
                    if(val>q3[i])
                    {
                        q3[i+1]=q3[i];
                    }
                    else
                        break;
                }
                q3[++i]=val;
                rear++;
                pdisp();
            }
    }
}
void pdq()
{
    if(front==-1)
         printf("Empty q");
    else
    {
        int e=q3[front];
        front=front+1;
        printf("\nDeleted element:%d",e);
        if(front==rear+1)
            front=rear=-1;
    }
}
void pdisp()
{
    if(front==-1)
        printf("Q empty");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d\t",q3[i]);
    }
}
void main()
{

    int ch;
    do
    {
         printf("1.Linear q\n2.Circular\n3.Priority\n4.exit");
        printf("\nEnter:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:lq();
                break;
            case 2:cq();
                break;
            case 3:pq();
        }
    }while(ch!=4);
}
