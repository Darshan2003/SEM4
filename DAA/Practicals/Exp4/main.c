#include<stdio.h>
#include<conio.h>
#include<string.h>


int findLongestCommonSubsequence(char str1[],char str2[],int len1, int len2)
{
    //creating a matrix of size +1 than length of strings
    int tab[len1+1][len2+1];

    //assigning first row and column as zeros
    for(int i=0;i<len1+1;i++)
    { 
        for(int j=0;j<len2+1;j++)
        {
            tab[i][j]=0;
        }
    }
    
 

    
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(str1[i]==str2[j])
            {
                tab[i+1][j+1] = tab[i][j] + 1;
            }
            else
            {
                if(tab[i][j+1]>tab[i+1][j])
                {
                    tab[i+1][j+1]=tab[i][j+1];
                }
                else{
                    tab[i+1][j+1]=tab[i+1][j];
                }
            }
        }
    }

    printf("      ");
    for(int i=0;i<len2;i++)
    {
        printf(" %c ",str2[i]);
    }
    printf("\n");
     for(int i=0;i<len1+1;i++)
    {
        if(i==0)
            printf("   ");
        else
            printf(" %c ",str1[i-1]);
        for(int j=0;j<len2+1;j++)
        {
            printf(" %d ",tab[i][j]);
        }
        printf("\n");
    }

//     int result = tab[len1][len2];
//     char ans[result+1];
//     ans[result] = '\0';
//     int temp = result-1;
//     int j = len1;
//     int i = len2;
//     while (i > 0 && j > 0) {  
//         if (str1[i] == str2[j]) {  
//         ans[temp] = str1[i];  
//         i--;  
//         j--;  
//         temp--;  
//         }  
//         else if (tab[i - 1][j] > tab[i][j - 1])  
//         i--;  
//         else  
//         j--;  
//   }  

  int index = tab[len1][len2];  
  char ans[index + 1];  
  ans[index] = '\0';  
  int i = len1, j = len2;  
  while (i > 0 && j > 0) {  
    if (str1[i - 1] == str2[j - 1]) {  
      ans[index - 1] = str1[i - 1];  
      i--;  
      j--;  
      index--;  
    }  
  
    else if (tab[i - 1][j] > tab[i][j - 1])  
      i--;  
    else  
      j--;  
  }  
    printf("\nOne of the Longest common subsequence is: %s",ans);
    return tab[len1][len2];
}

void main()
{
    char str1[100],str2[100];
    int len1=0,len2=0;

    printf("\nEnter String 1: ");
    scanf("%s",str1);

    printf("\nEnter String 2: ");
    scanf("%s",str2);

    //calculating length of the input string
    for(int i=0;str1[i]!='\0';i++)
    {
        len1++;
    }
    for(int i=0;str2[i]!='\0';i++)
    {
        len2++;
    }
    int result = findLongestCommonSubsequence(str1,str2,len1,len2);
    printf("\nLongest Common Subsequence is of length: %d",result);
}