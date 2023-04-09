#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quicksort(int a[], int start, int end)
{
    int pivot = a[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return (i + 1);
}

double quick(int a[], int start, int end)
{
    if (start < end)
    {
        int p = quicksort(a, start, end);
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}


void main()
{
    double qust;
    FILE *fp,*quick_out;
    
    int upper_limit = 100;
    int arr1[upper_limit*100];
    
    printf("Quick Sort\n");
    for (int i = 0; i < 100; i++)
    {
        fp = fopen("quick.txt", "r");
        int temp_num;
        for (int j = 0; j < upper_limit; j++)
        {
            fscanf(fp, "%d", &temp_num);
            arr1[j] = temp_num;
        }
        fclose(fp);

        clock_t t1;
        t1 = clock();
        quick(arr1,0,upper_limit-1);
        t1 = clock() - t1;
        
        qust = ((double)t1) / CLOCKS_PER_SEC;
        printf("%lf\n", qust);
        fflush(stdout);
        upper_limit += 100;
    }
}
