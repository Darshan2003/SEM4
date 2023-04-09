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
   double insertion;
    
    FILE *fp,*ins_out;
    int upper_limit = 100;
    int arr1[upper_limit*100];
    printf("Insertion Sort\n");
    for (int i = 0; i < 100; i++)
    {
        fp = fopen("insertion.txt", "r");
        int  temp_num;
        for (int j = 0; j < upper_limit; j++)
        {
            fscanf(fp, "%d", &temp_num);
            arr1[j] = temp_num;
        }
        fclose(fp);

        clock_t t1;
        t1 = clock();
        insertion_sort(arr1,upper_limit);
        t1 = clock() - t1;
       
        insertion = ((double)t1) / CLOCKS_PER_SEC;
        printf("%lf\n", insertion);
        fflush(stdout);
        upper_limit += 100;
    }
}


