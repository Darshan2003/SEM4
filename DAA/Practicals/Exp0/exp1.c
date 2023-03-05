#include <stdio.h>
#include<math.h>

void n_cube(long long int n)
{
    printf("\t\t%lld",n*n*n);
}


void factorial_n(long long int n)
{
    long long res = 1;
    for(int i = 1;i<=n;i++)
    {
        res *= i;
    }
    printf("\t\t%lld",res);
}

void exp_n(long long int n)
{
    printf("\t\t%.4f",exp(n));
}


void n(long long int n)
{
    printf("\t\t%lld",n);
}


void two_power_of_n(long long int n)
{
    printf("\t\t%.2f",pow(2,n));
}

void root_log_of_n(int n)
{
    printf("\t\t%.5f",sqrt(log2(n)));
}

void log_of_n(int n)
{
    printf("\t\t%.4f",log2(n));
}

void n_log_n(int n)
{
    printf("\t\t%.4f",n*log2(n));
}

void two_power_log_of_n(int n)
{
    printf("\t\t%.4f",pow(2,log2(n)));
}


void log_of_n_power_log_of_n(int n)
{
    printf("\t\t%.4f",pow(log2(n),log2(n)));
}

void n_2_power_n(int n)
{
    printf("\t\t%.2f",n*pow(2,n));
}

void power_of_two_power_n(long long int n)
{
    printf("\t\t%.2f",pow(2,pow(2,n)));
}

int main()
{
   
   
    printf(" N\t\tn^3\t\tlog2n\t\t2^log2n\t\tn*2^n\t\tn*log2n\t\tsqrt(log2n)\t\tn\t\te^n\t\tlog2n^log2n\n");
    for(long long int i = 0;i<=100;i++)
    {
        printf(" %lld",i);
        n_cube(i);
        log_of_n(i);
        two_power_log_of_n(i);
        n_2_power_n(i);
        two_power_of_n(i);
        n_log_n(i);
        root_log_of_n(i);
        n(i);
        exp_n(i);
        log_of_n_power_log_of_n(i);
        printf("\n");
    }
   
    for(int i=0;i<=20;i++)
    {
     
       factorial_n(i);
       printf("\n");
    }
   

    return 0;
}