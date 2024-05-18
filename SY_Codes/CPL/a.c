#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_valid_sequence(int n, int a[]) 
{
    bool diffs[n-1];
    for (int i = 0; i < n-1; i++) 
    {
        diffs[i] = false;
    }
    for (int i = 1; i < n; i++) 
    {
        int diff = abs(a[i] - a[i-1]);
        if (diff >= n) 
        {
            return false;
        }
        diffs[diff-1] = true;
    }
    for (int i = 0; i < n-1; i++) 
    {
        if (!diffs[i]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
        }
        if (is_valid_sequence(n, a)) 
        {
            printf("Accepted\n");
        } else 
        {
            printf("Rejected\n");
        }
    }
    return 0;
}