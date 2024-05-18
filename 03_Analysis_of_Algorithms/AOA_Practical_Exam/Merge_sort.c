#include <stdlib.h>
#include <stdio.h>



void merge(int a[],int n)
{
    int beg,end;
    beg = 0;
    end = n - 1;
    



}
void merge_sort()
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

    merge_sort(a,n);

    printf("Elements after sorting: \n");
    print_arr(a,n);



    return 0;
}