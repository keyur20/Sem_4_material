#include<stdlib.h>
#include<stdio.h>
void insertion_sort(int a[], int n)
{
    int j, temp,i;
    for ( i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >=0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;             
    }
}

void print_arr(int a[],int n)
{

    printf("Elements after sorting: ");

    int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

}

int main()
{
    int n,i;
    
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: \n");
    for(i = 0; i < n-1; i++)
    {
        scanf("%d ", &a[i]);
    }
    printf("\n");
    printf("Elements before sorting: ");
    for(i = 0 ;i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    insertion_sort(a, n);
    print_arr(a, n);

   
    return 0;

}
/*
#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int j, temp, i;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

void print_arr(int a[], int n)
{
    printf("Elements after sorting: ");

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");

    printf("Elements before sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    insertion_sort(a, n);
    print_arr(a, n);

    return 0;
}
*/