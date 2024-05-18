#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void radix_sort(int a[],int n)
{

    
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

    radix_sort(a,n);

    printf("Elements after sorting: \n");
    print_arr(a,n);



    return 0;
}