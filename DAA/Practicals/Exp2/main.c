#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    i = 0;
    j = 0;

    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

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
    double qust,mest;
    srand(time(0));
    FILE *fp,*mer_out,*quick_out;
    fp = fopen("random.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        fprintf(fp, "%d\n", rand() % 100000);
    }
    int upper_limit = 100;
    int arr1[upper_limit*1000], arr2[upper_limit*1000];
    fclose(fp);
    printf("Merge Sort\tQuick Sort\n");
    for (int i = 0; i < 1000; i++)
    {
        fp = fopen("random.txt", "r");
        int temp_num;
        for (int j = 0; j < upper_limit; j++)
        {
            fscanf(fp, "%d", &temp_num);
            arr1[j] = temp_num;
            arr2[j] = temp_num;
        }
        fclose(fp);

        clock_t t;
        t = clock();
        mergeSort(arr2,0,upper_limit-1);
        t = clock() - t;
        
        mest = ((double)t) / CLOCKS_PER_SEC;
        clock_t t1;
        t1 = clock();
        quick(arr1,0,upper_limit-1);
        t1 = clock() - t1;
        
        qust = ((double)t1) / CLOCKS_PER_SEC;
        printf("%lf\t%lf\n", mest, qust);
        fflush(stdout);
        upper_limit += 100;
    }
    mer_out = fopen("merge.txt", "w");
    for (int i = 0; i < upper_limit-100; i++)
    {
        fprintf(fp, "%d\n", arr2[i]);
    }
    fclose(mer_out);

    quick_out = fopen("quick.txt", "w");
    for (int i = 0; i < upper_limit-100; i++)
    {
        fprintf(fp, "%d\n", arr1[i]);
    }
    fclose(mer_out);
}
