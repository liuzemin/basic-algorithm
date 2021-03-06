/*
 * No.1012: u Calculate e
 * Problem Description
 * A simple mathematical formula for e is



 * where n is allowed to go to infinity. This can actually yield very accurate approximations of e using relatively small values of n.
 

 * Output
 * Output the approximations of e generated by the above formula for the values of n from 0 to 9. The beginning of your output should appear similar to that shown below.
 

 * Sample Output
 * n e
 * - -----------
 * 0 1
 * 1 2
 * 2 2.5
 * 3 2.666666667
 * 4 2.708333333
 

 * Source
 * Greater New York 2000

 */


#include<stdio.h>
int main()
 {double result = 2.5;
    double arr[10] = {1};
    int i = 1,j = 3;
    while(i < 10)
     {
         arr[i] = i * arr[i - 1];
         i++;
     }
     printf("n e\n");
     printf("- -----------\n");
     printf("0 1\n");
     printf("1 2\n");
     printf("2 2.5\n");
     
     while(j < 10)
     {
         result = result + 1/arr[j];
         printf("%d %11.9f\n",j,result);
         j++;
     }
 } 
