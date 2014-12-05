/*
 * No.1005: Number Sequence
 * Problem Description
 * A number sequence is defined as follows:

 * f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

 * Given A, B, and n, you are to calculate the value of f(n).
 

 * Input
 * The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
 

 * Output
 * For each test case, print the value of f(n) on a single line.
 

 * Sample Input
 * 1 1 3
 * 1 2 10
 * 0 0 0
 

 * Sample Output
 * 2
 * 5
 

 * Author
 * CHEN, Shunbao
 

 * Source
 * ZJCPC2004
 */
 
#include<stdio.h>
int main()
{
    int f[1000]={0},n,i,a,b;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
        f[0]=1;
        f[1]=1;
        if(a==0&&b==0&&n==0)
            break;
        for(i=2;i<(n%49);i++)
        {
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        }
        printf("%d\n",f[n%49-1]);
    }
    return 0;
}
