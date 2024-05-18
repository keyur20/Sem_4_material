#include <stdlib.h>
#include <stdio.h>

//for creating max heapify
void max_heapify(int a[],int n,int i)
{
    int left,right,largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    
    if(left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if(right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a , n , largest);
    }
    

}

void heap_sort(int a[], int n)
{
    //build max heap
    int i,temp;
    for ( i = n/2 - 1; i >= 0; i--)
    {
        max_heapify(a,n,i);
    }
    //delete element from max heap
    for( i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        max_heapify(a,i,0);
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
    int n,i;
    printf("Enter the number of elements :");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements before sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } 
    printf("\n");
    
    heap_sort(a,n);

    printf("Elements after sorting: \n");
    print_arr(a,n);
    
    

    return 0;
}
