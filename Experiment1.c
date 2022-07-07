#include<stdio.h>

void secondMinMax(int a[],int size)
{
    int min1,min2,max1,max2,i;

    if(size==1)
    {
        printf("\n1st greatest = %d ",a[0]);
        printf("\n2nd greatest = %d ",a[0]);
        printf("\n1st smallest = %d ",a[0]);
        printf("\n2nd smallest = %d ",a[0]);


    }


    else
    {
        if(a[0]<a[1])
        {
            min1=a[0];
            min2=a[1];
        }

        else
        {
            min1=a[1];
            min2=a[0];
        }

        if(a[0]>a[1])
        {
            max1=a[0];
            max2=a[1];
        }

        else
        {
            max1=a[1];
            max2=a[0];
        }


        for(i=2;i<size;i++)
        {
            if(a[i]<min1)
            {
                min2=min1;
                min1=a[i];
            }

            else if(a[i]<min2)
            {
                min2=a[i];
            }


            if(a[i]>max1)
            {
                max2=max1;
                max1=a[i];
            }

            else if(a[i]>max2)
            {
                max2=a[i];
            }


        }



        printf("\n1st greatest = %d ",max1);
        printf("\n2nd greatest = %d ",max2);
        printf("\n1st smallest = %d ",min1);
        printf("\n2nd smallest = %d ",min2);




    }


}

void display(int a[],int size)
{
    int i;

    putchar('\n');

    for(i=0;i<size;i++)
        printf("%d ",a[i]);

}


void insert(int a[],int* size)
{
    int i;
    int loc,item;

    printf("\nEnter item to insert ");
    scanf("%d",&item);

    printf("\nEnter location for insertion ");
    scanf("%d",&loc);

    for(i=*size-1;i>=loc-1;i--)
        a[i+1]=a[i];


    a[loc-1]=item;

    (*size)++;



}





void del(int a[],int *size)
{
    int i,loc;

    printf("\nEnter location for deletion ");
    scanf("%d",&loc);

    for(i=loc-1;i<*size-1;i++)
        a[i]=a[i+1];

    (*size)--;

}


void sort(int a[],int size)
{
    int i,j,temp;

    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int a[50],i,size,choice=1;

    printf("Enter number of elements to store ");
    scanf("%d",&size);

    printf("Enter %d elements ",size);

    for(i=0;i<size;i++)
        scanf("%d",&a[i]);

    while(choice)
    {
        printf("\n\n1 - Insert at a location\n2 - Delete from a location\n3 - Sort\n4 - \
Smallest and Greatest\n5 - Display\n0 - Exit");


        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insert(a,&size); break;
            case 2: del(a,&size); break;
            case 3: sort(a,size); break;
            case 4: secondMinMax(a,size); break;
            case 5: display(a,size); break;
            case 0: break;

            default : printf("\nInvalid choice ");
        }


    }


    return 0;
}
