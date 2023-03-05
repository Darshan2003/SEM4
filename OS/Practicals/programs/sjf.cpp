#include<iostream>
using namespace std;
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

//sorts the matrix based on arrival time using bubble sort
void arrangeArrival(int num, int mat[][5]) {
   for(int i=0; i<num; i++) {
      for(int j=0; j<num-i-1; j++) {
         if(mat[1][j] > mat[1][j+1]) {
            for(int k=0; k<5; k++) {
               swap(mat[k][j], mat[k][j+1]);
            }
         }
      }
   }
}


void completionTime(int num, int mat[][5]) {
   int temp, val;
   mat[3][0] = mat[1][0] + mat[2][0];
   mat[5][0] = mat[3][0] - mat[1][0];
   mat[4][0] = mat[5][0] - mat[2][0];
    for(int i=1; i<num; i++) {
      temp = mat[3][i-1];
      int low = mat[2][i];

      //finding the shortest job
      for(int j=i; j<num; j++) {
         if(temp >= mat[1][j] && low >= mat[2][j]) {
            low = mat[2][j];
            val = j;
         }
      }

      mat[3][val] = temp + mat[2][val];
      mat[5][val] = mat[3][val] - mat[1][val];
      mat[4][val] = mat[5][val] - mat[2][val];

      //swapping the position of the shortest job with current position
      for(int k=0; k<6; k++) {
         swap(mat[k][val], mat[k][i]);
      }
   }
}
int main() {
   int num, temp;
   double awt=0, atat=0,act=0;

   cout<<"\nEnter no. of patients: ";
   cin>>num;
   int mat[6][5];
   for(int i = 0;i<num;i++)
   {
      mat[0][i]=i+1;
      cout<<"\nEnter arrival time of patient-"<<i+1<<" : ";
      cin>>mat[1][i];
      cout<<"\nEnter Oxygen Required for time period by patient-"<<i+1<<" : ";
      cin>>mat[2][i];
   }
   
   cout<<"Before Scheduling\n";
   cout<<"PID\tArrival Time\tBurst Time\n";
   for(int i=0; i<num; i++) {
      cout<<mat[0][i]<<"\t\t"<<mat[1][i]<<"\t\t"<<mat[2][i]<<"\n";
   }
   arrangeArrival(num, mat);
   completionTime(num, mat);
   cout<<"After Scheduling\n";
   cout<<"PID\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n";
   for(int i=0; i<num; i++) {
      cout<<mat[0][i]<<"\t\t"<<mat[1][i]<<"\t\t"<<mat[2][i]<<"\t\t"<<mat[4][i]<<"\t\t"<<mat[3][i]<<"\t\t"<<mat[5][i]<<"\n";
      awt += mat[4][i];
      atat += mat[5][i];
      act += mat[3][i];
   }

  
   awt /= num;
   atat /= num;
   act /= num;

   cout<<"Average Waiting time: "<<awt<<endl;
   cout<<"Average Turnaround time: "<<atat<<endl;
   cout<<"Average Completion time: "<<act<<endl;

   if(mat[3][0]>0)
   {
      cout<<"|\t\t";
   }
   for(int i=0; i<num; i++) {
      cout<<"|\t"<<mat[0][i]<<"\t";
   }
   cout<<"|"<<endl;
   
   if(mat[3][0]>0)
   {
      cout<<"0\t\t";
   }
   for(int i=0; i<num; i++) {
      cout<<mat[1][i]+mat[4][i]<<"\t\t";
   }
   cout<<mat[3][num-1]<<endl;
}