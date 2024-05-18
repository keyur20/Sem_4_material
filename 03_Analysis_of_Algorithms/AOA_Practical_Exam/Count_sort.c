#include <stdlib.h>
#include <stdio.h>

int get_max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }

    }
    return max;
}
void count_sort(int a[],int n)
{

    int max = get_max(a,n);
    int count[max +1];

    // intialize all elements in count array to zero
     for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // store the count of elements of original array in count array
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    //counting cumulative frequency in count array
    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    int output[n+1];
    for (int i = n - 1; i >= 0; i--)
    {

        output[count[a[i]-1]] = a[i];
        count[a[i]]--;
    }
    //store sorted elements in main array

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
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

    count_sort(a,n);

    printf("Elements after sorting: \n");
    print_arr(a,n);



    return 0;
}
