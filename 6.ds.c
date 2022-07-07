#include<stdio.h>
#include<malloc.h>

struct node
{
    int info;
    struct node* next;
}*front=NULL,*rear=NULL;

void addAtFront(int item)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->info=item;
    p->next=NULL;

    if(front==NULL)
        front=rear=p;

    else
    {
        p->next=front;
        front=p;
    }
}

void addAtRear(int item)
{

    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->info=item;
    p->next=NULL;


    if(front==NULL)
        front=rear=p;

    else
    {
        rear->next=p;
        rear=p;
    }
}

int removeFromFront()
{
    struct node* p=front;
     int item;

    if(front==NULL)
        return -1;

    front=front->next;

    item=p->info;
    free(p);

    printf("\n%d was removed from front ",item);
    return item;
}


int removeFromRear()
{
    struct node* p=front;
    int item;

    if(front==NULL)
        return -1;

    while(p->next!=rear)
    p=p->next;


    p->next=NULL;


     item=rear->info;
        free(rear);
        rear=p;

    printf("\n%d was removed from rear ",item);
    return item;
}

void display()
{
    struct node* p;
    printf("\n");


    for(p=front;p!=NULL;p=p->next)
        printf("%d ",p->info);
}


int main()
{
    int choice,item;

    do
    {
        printf("\n\n1 - Add at Front\n2 - Add at Rear\n3 - Delete from Front\n4 - Delete from Rear\n5 - Display\
\n0 - Exit ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter item to add ");
                    scanf("%d",&item);
                    addAtFront(item);
                    break;
            case 2: printf("\nEnter item to add ");
                    scanf("%d",&item);
                    addAtRear(item);
                    break;

            case 3: removeFromFront();
                    break;
            case 4: removeFromRear();
                    break;
            case 5: display();
        }

    }
    while(choice);

    return 0;
}
