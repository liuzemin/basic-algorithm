/*
 * No.1004: Let the Balloon Rise
 * Problem Description
 * Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.

 * This year, they decide to leave this lovely job to you. 
 

 * Input
 * Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.

 * A test case with N = 0 terminates the input and this test case is not to be processed.
 

 * Output
 * For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
 

 * Sample Input
 * 5
 * green
 * red
 * blue
 * red
 * red
 * 3
 * pink
 * orange
 * pink
 * 0
 
 * Sample Output
 * red
 * pink
 
 * Author
 * WU, Jiazhi
 
 * Source
 * ZJCPC2004
 */
#include<stdio.h> 
#include<string.h> 
int main() 
{ 
 int n,i,t,max,j,b[1000],k=0; 
 char a[1000][16]; 
 char c[1000][16];
 scanf("%d",&n);
 while(n!=0) 
 { k++;
   getchar(); 
   max=0; 
   for(i=0;i<n;i++) 
   { 
      gets(a[i]); 
      b[i]=1; 
   } 
    for(i=0;i<n;i++) 
      { 
        for(j=0;j<n;j++) 
          { 
             if(strcmp(a[i],a[j])==0) 
             b[i]++; 
           } 
      } 
    for(i=0;i<n;i++) 
    { 
        if(max<b[i]) 
        { 
          max=b[i]; 
          t=i; 
        } 
     } 
    
     strcpy(c[k], a[t]);
      scanf("%d",&n);
 } 


for(i=1;i<=k;i++)
{
   printf("%s\n",c[i]); 
}

} 
