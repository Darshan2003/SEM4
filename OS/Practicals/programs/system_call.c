#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;

    j = 0;

    k = l;
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

    while (i < n1) {
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


void quickSort(int number[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quickSort(number,first,j-1);
      quickSort(number,j+1,last);
   }
}

void printArray(int arr[],int size)
{
    printf("\nContents in array:");
    for(int i=0;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }
}

void main()
{
    int arr[100],size;
    printf("\nEnter Size of array:");
    scanf("%d",&size);

    printf("\nEnter Elements of array:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    // for(int i=0;i<size;i++)
    // {
    //     child_arr[i] = parent_arr[i];
    // }
    printf("\nArray before sorting: ");
    printArray(arr,size);
    pid_t p;
    p=fork();

    //if 0 means it is a child process
    if(p==0)
    {
        printf("\nIn Child Process\n");
        quickSort(arr,0,size-1);
        printf("\nArray after Quick Sort");
        printArray(arr,size);
    }
    //if p is not 0 then it is parent process
    else if(p>0){
        wait(NULL);
        printf("\nIn Parent Process\n");
        mergeSort(arr,0,size-1);
        printf("\nArray after Merge Sort");
        printArray(arr,size);
    }
    else
    {
        printf("\nChild process not created!");
    }

}