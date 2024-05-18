#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int start,int end)
{
    int pivot=a[end];
    int i = start -1;

    for (int j = start; j <= end - 1; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            int t =a[i];
            a[i]=a[j];
            a[j]=t;
        }

    }
    int t = a[i+1];
    a[i+1] = a[end];
    a[end] = t;
    
    return(i+1);
}

void quick_sort(int a[],int start,int end)
{
    if(start < end)
    {
        int p = partition(a,start,end);
        quick_sort(a,start,p-1);
        quick_sort(a,p+1,end);


    }
}

void print_arr(int a[], int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

}
int main()
{
    int n;
    printf("Enter the number of elements :");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements before sorting: \n");
    print_arr(a,n);
    printf("\n");

    quick_sort(a,0,n-1);

    printf("Elements after sorting: \n");
    print_arr(a,n);



    return 0;
}