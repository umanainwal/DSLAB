#include<stdio.h>

int partition(int a[],int beg,int end)
{
    int key=a[end],temp;
    int i=beg-1,j;



    for(j=beg;j<end;j++)
    {
        if(a[j]<key)
        {
            i++;

            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }


    temp=a[i+1];
    a[i+1]=a[end];
    a[end]=temp;

    return i+1;

}

void quickSort(int a[],int beg,int end)
{
    int pi;

    if(beg<end)
    {
        pi=partition(a,beg,end);



        quickSort(a,beg,pi-1);

        quickSort(a,pi+1,end);


    }
}


void display(int a[],int size)
{
    int i;

    putchar('\n');

    for(i=0;i<size;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[50],i,size;

    printf("\nEnter number of elements to store ");
    scanf("%d",&size);

    printf("Enter %d elements ",size);

    for(i=0;i<size;i++)
    scanf("%d",&a[i]);

    quickSort(a,0,size-1);

    printf("\nThe sorted array is ");

    quickSort(a,0,size-1);

    display(a,size);



    return 0;
}