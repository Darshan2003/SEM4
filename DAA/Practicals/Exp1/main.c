#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<limits.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
  

void insertion_sort(int arr[],int n)
{
    int i,key,j;
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}


void main()
{
   double selection,insertion;
    srand(time(0));
    FILE *fp,*ins_out,*sel_out;
    fp = fopen("random.txt", "w");
    for (int i = 0; i < 10000; i++)
    {
        fprintf(fp, "%d\n", rand() % 10000);
    }
    int upper_limit = 100;
    int arr1[upper_limit*100], arr2[upper_limit*100];
    fclose(fp);
    printf("Selection Sort\tInsertion Sort\n");
    for (int i = 0; i < 100; i++)
    {
        fp = fopen("random.txt", "r");
        int  temp_num;
        for (int j = 0; j < upper_limit; j++)
        {
            fscanf(fp, "%d", &temp_num);
            arr1[j] = temp_num;
            arr2[j] = temp_num;
        }
        fclose(fp);

        clock_t t;
        t = clock();
        selection_sort(arr2,upper_limit);
        t = clock() - t;
        
      
        selection = ((double)t) / CLOCKS_PER_SEC;
        clock_t t1;
        t1 = clock();
        insertion_sort(arr1,upper_limit);
        t1 = clock() - t1;
       
        insertion = ((double)t1) / CLOCKS_PER_SEC;
        printf("%lf\t%lf\n", selection, insertion);
        fflush(stdout);
        upper_limit += 100;
    }

    ins_out = fopen("insertion.txt", "w");
    for (int x = 0; x < upper_limit-100; x++)
    {
        fprintf(ins_out, "%d\n", arr1[x]);
    }
    fclose(ins_out);
    sel_out = fopen("selection.txt", "w");
    for (int x = 0; x < upper_limit-100; x++)
    {
        fprintf(sel_out, "%d\n", arr2[x]);
    }
    fclose(sel_out);
}


